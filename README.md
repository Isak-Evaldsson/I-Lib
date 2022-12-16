# I-Lib
I-Lib (or Isak-Lib) a little library implementing commonly used data structures or helper functions. Sort like my own libc extension.

## Contents
The library contains the following, for more details/documentation see the code/header files

### Data structures
* **vector_t** - resizable array, allowing you to push to it, index it and iterate over it
* **list_t** - general purpose list, with fast push/pop allowing it work like a queue, exposes internal structure to the user, allowing fast iteration using do while
* **set_t** - has set data structure

## Usage
The makefile currently builds a static library that can be compiled into your code projects, since this library won't be widely distributed this simplifies the usage compared to dynamic linking

## TODO
This library will dynamically grow as needed. However some features are in the todo list:
* Set: add support for deletion
* Add HashMap
* Add Binary search trees?
