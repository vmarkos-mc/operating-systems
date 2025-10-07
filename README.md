# Operating Systems: Introductory Course with a Linux Focus

This repository contains the materials for an introductory course on **Operating Systems**. The course balances core concepts of OS theory (processes, memory management, file systems) with practical examples and assignments focused heavily on the **Linux/Unix environment**.

The goal is to provide a solid foundation in how operating systems function, complemented by hands-on experience using system calls, shell scripting, and basic concurrency programming.

## Table of Contents

* [Overview](#-operating-systems-introductory-course-with-a-linux-focus)
* [Repository Structure](#repository-structure)
* [Getting Started](#getting-started)
* [Contributing](#contributing)
* [License](#license)

## Repository Structure

The course is divided into weekly modules, each containing lecture notes (often as PDFs or Markdown files) and accompanying code examples or lab assignments (likely in C or Python).

| Folder | Description |
| :--- | :--- |
| `Week 01 - Introduction` | Covers the definition and history of Operating Systems, system structures, and an introduction to the Unix/Linux environment and shell. |
| `LICENSE` | The MIT License for this project. |
| ... | *More weekly modules will cover Processes, Threads, CPU Scheduling, Deadlocks, Memory Management, and File Systems.* |

## Getting Started

To work with the material in this course, a Linux/Unix environment is strongly recommended, as many examples and assignments will rely on POSIX-compliant behavior and tools.

### Prerequisites

* **Linux/Unix Environment:** (e.g., Ubuntu, macOS, or Windows Subsystem for Linux (WSL)).
* **C Compiler:** Such as GCC, for working with system programming examples.
* **Basic Shell Knowledge:** Familiarity with bash or zsh is helpful for the first week.

### Running the Code

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/vmarkos-mc/operating-systems.git](https://github.com/vmarkos-mc/operating-systems.git)
    cd operating-systems
    ```

2.  **Executing C Examples (System Calls):**
    Navigate to the relevant week, compile the source, and run the executable:
    ```bash
    cd Week\ 01\ -\ Introduction
    gcc -o example example_syscall.c
    ./example
    ```

3.  **Executing Shell Scripts:**
    Scripts are executed directly in the terminal:
    ```bash
    ./Week\ 01\ -\ Introduction/script.sh
    ```

## Contributing

We encourage contributions! If you find a better way to illustrate a concept, optimize an example, or fix an error in the documentation, please submit a pull request.

1.  **Fork** the repository.
2.  **Create** your feature branch (`git checkout -b feature/better-scheduler-example`).
3.  **Commit** your changes (`git commit -m 'Added a clearer example for CPU scheduling'`).
4.  **Push** to the branch (`git push origin feature/better-scheduler-example`).
5.  **Open a Pull Request**.

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
