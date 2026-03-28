# stickit

A lightweight terminal based sticky note board written in C++.

Create, view, pin, and manage post-it style notes directly from the terminal, with persistent storage across sessions.

---

## Overview
`stickit` is a simple CLI application that simulates sticky notes on a monitor, but in your terminal.

It is designed as a learning project to build foundations in C++, focusing on:
- data structures (`std::vector`, `std::string`)
- file I/O
- program structure and modular design
- basic user interaction in the terminal

---
## Features
- Create post-it notes
- View all notes in a board layout
- View individual notes
- Pin/unpin notes
- Delete Notes
- Persistent storage (save + load from file)

## Commands
### Add
```Bash
stickit add --title="Reminder" --message="Buy milk" --color=yellow
```

### Edit
```Bash
stickit edit --id=4 --title="Urgent reminder"
stickit edit --id=4 --message="Buy milk and eggs"
stickit edit --id=4 --color=red
```

### List
```Bash
stickit list
stickit list --pinned
```

### Delete
```Bash
stickit delete --id=4
```

### Pin/Unpin
```Bash
stickit pin --id=4
stickit unpin --id=4
```

### File Override
```Bash
stickit add --title="X" --message="Y" --color=green --file=custom.txt
```

---
## Example
```
===== POST-IT Board =====
[1] [PINNED][yellow]
COMP2017 - Finish worksheet

[2][blue]
Buy stuff - Ethernet cable

[3][green]
Ideas - Burger
========================
```
