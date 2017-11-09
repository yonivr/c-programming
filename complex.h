typedef struct Complex { /*complex data type, contains 2 double variables to store real and image values*/
	double real;
	double img ;
} complex;

void read_comp(complex *c, double real, double img);/*Reads values from stdin to an existing complex number, expects pointer to complex number and real,imaginary double values*/
void print_comp(complex *c,char name);						/*Prints a complex number to stdout in a formated fashion, expects a pointer to the complex number*/
void add_comp(complex *c1, complex *c2);			/*Adds two complex numbers and prints the result to stdout, expects two pointers to complex numbers*/
void sub_comp(complex *c1, complex *c2);			/*Subtracts two complex numbers and prints the result to stdout, expects two pointers to complex numbers*/
void mult_comp_real(complex *c, double f);			/*Multiplies a complex number with a real number and prints the result to stdout, expects a pointer to the complex number and the real number value*/
void mult_comp_img(complex *c, double f);			/*Multiplies a complex number with an imaginary number and prints the result to stdout, expects a pointer to the complex number and the imaginary number value*/
void mult_comp_comp(complex *c1, complex *c2);		/*Multiplies a complex number with another complex number and prints the result to stdout, expects two pointers to the complex numbers*/
void abs_comp(complex *c);							/*Calculates the absolute value of a complex number and prints the result to stdout, expects a pointer to a complex number*/
