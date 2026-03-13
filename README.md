# 🐚 MyShell — Interactive Linux Shell in C

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" />
  <img src="https://img.shields.io/badge/Platform-Linux-orange?style=for-the-badge&logo=linux" />
  <img src="https://img.shields.io/badge/Build-Makefile-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge" />
</p>

> A lightweight Linux shell built in C — replicating core Bash features using low-level POSIX system calls like `fork()`, `execvp()`, `pipe()`, and `dup2()`.

---

## 📌 Table of Contents
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Future Improvements](#future-improvements)
- [Author](#author)

---

<a id="features"></a>
## ✨ Features

- 🖥️ Colored prompt with username and current directory
- 🔧 Built-in commands: `cd`, `exit`, `history`, `clear`
- 🚀 Execute any external Linux program
- 🔗 Pipe support — `ls | wc -l`
- 📥 Input / 📤 Output redirection — `<` and `>`
- 🌀 Background process execution — `sleep 5 &`
- 📜 Command history tracking

---

<a id="tech-stack"></a>
## 🛠️ Tech Stack

| Category | Details |
|---|---|
| **Language** | C  |
| **OS / Platform** | Linux (Ubuntu) |
| **API Standard** | POSIX — Portable Operating System Interface |
| **Build Tool** | GNU Make (`Makefile`) |
| **Compiler** | GCC — GNU Compiler Collection |
| **IPC Mechanism** | Unix Pipes (`pipe()` + `dup2()`) |
| **Process Model** | Fork-Exec pattern (`fork()` + `execvp()`) |
| **I/O** | File descriptors, stdin/stdout/stderr redirection |

---

<a id="project-structure"></a>
## 📁 Project Structure

```
myshell/
├── main.c          # Shell entry point and main loop
├── parser.c        # Command parsing and tokenization
├── execute.c       # External command execution
├── builtins.c      # Built-in command implementations
├── pipes.c         # Pipe handling
├── redirection.c   # I/O redirection
├── history.c       # Command history
├── shell.h         # Shared header and declarations
└── Makefile        # Build configuration
```

---

<a id="getting-started"></a>
## 🚀 Getting Started

**Prerequisites:** `gcc` and `make` on any Linux distro.

```bash
# Clone and build
git clone https://github.com/yourusername/myshell.git
cd myshell
make

# Run
./myshell

# Clean build files
make clean
```

---

<a id="usage"></a>
## 💡 Usage

```bash
myshell> ls                  # list files
myshell> cd Documents        # change directory
myshell> ls | wc -l          # pipe commands
myshell> ls > files.txt      # output redirection
myshell> wc -w < files.txt   # input redirection
myshell> sleep 5 &           # background process
myshell> history             # show command history
myshell> exit                # quit the shell
```

---

<a id="how-it-works"></a>
## 🔍 How It Works

MyShell follows the classic shell loop:

```
Read input → Parse tokens → Built-in? → Execute directly
                                ↓ No
                           fork() → execvp() → wait()
```

| System Call | Role |
|---|---|
| `fork()` | Create a child process |
| `execvp()` | Run the command in the child |
| `pipe()` | Connect stdout of one process to stdin of another |
| `dup2()` | Rewire file descriptors for redirection |
| `wait()` | Wait for child to finish (skipped for `&`) |
| `chdir()` | Change directory (used by `cd` built-in) |

---

<a id="future-improvements"></a>
## 🛠️ Future Improvements

- [ ] Signal handling (`Ctrl+C`, `Ctrl+Z`)
- [ ] Tab completion
- [ ] Environment variable support (`$VAR`, `export`)
- [ ] Command aliases
- [ ] Job control (`fg`, `bg`, `jobs`)
- [ ] Multi-pipe chaining (`cmd1 | cmd2 | cmd3`)

---

<a id="author"></a>
## 👨‍💻 Author

**Jitin Kumar** — B.Tech CSE (AI Specialization)

[![GitHub](https://img.shields.io/badge/GitHub-Jitin2102-black?style=flat-square&logo=github)](https://github.com/Jitin2102)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Jitin%20Kumar-blue?style=flat-square&logo=linkedin)](https://linkedin.com/in/Jitin2102)

---

<p align="center">Built with ❤️ and lots of <code>fork()</code> calls.</p>
