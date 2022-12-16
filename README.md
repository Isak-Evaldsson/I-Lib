# I-Lib
I-Lib (or Isak-Lib) a litle library implementing commonly used data structures or helper functions. Sort like my own libc extension.

## Contents
The library contains the following, for more details/documentation see the code/header files

### Data structures
* **vector_t** - resizable array, allowing you to push to it, index it and iterate over it
* **list_t** - general purpose list, with fast push/pop allowing it work like a queue, exposes interal structure to the user, allowing fast iteration using do while

## Usage
The makefile currently builds a static library that can be compiled into your code projects, since this library won't be widely distributed this simples the usage compared to dynamic linking

## TODO
This library will dynamically grow as needed. However some features are in the todo list:
* Move the hash set implementation from into this library + re-writing it to a hash map
* Binary search trees?
