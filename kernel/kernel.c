// aiOS Minimal Kernel (kernel.c)
// Prints a message to the screen (VGA text mode)

void kernel_main() {
    char* video_memory = (char*)0xb8000;
    const char* message = "aiOS Kernel: Hello, world!";
    for (int i = 0; message[i] != '\0'; ++i) {
        video_memory[i * 2] = message[i];
        video_memory[i * 2 + 1] = 0x07; // Light grey on black
    }
    while (1) {}
}
