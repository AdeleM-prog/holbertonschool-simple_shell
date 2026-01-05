# [**Simple Shell**](https://github.com/AdeleM-prog/holbertonschool-simple_shell)

## 🧠 Description

**Simple Shell** is a minimalist command-line interpreter written in C, inspired by the UNIX `sh` shell.
It can execute both built-in and external commands using a classic read–parse–execute loop.

---

## ⚙️ Features

| Feature | Status |
|---------|--------|
| Built-in `exit` & `env` | ✅ Implemented |
| PATH resolution | ✅ Implemented |
| Fork/execve execution | ✅ Implemented |
| Memory leak prevention | ✅ Implemented |
| Non-interactive mode | ✅ Implemented |
| Error handling | ✅ Basic |

---

## 🧩 Directory Structure

| File | Description |
|------|-------------|
| `shell.h` | Header file with includes and prototypes |
| `shell.c` | Main loop and command handling |
| `parsing.c` | Input parsing logic |
| `pathing.c` | PATH resolution |
| `executing.c` | Fork and execve execution |
| `README.md` | Project documentation |

---

## 🔧 Compilation

Compile the project with:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
---

## ▶️ Usage

Interactive mode
```bash
./hsh
$ ls -l
$ echo Hello World
$ env
$ exit
```
Non-interactive mode
```bash
echo "ls" | ./hsh
```
---

## 🔍 Internal Workflow

Prompt: Display $ and wait for user input.

Read: Capture the input line using getline().

Parse: Split input into tokens using strtok().

Built-in check:

If exit: free memory and quit.

If env: print environment variables and continue.

PATH resolution: Search for executables in directories listed in PATH.

Execute:

Create a new process with fork().

The child executes using execve().

The parent waits for termination with wait().

Loop: Repeat until the user exits or EOF is reached.

---

## 💡 Built-in Commands

Command	Description
`exit`	Exit the shell
`env`	Display environment variables

---

## 🧹 Memory Management

Frees dynamically allocated memory after every command.

Proper cleanup on exit or end-of-file.

Prevents memory leaks caused by token duplication or getline buffer reuse.

---

## 🧭 Flowchart

<img width="519" height="1251" alt="Diagramme sans nom drawio" src="https://github.com/user-attachments/assets/7d40c1cc-25b3-4a96-98cb-e3355970cb7a" />

---

## 👨‍💻 Authors

[**Adèle**](https://github.com/AdeleM-prog) & [**Antoine**](https://github.com/add1ktion)
