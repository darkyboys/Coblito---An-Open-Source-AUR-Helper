# This file will define <your username>'s contribution
[A Brief overview of what you have contributed to]

## A More descriptive way to describe my contribution
[Describe your contributions in detail]

## Orignal to updated parts of code
[here please place the parts of code from orignal files]
example:
main.cc -
```cpp
    else if (arg_string == "--version") std::cout<<pckg.version;
    else if (arg_string == "-l") pckg.list();
    else if (arg_string == "-c") pckg.clean();
```

**After update**
main.cc - 
```cpp
    else if (arg_string == "--version" or arg_string == "-v" or arg_string == "version") std::cout<<pckg.version;
    else if (arg_string == "-l" or arg_string == "list") pckg.list();
    else if (arg_string == "-c" or arg_string == "clean" or arg_string == "clear") pckg.clean();
```

[This was just an example for a better explanation and you must do this for every file you have edited and if you have created new files then just write **-new-file:[filename]** - and then the content and then mark the end point of file with **-end-file[filename]**]
example:

**-new-file:[myfile.txt]** - 
This is my file
**-end-file[myfile.txt]**

## And then finally after all of this i accept that my contribution matches and don't voilates the Contribution Guide Lines setted in official repository of Coblito which is only https://github.com/darkyboys/Coblito---An-Open-Source-AUR-Helper.