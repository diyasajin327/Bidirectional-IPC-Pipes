# Bidirectional Inter-Process Communication Using Pipes
## Description
This project demonstrates communication between parent and child processes using pipes in C (Unix/Linux).

## Technologies Used
* C Programming
* Linux / Unix
* GCC Compiler

## How It Works
* Two pipes are created
* Parent sends message to child
* Child replies back to parent
* Simulates a simple chat system

## How to Run
```bash
gcc ipc_chat.c -o ipc
./ipc
```

## Sample Output
Parent: Enter message for child: Hello
Child received: Hello
Child: Enter reply to parent: Hi
Parent received: Hi

## Concepts Covered
* pipe()
* fork()
* read()
* write()
* Inter-Process Communication (IPC)
