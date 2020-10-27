/*
  Read from command-line arguments.  Sample transcript...

cs202@cs:~/solutions/h9$ ./g_file_head.o
Usage: ./g_file_head.o file1.txt file2.txt ...

cs202@cs:~/solutions/h9$ ./g_file_head.o a_empty.c 
** file: a_empty.c **
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
**  end **

cs202@cs:~/solutions/h9$ ./g_file_head.o a_empty.c /u1/junk/kinne/text-samples/shakespeare.txt 
** file: a_empty.c **
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
**  end **
** file: /u1/junk/kinne/text-samples/shakespeare.txt **
The Project Gutenberg EBook of The Complete Works of William Shakespeare, by
William Shakespeare

This eBook is for the use of anyone anywhere at no cost and with
almost no restrictions whatsoever.  You may copy it, give it away or
**  end **

cs202@cs:~/solutions/h9$ ./g_file_head.o nofile a_empty.c nofile2
** file: nofile **
** unable to open **
** file: a_empty.c **
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
**  end **
** file: nofile2 **
** unable to open **

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  
  return 0;
}
