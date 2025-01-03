# Coblito - An AUR Helper For Arch Linux
**Coblito** is an Open-Source and fully free and advanced AUR helper developer for Arch Linux users to install the AUR Packages with a lot of ease , Directly through there CLI tools or via terminal. **Coblito** is also entirely safe and fully free to be modified via it's source code as it uses a begginer friendly C++ program for it's development , Meaning anyone who understands C++ can easily contribute to this software!

## Installing Coblito
**Installing** a software may be a daunting task but this doesn't applies to **Coblito** as what you only need is to copy and paste the commands given bellow to your terminal and **Coblito** will be successfully installed.
```bash
git clone https://github.com/darkyboys/Coblito---An-Open-Source-AUR-Helper.git
cd Coblito---An-Open-Source-AUR-Helper/src
g++ main.cc -o coblito
mv coblito ..
cd ..
mv coblito ..
cd ..
echo "Coblito was successfully installed in this directory now you can move the coblito bin anywhere you want, It's recomended to place it in your environment path to access it from anywhere eg '/usr/local/bin'"
```

**Congratulations!** you have successfully installed **Coblito** in your arch Linux system.

## How To Use ?
**Using Coblito** is pretty straightforward. Here's how you can use it:

*So basically Coblito needs to be controlled via CLI arguments and we will see what those arguments may be just in a few minutes. But for using those arguments we uses coblito [arguments]*

**For Example**
```bash
coblito --version
```
Don't worry as a begginer you may be confused for what `--version` is but beleave me you will see that with-in few seconds.
As now we are familiar with the structure now let's focus on what arguments we has with **Coblito**:
 - --version : This will show the version of coblito
 - version : This will work same as --version would work.
 - -v : This will work same as --version would work.

**For Example**
```bash
coblito --version
coblito version
coblito -v
# output will be same
```
 - -S [package name] : This will install a package from AUR as per the given name.
 - install [package name] : This will work same as -S would work.

**For Example**
```bash
coblito -S gimp
coblito install gimp
# output will be same as they both will install gimp
```

 - -Q [package name] : This will find a package from the dataset of coblito (This dataset is totaly locally created & private to you only, Which contains the list of names of installed packages) if it was found or not.
 - check [package name] : This will work same as -Q would work.

**For Example**
```bash
coblito -Q gimp
coblito check gimp
# output will be same as they both will find if gimp was present in dataset or not
```

 - -l : This will show the list of all packages found in the dataset.
 - list : This will work same as -l would work.

**For Example**
```bash
coblito -l
coblito list
# output will be same as they both will show the list of installed packages
```

 - -c : This will wipe out or simply clean the entire dataset, Which will result in not found anymore result for older packages when use a command which uses dataset eg. -l or -Q
 - clear : This will work same as -c would work.
 - clean : This will work same as -c would work.

**For Example**
```bash
coblito -c
coblito clean
coblito clear
# output will be same as all of them will clear the dataset
```

 - --help : This will show the CLI based documentation or this *How-To-Use* section.
 - -h : This will work same as --help would work.
 - help : This will work same as --help would work.

 **For Example**
```bash
coblito -h
coblito --help
coblito help
# output will be same as all of them will show the CLI based documentation
```

*For deleting packages be sure to use `sudo pacman -R [package name]` or `sudo pacman -Rns [package name]` as your packages are installed via pacman in the end because coblito just makes your work of downloading and building the packages easy only but in the end pacman is used to install packages from the downloaded tar.zst file.*

## Want To Contribute ?
Checkout the <a href="CONTRIBUTING.md">CONTRIBUTING.md</a> file for more info.

Licensed under the : <a href="LICENSE">MIT License</a>
Author : <a href="https://github.com/darkyboys">dakyboys/ghgltggamer</a>

*Thanks For Reading*