# get_next_line
## Description
This project is designed to read a line from a file descriptor. It provides a function, get_next_line(), which reads one line from a file descriptor each time it's called. The project includes additional helper functions located in the get_next_line_utils.c file to assist in the implementation of get_next_line().

## Usage
1. Clone this repository:
```
git clone <repository_url>
```

2. Include the necessary files in your project. You'll need at least ``get_next_line.c``, ``get_next_line_utils.c``, and ``get_next_line.h``.

3. Compile your project along with the get_next_line files. For example:
```
gcc -o my_program main.c get_next_line.c get_next_line_utils.c
```

## Bonus: Handling Multiple File Descriptors
### Description

The bonus part of this project extends the functionality of ***get_next_line()*** to manage multiple file descriptors simultaneously. This means you can call ``get_next_line()`` to read from one file descriptor, then another, and so on, without losing the reading thread of each file descriptor or returning a line from another file descriptor.

For example, you can:
1. Call ``get_next_line()`` to read from file descriptor 3.
2. Call ``get_next_line()`` to read from file descriptor 4.
3. Call ``get_next_line()`` to read from file descriptor 5.
4. Repeat the above steps for any number of file descriptors.

## Contributing
Contributions are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.
