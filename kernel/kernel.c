// aiOS Minimal Kernel (kernel.c)
// Prints a message to the screen (VGA text mode)

void kernel_main() {
    volatile char* video = (volatile char*)0xb8000;
    const char* msg = "aiOS Kernel: Hello from the kernel!";
    for (int i = 0; msg[i] != 0; ++i) {
        video[i * 2] = msg[i];
        video[i * 2 + 1] = 0x0F; // White on black
    }
    while (1) {}
}
