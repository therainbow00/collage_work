CS456 Assignment #2	10 points

Complete the ps.c program to output a process listing.  To do this properly you
will need the following:

- You will need to scandir(3) the /proc filesystem.  You are only interested in
  the entries that start with a digit.  Consider using a filter.  The output
  should be version sorted.

- To get the command line output, open the file /proc/<pid>/cmdline and read
  up to 4K of it.  If it is not zero length then it is a sequence of null
  terminated strings.  Just print a space when you encounter a null character,
  up to the end of the "file".

  If the file is zero length, then open /proc/<pid>/status, skip over the first
  6 bytes and output the rest of the first line (up to the newline) between
  []'s.  These processes represent kernel "threads".

  If you cannot open the file(s), then abort printing the process listing for
  that particular process (it may have exited between the scandir and the
  attempt to list it.)

- The pid should be right aligned to 6 characters on output.  The command line
  should stop before the edge of the terminal window.  You can use 80 - 7
  columns as a default, or use ioctl(2) to get the size of the window via the
  TIOCGWINSZ ioctl.  Read the man page on ioctl_tty(2) for more information on
  the 'struct winsize' structure.

