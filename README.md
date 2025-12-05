# Operating Systems: Introductory Course with a Linux Focus

*For details regarding this module's **assessment** please see: [Assessment](https://github.com/vmarkos-mc/operating-systems/tree/main/Assessment)*

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
| `Week 02 - Files, Filters, Pipes` | Introduce filters, files, pipes and how to play with them in Linux. |
| `Week 03 - Processes` | Discuss about processes, system processes in particular, and play along from terminal. |
| `Week 04 - Users And Rights` | User and group structure in Linux. |
| `Week 05 - Bash Revision` | A quick revision on Bash. |
| `Week 06 - Introduction To C` | Introduction to elementary C concepts, and Linux System Calls. |
| `Week 07 - Memory Management in C` | Pointers, arrays, and other C cool stuff... |
| `Week 08 - Introduction To IPC` | Introduction to Inter-process Communication. |
| `Week 09 - Shared Memory and Message Queues` | Examples on sharing data usign shared memory segments and message queues. |
| `Week 10 - Concurrency` | Introduction to concurrency at an OS level. |
| `Week 11 - Semaphores and Sockets` | Introduction to Semaphores and UDP Sockets. |
| `Week 12 - Revision` | All-inclusive revision quiz! |
| `LICENSE` | The MIT License for this project. |

## Getting Started

To work with the material in this course, a Linux/Unix environment is strongly recommended, as many examples and assignments will rely on POSIX-compliant behavior and tools.

### Prerequisites

* **Linux/Unix Environment:** (e.g., Ubuntu, macOS, or Windows Subsystem for Linux (WSL)).
* **C Compiler:** Such as GCC, for working with system programming examples.
* **Basic Shell Knowledge:** Familiarity with bash or zsh is helpful for the first week.

### Running the Code

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/vmarkos-mc/operating-systems.git
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
