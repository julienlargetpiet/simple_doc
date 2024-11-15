<img src = "logo.jpg">

# simple_doc

C++ programm to generate a html page for functions documentation.

## Example

Let's consider the file `code.py`:

```
##@I introduction paragraph
##@I introduction paragraph2
##@I introduction paragraph3
##@I introduction paragraph4

##@T Add
##@U Description paragraph1
##@X
##@D Description paragraph2
##@A x : first number to add
##@A y : second number to add
##@X
##@E add(3, 4)
##@E 7
##@X

add(a, b):
    return a + b
```

As you see, you must begin documentation with 2 comments characters. If it was with a `c++` or `javascript` file, because comments are `//` (2 characters natively), the following will work.

```
//@I introduction paragraph
//@I introduction paragraph2
//@I introduction paragraph3
//@I introduction paragraph4

//@L1 Functions
//@T Add
//@U Description paragraph1
//@X
//@D Description paragraph2
//@A x : first int number to add
//@A y : second iint number to add
//@X
//@E add(3, 4)
//@E 7
//@X

int add(int &a, int &b):
    return a + b;
```

**T**  stands for Title

**U**  stands for usage (shows function and its parameters)

**D**  stands for description (output paragraph of description)

**A**  stands for arguments (output table of args | definition)

**E**  stands for example (output code example within <ode tag)

**X**  must be put at the end of **usage**, **arguments** and **examples** block

**LNumber** stands for Line (output hNumber tag line) Number stands for the depth level in the table of contents

**JNumber** stands for Jump (switch to hNumber tag) Number stands for the depth level in the table of contents

**I** stands for **INTRODUCTION** paragraphs

**M** stands for i**M**age (put image file into documentation)

**V** stands for Video (put vido file into documentation)

**O** is for putting an audio file into documentation

**F** stands for Folder (where all the medias come from)

**GNumber** is for putting a h tag (won't be taken in count by the table of contents unlike **LNumber**)

## Example

This repo provides a test file `test_doc.cpp` where you can find an example of how documentation is made inside a code file. 

The html associated with `test_doc.cpp` is available here: <a href="https://julienlargetpiet.tech/static/files/out.html">https://julienlargetpiet.tech/static/files/0out.html</a>

Also, you can run the programm on this file to see the output as `out.html` file.

## Usage:

`g++ -O3 cpp_doc.cpp`

And then...

`./a.out`

`$File: code.py` 

`$Path of the logo image if exists: logo.jpg`

That's all.

# Use it conveniently with shell

In `.bash_aliases`.

`alias docu="~/./path_to_compiled_programm/a.out"`

# Special characters

In documentation make sure to replace character `<` by `&lt;` and `>` by `&gt;`.

