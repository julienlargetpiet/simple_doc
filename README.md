<img src = "logo.jpg">

# simple_doc

C++ programm to generate a html page for functions documentation.

## Example

Let's consider the file `code.py`:

<code>
##@T Add
##@U Description paragraph1
##@D Description paragraph2
##@A x : first number to add
##@A y : second number to add
##@X
##@E add(3, 4)
##@E 7
##@X

add(a, b):
    return a + b
</code>

As you see, you must begin documentation with 2 comments characters. If it was with a `c++` or `javascript` file, because comments are `//`, the following will work.

<code>
##@T Add
##@U Description paragraph1
##@D Description paragraph2
##@A x : first int number to add
##@A y : second iint number to add
##@X
##@E add(3, 4)
##@E 7
##@X

int add(int &a, int &b):
    return a + b;
</code>


## Usage:

`g++ -03 cpp_doc.cpp`

And then...

`./a.out`

`$File: code.py` 

`$Path of the logo image if exists: logo.jpg`

That's all.


