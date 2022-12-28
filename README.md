# shitpostlib
shitpost utilities written in C

## introduction
Basically, a tool for shitposter to generate content quickly.

## installation
To use it, clone the repo.
Create a `build` directory and cd into it:
```sh
mkdir build && cd build
```
Use `cmake` to create a `Makefile`:
```sh
cmake ..
```
Build it with `make`:
```sh
make
```
And you're ready to run it!

## usage
```
shitpostlib [option] text

OPTIONS
        -h, --help
               Shows this help message.
        -g, --gaylang  
               Generate text in a copypasta-like style.
```

## examples
```sh
$ shitpostlib -g "xin chào, em yêu anh nhiều lắm anh ơi"
xin chào, e iu ank nkìu lémm ank ơi
$ shitpostlib -g em nhớ anh rất nhiều
em nkớ ank gấk nkìu
```

## contribution
You can freely contribute to this project, by writing code or finding bugs.
When writing code, follow the [Linux kernel coding style](https://www.kernel.org/doc/html/v4.11/process/coding-style.html).
In brief:
* use tabs, 8 spaces wide. Using tabs is more dynamic, and 8-wide tabs acts as a warning for the following rule.
* do not **ever** indent more than 3 times. If that is the case, it is complicated enough to seperate into its own function.
* `case` should be indented to the same level as the `switch` statement.
* a function should have the opening brace on the next line, while all other statements such as `if` and `for` have one on the same line. For example:
```c
int main()
{
        if (1) {
                switch (4) {
                case 1:
                        ...
                        break;
                case 2:
                        ...
                        break;
                default:
                        ...
                        break;
               }
        }
}
```
* space must be inserted beetween operators (except `sizeof`).
* do not write short names for global variables, even if it sounds stupid like `dictionaryTextContentJson`, while local ones can be shorter (but not too short).
* do not depend too much on operating system specific library or functions.
