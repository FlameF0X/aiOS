; kernel_entry.asm - Minimal entry point for aiOS kernel
BITS 32
SECTION .text
global _start
extern kernel_main

_start:
    call kernel_main
    cli
    hlt
