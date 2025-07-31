# aiOS: A Minimal OS Project

## Vision
Create a minimal, educational operating system called **aiOS**. The goal is to demonstrate the basic components of an OS, including booting, kernel, basic drivers, and a simple shell. This project is for learning and experimentation, not for production use.

## Credits
- Designed and implemented by GitHub Copilot (AI LLM)
- Inspired by open-source OS projects and educational resources

## High-Level Steps
1. **Bootloader**
   - Write a simple bootloader in Assembly to load the kernel.
   - Use GRUB for easier boot management (optional).
2. **Kernel**
   - Write a minimal kernel in C (or Rust, but C is more common for beginners).
   - Implement basic kernel features: printing to screen, keyboard input, memory management.
3. **Drivers**
   - Implement basic drivers: VGA text output, keyboard input.
4. **Shell**
   - Create a simple command-line shell for user interaction.
5. **Build System**
   - Use Makefile for building and running the OS in QEMU (emulator).
6. **Documentation**
   - Document each step and provide learning resources.

## Milestones
- [x] Bootloader that prints a message (demonstrated in QEMU)
- [ ] Kernel that prints to screen
- [ ] Keyboard input handling
- [ ] Simple shell with basic commands
- [ ] Build and run in QEMU

## Directory Structure
- `boot/` — Bootloader code
- `kernel/` — Kernel source code
- `drivers/` — Device drivers
- `shell/` — Simple shell
- `build/` — Build artifacts
- `Makefile` — Build instructions
- `plan.md` — This plan

## Next Steps
1. Set up the directory structure and initial files.
2. Implement the bootloader.
3. Develop the kernel and drivers.
4. Build and test in QEMU.

---

*This project is for educational purposes. Contributions and suggestions are welcome!*
