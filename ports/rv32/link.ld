 OUTPUT_ARCH( "riscv" )
 ENTRY( _start )
 SECTIONS
 {
 /* text: test code section */
 . = 0x40200000;
 .text :
 {
    *(.text)
 }

 /* data: Initialized data segment */
 .data :
 {
    *(.data)
    *(.rodata)
 }
 /* End of uninitalized data segement */

 .bss :
 {
    __bss_start = .;
     *(.bss .bss.*)
 	 *(.sbss .sbss.*)
    __bss_end = .;
 }

 _end = .;
 /* SDRAM HEAP */
 /* VRAM 0x40000000 - */
 /* HEAP 0x40100000 - */
 /* APP  0x40200000 - */
 end = 0x40300000;
 }
