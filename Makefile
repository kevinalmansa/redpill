##
## Makefile for redpill in /home/kevin/Projects/redpill
## 
## Made by Kevin Almansa <kevinalmansa>
## Email   kevin.almansa@gmail.com
## 
## Started on  Fri Feb 24 16:09:57 2017 kevinalmansa
## Last update Fri Feb 24 16:10:37 2017 kevinalmansa
##

CC	=	gcc
RM	=	rm -vf
NAME	=	redpill
SRC	=	src/descriptor_tables.c
OBJ	=	$(SRC:.c=.o)
CFLAGS	=	
LDFLAGS	=	

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
