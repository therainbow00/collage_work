#include<stdio.h>
#include<stdlib.h>

int Stack[200]; // be careful you don't exceed more than 200;
int stack_size=200;
int top=-1;


int G[100][100];
int n_g,m_g; // number of vertices and number of arcs


int GraphConstruct( char *file_name) {

    // read the file and return the number of vertices and allocate memory for GraphPointer

    FILE *fp;

    fp=fopen (file_name, "r");

    if (fp ==NULL ) {
        printf("no file \n");
        exit(1);
    }

    int n,m,a,b;

    fscanf(fp,"%d", &n_g); // read the number of vertices
    fscanf(fp,"%d", &m_g);  // read the number of edges of G

	n=n_g;
	m=m_g;
    // allocate memory for the input graph G which is read from a file graph-G.txt
    int i,j;


    for (i=0;i < n;i++)
        for(j=0; j< n; j++)
            G[i][j]=0;


    // read the pair of adjacent vertices from the file

    for (i=0; i< m; i++) {
        fscanf(fp,"%d", &a);
        fscanf(fp,"%d", &b);
       // fscanf(fp,"%d",&G[a][b]);
		G[a][b]=1;

    }

    fclose(fp);
	for (i=0; i< n; i++){
			for (j=0; j< n; j++)
				printf("%d  ",G[i][j]);
			printf("\n");
		}
		printf("\n");


    return 1;


}


void find_cycle(){


	int i,j;
	int Removed[n_g]; // it shows whether some vertex has been removed from the stack.

	for (i=0; i< n_g; i++)
		Removed[i]=0;

	// this is to avoid reading a neighbor of a  node many times
	int neighbor[n_g][n_g];
	for (i=0; i< n_g; i++)
		for (j=0;j < n_g; j++)
			neighbor[i][j]=0;


	int node; // we run dfs from evey node that has not been explored yet. Initially from node zero.

	int flag=0; // to decide if the current node has a neighbor, otherwise it should be removed from stack.
	int current;

	int Explore[n_g];
	for (i=0; i<n_g;i++)
		Explore[i]=0;


	for (node=0; node < n_g; node++)

	  if (Explore[node]==0 ){
		  top=-1;
		  Stack[top+1]=node;
	  	  top++;
	  	  Explore[node]=1;



		while (top >= 0)
		{

		  current=Stack[top];
		 //printf("%d, %d \n" , top, current);
		 //c=getchar();
	      flag=0;  // to decide if the current node has a neighbor, otherwise should be // removed from stack.
		  for (i=0; i < n_g && !flag; i++) {
			if (G[current][i] && neighbor[current][i]==0 && !Removed[i] ){
				// once a neighbor of current is considered we don't consider  it again

				neighbor[current][i]=1;
				if (Explore[i]==1) // we have found a cycle; and print it here
					{
						printf("The cycle is \n");
					    while (Stack[top] != i )
						{
							printf("%d , ", Stack[top]);
						    top--;
						}
						printf("%d \n",i);
						//c=getchar();
						return ;
					}
				else {
					Stack[top+1]=i;
					top++;
					Explore[i]=1;
					flag=1;
					if (top >= stack_size)
					{
						printf("Stack overflow\n");
						exit(1);
					}
				}
			}
		}

		if (flag==0){ // no out-neighbor for top of stack;
			Removed[Stack[top]]=1;
		    top--;
	   }

  	  }
	}

}



int main(int argc, char *argv[]) {

   GraphConstruct(argv[1]);

   find_cycle();


}
