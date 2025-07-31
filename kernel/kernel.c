// aiOS Minimal Kernel (kernel.c)
// Minimal CLI shell: print prompt, read keypresses, echo input, repeat

// Print a string to VGA text mode
void print(const char* str, int* col) {
    volatile char* video = (volatile char*)0xb8000;
    while (*str) {
        video[(*col) * 2] = *str;
        video[(*col) * 2 + 1] = 0x0F;
        (*col)++;
        str++;
    }
}

// Read a character from keyboard using BIOS interrupt 0x16
char getch() {
    char c;
    __asm__ __volatile__ (
        "mov $0x00, %%ah\n\t"
        "int $0x16\n\t"
        "mov %%al, %0\n\t"
        : "=r"(c)
        :
        : "ax"
    );
    return c;
}

void kernel_main() {
    int col = 0;
    print("aiOS CLI Shell> ", &col);
    while (1) {
        char c = getch();
        if (c == '\r') {
            print("\n\raiOS CLI Shell> ", &col);
        } else {
            char s[2] = {c, 0};
            print(s, &col);
        }
    }
}
