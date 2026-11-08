# week5-github

## Todo App

This a terminal based todo app made entirely in C, you can see your todos, create new ones, delete existing ones etc.

### Files

- todo-app.c
- tasks.c
- tasks.h

### Usage

#### Compile

You need a C compiler such as [GCC](https://gcc.gnu.org/). From the project folder, run:

```bash
gcc -Wall -o todo todo-app.c tasks.c
```

This compiles `todo-app.c` and `tasks.c` together into one program called `todo`. The `-Wall` flag turns on compiler warnings, and `-o todo` sets the name of the output file.

#### Run

```bash
./todo
```

The program shows a menu. Type a number and press Enter:

- `1`: see your tasks
- `2`: create a new task
- `3`: end the program

### Author

Made by [Rubin Imeri](https://github.com/rubinimeri)
