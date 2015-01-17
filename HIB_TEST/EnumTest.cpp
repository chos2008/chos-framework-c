#include <stdio.h>
enum enum_a
{
    a = 3, 
	b, 
	c = 3, 
	d
};
void testEnum_a()
{
	enum enum_a aa = a, bb = b, cc = c, dd = d;

	printf("aa %d\n", aa);
	printf("bb %d\n", bb);
	printf("cc %d\n", cc);
	printf("dd %d\n", dd);

}

enum weekday 
{
	sun, 
	mon, 
	tue, 
	wed, 
	thu, 
	fri, 
	sat
};

void testEnum_weekday() 
{
	weekday a, b, c, d, e, f, g;
	a = sun;
	b = mon;
	c = tue;
	d = wed;
	e = thu;
	f = fri;
	g = sat;
	printf("a: %d\tb: %d\tc: %d\td: %d\te: %d\tf: %d\tg: %d\n", a, b, c, d, e, f, g);
}


int main()
{
	testEnum_a();
	testEnum_weekday();
	return 0;
}