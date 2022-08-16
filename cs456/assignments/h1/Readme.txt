CS456/556 Assignment #1

1) Re-make for yourself up to 3 Unix commands, one (or more if you wish) from 
   each group from the given list below.  The system calls you will likely need
   to use are listed after the command you may re-make.  Your commands may be 
   relatively simple (i.e. cp only needs to copy a single file for example,) but 
   the more complete the better.  With no options, your program should print a 
   usage message and terminate.  Your programs should also print a more detailed 
   help/manual if --help is given on the command line. (9pts, 3pts each)

   Note that you will need to check for error conditions and print appropriate
   status messages.  You may use perror(3) for this.

2) Create a Makefile that can compile all your programs. (1pt)

3) Edit the "manifest" file with the names of your Makefile, and all the source
   files (both .c and .h files) needed to build your programs.  handin will
   read the manifest file when submitting and submit all the files specified
   therein.

Bonus points may be awarded for particularly good implementations or from making
more than the required amount, or for making one or more from group four.

Group one:
---------
cp / cat / more:
 open(2)		- open and possibly create a file
 close(2)		- close a file descriptor
 read(2)		- read from a file descriptor
 write(2)		- write to a file descriptor

Group two:
---------
ls / tree / du:
 stat(2), lstat(2)	- get file status
 statx(2)		- get file status (extended)

 - Note there is no C wrapper to the readdir(2) system call, so if you want to
   read a directory of files, use: opendir(3)/readdir(3) or scandir(3)
   scandir(3) is probably easiest to use.

Group three:
---------
mv (!):
 rename(2)		- change the name or location of a file

link / ln (!):
 link(2)		- make a new name for a file (hard link)
 symlink(2)		- make a new name for a file (symbolic link)

rm (*) / unlink (*):
 unlink(2)		- delete a name and possibly the file it refers to

mkdir (*):
 mkdir(2)		- create a directory

rmdir (*):
 rmdir(2)		- delete a directory

chmod (*):
 chmod(2)		- change permissions of a file

readlink (*):
 readlink(2)		- read value of a symbolic link

kill (*):
 kill(2)		- send signal to a process

touch (*):
 utime(2)		- change file last access and modification times
 creat(2)/open(2)	- open and possibly create a file

! = I will consider these as group 1 programs if they accept multiple source to
    singular destination.
* = These programs should try to handle all the command line parameters given
    to them, so 'rm *.o' would remove all the .o files, not just the first one.

Group four:
----------
 - This group represents 1-2 bonus points.
stat:
 stat(2), lstat(2)	- get file status
 statx(2)		- get file status (extended)

uname:
 uname(2)		- get name and information about current kernel

uptime / free:
 sysinfo(2)		- return system information

df:
 statfs(2)		- get filesystem statistics

