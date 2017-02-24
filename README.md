# redpill
My implementation of Joanna Rutkowska's "Redpill"

## Retrieved Values


### Non-Virtualized 8 Core Linux Kernel 4.9.11

| IDT Limit	| IDT Base		| GDT Limit	| GDT Base		| LDTR	|
|---------------|-----------------------|---------------|-----------------------|-------|
| 4095		| 0xffffffffff57c000	| 127		| 0xffff88042fa09000	| 0	|
| 4095		| 0xffffffffff57c000	| 127		| 0xffff88042fa49000	| 0	|
| 4095		| 0xffffffffff57c000	| 127		| 0xffff88042fa89000	| 0	|
| 4095		| 0xffffffffff57c000	| 127		| 0xffff88042fac9000	| 0	|
| 4095		| 0xffffffffff57c000	| 127		| 0xffff88042fb09000	| 0	|
| 4095		| 0xffffffffff57c000	| 127		| 0xffff88042fb49000	| 0	|
| 4095		| 0xffffffffff57c000	| 127		| 0xffff88042fb89000	| 0	|
| 4095		| 0xffffffffff57c000	| 127		| 0xffff88042fbc9000	| 0	|

### Virtualbox 1 Core Linux Kernel 4.4.0

| IDT Limit	| IDT Base		| GDT Limit	| GDT Base		| LDTR	|
|---------------|-----------------------|---------------|-----------------------|-------|
| 4095		| 0xffffffffff574000	| 127		| 0xffff88011fc09000	| 0	|

### VMWare Player 12 1 Core Linux Kernel 4.4.0

| IDT Limit	| IDT Base		| GDT Limit	| GDT Base		| LDTR	|
|---------------|-----------------------|---------------|-----------------------|-------|
| 4095		| 0xffffffffff574000	| 127		| 0xffff88003c609000	| 0	|
