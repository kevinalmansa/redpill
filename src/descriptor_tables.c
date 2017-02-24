/*
** descriptor_tables.c for redpill in /home/kevin/Projects/redpill/src
** 
** Made by Kevin Almansa <kevinalmansa>
** Email   kevin.almansa@gmail.com
** 
** Started on  Fri Feb 24 11:01:58 2017 kevinalmansa
** Last update Fri Feb 24 16:09:43 2017 kevinalmansa
*/

#include <inttypes.h>
#include <stdio.h>

/*
** WARNING: This has only been tested on a 64 bit machine.
** I do NOT own a 32 bit machine.
*/

/*
** SIDT, SGDT, SLDT
** limit: always 16 bits (2 bytes)
** address: 32 bits or 64 bits (depending on architecture)
**    -> void* for this reason
** Anything other than an array of chars will cause the struct to no longer be
** 10 bytes (limit + address) due to automatic alignment resulting in undefined
** behaviour
*/
struct desc_table
{
  uint16_t	limit;
  void		*base;
} __attribute__((packed));

struct desc_table		get_idtr()
{
  struct desc_table		idtr = {0, 0};
  
  __asm__ __volatile__("sidt  %0" : "=m"(idtr));
  return idtr;
}

struct desc_table		get_gdtr()
{
  struct desc_table		gdtr = {0, 0};

  __asm__ __volatile__("sgdt  %0" : "=m"(gdtr));
  return gdtr;
}

uint16_t			get_ldt_seg_selector()
{
  uint16_t			ldt_seg_selector;

  __asm__ __volatile__("sldt %0" : "=m"(ldt_seg_selector));
  return ldt_seg_selector;
}

/*
** Linux Non-Virtualized
**  IDTR:
**   limit: 4095
**   base: 0xffffffffff57c000
**
**  GDTR:
**   limit: 127
**   base: (one per processor)
**	   0xffff88042fa09000
**	   0xffff88042fa49000
**         0xffff88042fa89000
**	   0xffff88042fac9000
**
**	   0xffff88042fb09000
**	   0xffff88042fb49000
**	   0xffff88042fb89000
**	   0xffff88042fbc9000
**
**  LDTR:
**   seg_selector: 0
*/
int				main()
{
  struct desc_table	idtr;
  struct desc_table	gdtr;
  uint16_t			ldt_seg_selector;

  idtr = get_idtr();
  gdtr = get_gdtr();
  ldt_seg_selector = get_ldt_seg_selector();
  
  printf("IDTR:\n limit: %u\n base: %p\n", idtr.limit, idtr.base);
  printf("GDTR:\n limit: %u\n base: %p\n", gdtr.limit, gdtr.base);
  printf("LDTR:\n seg_selector: %u\n", ldt_seg_selector);
  return 0;
}
