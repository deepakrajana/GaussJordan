#include <stdio.h>
#include <math.h>
#include <time.h>
float a[20][20];
int main()
{
  float Aug[20][1];
  int i,j,order;
  clock_t start = clock();
  printf("\nEnter order of matrix A : ");
  scanf("%d",&order);
  if(order == 0)
  {
      printf("Cannot proceed further as order is 0");
  }
  else 
  {
  printf ("\nEnter the elements of Matrix A\n");
  for (i = 1; i <= order; i++)
    {
      for (j = 1; j <= order; j++)
	{
	  printf ("a[%d][%d] = ", i, j);
	  scanf ("%f", & a[i][j]);
	}
    }
  printf ("\n\n---------- Matrix A is --------------\n");
  for (i = 1; i <= order; i++)
    {
      printf ("\n");
      for (j = 1; j <= order; j++)
	{
	  printf ("\t%0.2f \t", a[i][j]);	//Printing A array
	}
    }
  printf("\n\nEnter the elements of Matrix B\n");
  for(i=1;i<=order;i++)
     {
    printf ("b[%d][%d] = ", i, j);
    scanf("%f",&a[i][order+1]);
    }
   for(i=1;i<=order;i++)
    {
        for(j=1;j<=order;j++)
        {
         if(i==j)
           {
             if(a[i][j]==0)
              {
                for(int p=i;p<=order;p++)
                {
                  if(a[p+1][j]!=0)
                  {
                   for(int o=1;o<=order+1;o++)
                     {
                     int r = a[p][o];
                     a[p][o] = a[p+1][o];
                     a[p+1][o] = r;
                     }
                   break;
                  }
                }
                 printf("No Solution possible as values =! 0");
                 break;
              }
            }
             
        }
    }
 printf ("\n\n----------Augmented Matrix AB is--------------\n");
       printf ("\n");
   for(i=1;i<=order;i++)
    {
     for(j=1;j<=order+1;j++)
       {
        printf("\t%.2f \t",a[i][j]);
        }
        printf("\n\n");
    }
    for(j=1; j<=order; j++)
    {
        for(i=1; i<=order; i++)
        {
            if(i!=j)
            {
                float c=a[i][j]/a[j][j];
                for(int k=1; k<=order+1; k++)
                {
                    a[i][k]=a[i][k]-c*a[j][k];
                }
            }
        }
    }
   for(i=1; i<=order; i++)
    {   
        Aug[i][1]=(float)a[i][order+1]/(float)a[i][i];
        printf("X[%d]= %.2f\n",i,Aug[i][1]);
    }     

printf("\n Time to Compile is : %f\n", ((double)clock()-start)/CLOCKS_PER_SEC);
 return 0;
}
}

