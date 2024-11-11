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

As you see, you must begin documentation with 2 comments characters. If it was with a `c++` or `javascript` file, because comments are `//` (2 characters natively), the following will work.

<code>
//@T Add
//@U Description paragraph1
//@D Description paragraph2
//@A x : first int number to add
//@A y : second iint number to add
//@X
//@E add(3, 4)
//@E 7
//@X

int add(int &a, int &b):
    return a + b;
</code>

`T` stands for Title

`U` stands for usage (shows function and its parameters)

`D` stands for description (output paragraph of description)

`A` stands for arguments (output table of args | definition)

`E` stands for example (output code example within <ode tag)

`X` must be put at the end of arguments and examples block

## Usage:

`g++ -03 cpp_doc.cpp`

And then...

`./a.out`

`$File: code.py` 

`$Path of the logo image if exists: logo.jpg`

That's all.


