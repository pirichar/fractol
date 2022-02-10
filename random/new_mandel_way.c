#include <stdio.h>
#include <unistd.h>

int     main(void)
{
        int A,B,i;
        double a,b,x,y,t;
        int height = 10;
        int width = 10;

		  printf("Mandelbrot Set\n");
        for(B=0;B < height;B++)
        {
            b= (((float)4.0*(B - (height/2))) / (height)) - (float)0.0;
              for(A=0;A< width;A++)
            {
                a= (((float)4.0*(A - (width/2))) / (height)) - (float)0.0;
                x=0.0;
                y=0.0;
                for(i=1;i<=1000;i++)
                {
                    t= ((x*x) - (y*y)) + b;
                    y= (((float)2.0 * x)*y) + a;
                    x = t;
                    if(((x*x)+(y*y)) > (float)4.0)
                        break;
                }
                if(i==1001)
					printf(".");

				else
					printf(" ");
            }
			printf("\n");
        }
	return (0);
}
