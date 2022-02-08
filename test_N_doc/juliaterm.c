#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int     main(void)
{
		int A,B,i,s;
		double a,b,x,y,t,n=15,r1,r2;
		srand(24);
		while(1)
		{
			r1=(4.0*rand()/RAND_MAX)-2.0;
			r2=(2.0*rand()/RAND_MAX)-1.0;
			s = 0;
			printf("Julia Set of %lf %lf\n",r1,r2);
			for(B=0;B<=4*n;B++)
			{
				b=2-(B/n);
				for(A=0;A<=4*n;A++)
				{
					a=-2+(A/n);
					x=0;
					y=0;
					for(i=1;i<=1000;i++)
					{
						t=x;
						x=(x*x)-(y*y)+r1;
						y=(2*t*y)+r2;
						if(((x*x)+(y*y)) > 4)
							break;
					}
					if(i==1001)
					{
						printf(".");
						s=s+1;
					}
				else
					printf(" ");
			}
			printf("\n");
			}
			if(s>10)
				return(0);
		}	
	return (0);
}
