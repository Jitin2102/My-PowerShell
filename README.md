# 🐚 MyShell — Interactive Linux Shell in C

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" />
  <img src="https://img.shields.io/badge/Platform-Linux-orange?style=for-the-badge&logo=linux" />
  <img src="https://img.shields.io/badge/Standard-POSIX-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Build-Makefile-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge" />
</p>

> A lightweight Unix-like command-line shell implemented in C that replicates the core functionality of traditional Linux shells such as Bash — built to deeply understand how operating systems manage processes, execute programs, and handle inter-process communication.

---

## 📌 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Project Structure](#-project-structure)
- [Technologies Used](#-technologies-used)
- [System Calls Used](#-key-system-calls)
- [Installation & Setup](#-installation--setup)
- [Example Usage](#-example-usage)
- [How It Works](#-how-it-works)
- [Built-in Commands](#-built-in-commands)
- [Learning Outcomes](#-learning-outcomes)
- [Future Improvements](#-future-improvements)
- [Author](#-author)

---

## 🧭 Overview

**MyShell** is a fully functional interactive shell written in C as part of a Linux System Programming learning exercise. It mimics the internal behavior of standard Unix shells by leveraging low-level POSIX system calls to manage process creation, program execution, piping, and I/O redirection — all from scratch.

This project was designed to answer a fundamental question:

> *"What actually happens under the hood when you type a command into a terminal?"*

---

## ✨ Features

| Feature | Description |
|---|---|
| 🖥️ **Interactive Prompt** | Colored prompt showing username and current working directory |
| 🔧 **Built-in Commands** | `cd`, `exit`, `history`, `clear` |
| 🚀 **External Program Execution** | Run any Linux binary available on `$PATH` |
| 📜 **Command History** | Track and display previously entered commands |
| 🔗 **Pipe Support** | Chain commands using the `\|` operator |
| 📥 **Input Redirection** | Redirect file contents as stdin using `<` |
| 📤 **Output Redirection** | Redirect stdout to a file using `>` |
| 🌀 **Background Execution** | Run processes in the background using `&` |

---

## 📁 Project Structure

```
myshell/
│
├── main.c            # Shell entry point and main command loop
├── parser.c          # Command parsing and tokenization
├── execute.c         # External command execution logic
├── builtins.c        # Built-in shell command implementations
├── pipes.c           # Pipe implementation between processes
├── redirection.c     # Input/output redirection handling
├── history.c         # Command history tracking and display
├── shell.h           # Shared header file and function declarations
├── Makefile          # Build configuration
├── README.md         # Project documentation
└── .gitignore        # Git ignore rules
```

---

## 🛠️ Technologies Used

- **C Programming Language** — Core implementation language
- **Linux System Programming** — Direct use of OS-level interfaces
- **POSIX Standard** — Portable Operating System Interface compliance
- **Process Management** — Creating and managing child processes
- **File Descriptors** — Low-level I/O and file descriptor manipulation
- **Inter-Process Communication (IPC)** — Pipes for process communication
- **Makefile** — Automated build system

---

## ⚙️ Key System Calls

| System Call | Purpose |
|---|---|
| `fork()` | Create a child process |
| `execvp()` | Execute an external program in a child process |
| `pipe()` | Create a unidirectional data channel between processes |
| `dup2()` | Redirect file descriptors for I/O manipulation |
| `wait()` / `waitpid()` | Wait for child process termination |
| `chdir()` | Change the current working directory |
| `getpid()` / `getppid()` | Retrieve process identifiers |

---

## 📦 Installation & Setup

### Prerequisites

Make sure you have the following installed on your Linux system:

- `gcc` (GNU Compiler Collection)
- `make`
- A Linux-based OS (Ubuntu, Debian, Fedora, Arch, etc.)

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/myshell.git
cd myshell
```

### 2. Compile the Project

```bash
make
```

This will compile all source files and produce the `myshell` executable.

### 3. Run the Shell

```bash
./myshell
```

You will be greeted with a colored prompt:

```
[jitin@hostname ~/myshell]$
```

### 4. Clean Build Artifacts

```bash
make clean
```

---

## 💡 Example Usage

```bash
# List files in current directory
myshell> ls

# Print working directory
myshell> pwd

# Change directory
myshell> cd Documents

# Run a command in the background
myshell> sleep 5 &

# Pipe: list files and count lines
myshell> ls | wc -l

# Output redirection: save ls output to a file
myshell> ls > files.txt

# Input redirection: count words in a file
myshell> wc -w < files.txt

# View command history
myshell> history

# Clear the terminal
myshell> clear

# Exit the shell
myshell> exit
```

---

## 🔍 How It Works

MyShell follows the classic **Read → Evaluate → Execute** loop used by all Unix shells:

```
┌─────────────────────────────────────────────┐
│             MyShell Main Loop               │
│                                             │
│  1. Display prompt (user@host:cwd$)         │
│  2. Read user input                         │
│  3. Parse input into tokens                 │
│  4. Check for built-in commands             │
│       └─ If found → execute directly        │
│  5. fork() → create a child process         │
│  6. execvp() → run external command         │
│  7. Handle pipes ( | ) and redirections     │
│  8. wait() for child (unless background &)  │
│  9. Return to step 1                        │
└─────────────────────────────────────────────┘
```

### Process Execution Flow

```
Parent Process (myshell)
        │
        ├── fork() ──────────────────────────────────────┐
        │                                                 │
        │  (parent)                            (child process)
        │  wait() / waitpid()                  execvp(command, args)
        │       │                                    │
        │  resumes after                     runs external binary
        │  child exits                       (e.g., /bin/ls)
        └───────────────────────────────────────────────-┘
```

### Pipe Implementation

```
Command: ls | wc -l

  Process A (ls)          Process B (wc -l)
       │                        │
  stdout ──→  [pipe fd]  ──→  stdin
```

---

## 🧩 Built-in Commands

These commands are handled directly by MyShell without spawning a child process:

| Command | Usage | Description |
|---|---|---|
| `cd` | `cd <directory>` | Change the current working directory |
| `exit` | `exit` | Terminate the shell session |
| `history` | `history` | Display list of previously entered commands |
| `clear` | `clear` | Clear the terminal screen |

> Built-in commands must be handled internally because they need to modify the shell's own process state (e.g., `cd` changes the CWD of the shell process itself, not a child).

---

## 🎓 Learning Outcomes

Through building MyShell, the following Linux system programming concepts were implemented and deeply understood:

- ✅ **Process Creation** — How `fork()` creates exact copies of the parent process
- ✅ **Program Execution** — How `exec()` family replaces a process image with a new program
- ✅ **Inter-Process Communication** — How `pipe()` enables data flow between processes
- ✅ **File Descriptor Manipulation** — How `dup2()` rewires stdin/stdout at the OS level
- ✅ **Command Parsing** — Tokenizing user input into command + argument arrays
- ✅ **Background Processing** — How `&` defers `wait()` to allow concurrent execution
- ✅ **Built-in vs External Commands** — Knowing which commands must run in-process vs subprocess
- ✅ **Linux Shell Internals** — The complete lifecycle of a shell from prompt to execution

---

## 🚀 Future Improvements

Planned enhancements and possible extensions:

- [ ] **Signal Handling** — Support `Ctrl+C` (SIGINT) and `Ctrl+Z` (SIGTSTP) gracefully
- [ ] **Tab Completion** — Auto-complete commands and file paths
- [ ] **Environment Variables** — Support `$VAR` expansion and `export` / `unset`
- [ ] **Command Aliases** — Define shorthand aliases for frequently used commands
- [ ] **Job Control** — Implement `fg`, `bg`, and `jobs` for managing background processes
- [ ] **Multi-Pipe Chaining** — Support chains like `cmd1 | cmd2 | cmd3 | cmd4`
- [ ] **Scripting Mode** — Execute `.sh` script files passed as arguments
- [ ] **Here-Documents** — Support `<<` heredoc syntax
- [ ] **Readline Integration** — Add arrow-key history navigation and line editing

---

## 👨‍💻 Author

**Jitin Kumar**
B.Tech Computer Science Engineering (AI Specialization)

<p>
  <a href="https://github.com/Jitin2102">
    <img src="https://img.shields.io/badge/GitHub-Jitin2102-black?style=flat-square&logo=github" />
  </a>
  <a href="https://linkedin.com/in/Jitin2102">
    <img src="https://img.shields.io/badge/LinkedIn-Jitin%20Kumar-blue?style=flat-square&logo=linkedin" />
  </a>
</p>

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).  
Feel free to fork, modify, and use it for your own learning. ⭐ Star the repo if you found it helpful!

---

<p align="center">
  Built with ❤️ and lots of <code>fork()</code> calls.
</p>
