#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char reserved[6][10]= {"for", "while", "int","float","if","else"};
int main () {
   char str2[100];

   FILE * fp;

// Assuming we don't allow '(', ')' , '*', '!', '/', ';' ,... be part of a variable name

   fp = fopen ("file.txt", "r");

   int i=0;
   int j;
    while (fscanf(fp, "%c", &str2[i]) != EOF )
     {

		 if (str2[i] == ' ')
			{
				str2[i]='\0';
		 	   	if (strlen(str2))
					{
   					 printf("Word is %s\n", str2 );
   					 for (j=0; j<6; j++)
   					   if ( ! strcmp(str2,reserved[j]))
					   {
    						printf("Reservd word %d \n",j);
					        break;

					  }
				  }
				i=0;
				continue; // go to the beginning of the while
			}

   		 if (str2[i] == '\n')

   			{
   				i=0;
   				continue; // go to the beginning of the while
   			}

			if ( str2[i]=='(')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;

				   }
			    }
				printf("Word is %c\n", '(' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]==')')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				      // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", ')' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]==';')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;

				   }
			    }
				printf("Word is %c\n", ';' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='=')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '=' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='+')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '+' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='{')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '{' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='}')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '}' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='<')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '<' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='>')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '>' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='/')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '/' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='*')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '*' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='%')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '%' );
				i=0;
				continue; // go to the beginning of the while
			}

			if ( str2[i]=='"')

			{
				str2[i]='\0';
		 	   	if (strlen(str2))
				{
				 printf("Word is %s\n", str2 );
				 for (j=0; j<6; j++)
				   if ( ! strcmp(str2,reserved[j]))
				   {
						printf("Reservd word %d \n",j);
				        break;
				        // if str2 is a reserved word then potentially an error
				   }
			    }
				printf("Word is %c\n", '"' );
				i=0;
				continue; // go to the beginning of the while
			}

		 	   i++;

     }

   fclose(fp);

   return(0);
}
