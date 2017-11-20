#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include  "complex.h"


void read_comp(complex *c, double real, double img)/*Reads values from stdin to an existing complex number, expects pointer to complex number and real,imaginary double values*/
{
	c->img = img;
	c->real = real;
}
void print_comp(complex *c,char name)						/*Prints a complex number to stdout in a formated fashion, expects a pointer to the complex number*/
{
	printf("%c = %f + (%f)i\n",name,c->real,c->img);
}
void add_comp(complex *c1, complex *c2)			/*Adds two complex numbers and prints the result to stdout, expects two pointers to complex numbers*/
{
	printf("%f + %fi + %f + %fi = %f + %fi", c1->real, c1->img, c2->real, c2->img, c1->real+ c2->real, c1->img + c2->img);
}
void sub_comp(complex *c1, complex *c2)			/*Subtracts two complex numbers and prints the result to stdout, expects two pointers to complex numbers*/
{
	printf("(%f + %fi) - (%f + %fi) = %f + %fi", c1->real, c1->img, c2->real, c2->img, c1->real - c2->real, c1->img - c2->img);
}
void mult_comp_real(complex *c, double f)			/*Multiplies a complex number with a real number and prints the result to stdout, expects a pointer to the complex number and the real number value*/
{
	printf("%f*(%f + %fi) = %f + %fi\n",f, c->real, c->img,c->real*f,c->img*f);
}
void mult_comp_img(complex *c, double f)			/*Multiplies a complex number with an imaginary number and prints the result to stdout, expects a pointer to the complex number and the imaginary number value*/
{
	printf("%fi*(%f + %fi) = -%f + %fi\n", f, c->real, c->img, c->img*f, c->real*f);
}
void mult_comp_comp(complex *c1, complex *c2)		/*Multiplies a complex number with another complex number and prints the result to stdout, expects two pointers to the complex numbers*/
{
	printf("(%f+%fi)*(%f+%fi) = %f+%fi\n",c1->real,c1->img,c2->real,c2->img,(c1->real*c2->real - c1->img*c2->img ),(c1->real*c2->img+c1->img*c2->real) );
}
void abs_comp(complex *c)
{
	printf("|%f+%fi| = %f\n" , c->real,c->img,sqrt(c->real*c->real + c->img*c->img));
}
