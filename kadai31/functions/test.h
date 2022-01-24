#ifndef TEST_H_
#define TEST_H_

#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define message(m) fprintf(stderr,(m))
#define message1(m,a) fprintf(stderr,(m),(a))
#define message2(m,a,b) fprintf(stderr,(m),(a),(b))
#define message3(m,a,b,c) fprintf(stderr,(m),(a),(b),(c))
#define message4(m,a,b,c,d) fprintf(stderr,(m),(a),(b),(c),(d))
#define message6(m,a,b,c,d,e,f) fprintf(stderr,(m),(a),(b),(c),(d),(e),(f))
#define message8(m,a,b,c,d,e,f,g,h) fprintf(stderr,(m),(a),(b),(c),(d),(e),(f),(g),(h))
#define messend1(m,a) do{message1((m),(a));exit(1);}while(0)
#define messend2(m,a,b) do{message2((m),(a),(b));exit(1);}while(0)
#define messend3(m,a,b,c) do{message3((m),(a),(b),(c));exit(1);}while(0)
#define messend4(m,a,b,c,d) do{message4((m),(a),(b),(c),(d));exit(1);}while(0)
#define messend6(m,a,b,c,d,e,f) do{message6((m),(a),(b),(c),(d),(e),(f));exit(1);}while(0)
#define messend8(m,a,b,c,d,e,f,g,h) do{message8((m),(a),(b),(c),(d),(e),(f),(g),(h));exit(1);}while(0)
#define DELTA 1e-6

void testStart(char *mes)
{
	fprintf(stderr, "%s ... ", mes);
}


void testEnd()
{
	message("Ok\n");
}

#define assert_equals_int(a, b) assert_equals_int_func(a, b, __FILE__, __LINE__)
void assert_equals_int_func(int a, int b, char *fname, int line)
{
	if (a != b)
		messend4("Error in %s(%d): a != b (%d != %d)\n", fname, line, a, b);
}

#define assert_not_equals_int(a, b) assert_not_equals_func(a, b, __FILE__, __LINE)
void assert_not_equals_int_func(int a, int b, char *fname, int line)
{
	if (a == b)
		message4("Error in %s(%d): a == b (%d == %d)\n", fname, line, a, b);
}

#define assert_equals_ints assert_equals_int

#define assert_equals_float(a, b) assert_equals_float_func(a, b, __FILE__, __LINE__)
void assert_equals_float_func(float a, float b, char *fname, int line)
{
	if (isnan(a) || isnan(b))
		messend4("Error in %s(%d): a(%f) or b(%f) is NaN\n", fname, line, a, b);
	if (fabs(a - b) > DELTA)
		message4("Error in %s(%d): a != b (%f != %f)\n", fname, line, a, b);
}

#define assert_equals_double(a, b) assert_equals_double_func(a, b, __FILE__, __LINE__)
void assert_equals_double_func(double a, double b, char *fname, int line)
{
	if (isnan(a) || isnan(b))
		messend4("Error in %s(%d): a(%f) or b(%f) is NaN\n", fname, line, a, b);
	if (fabs(a - b) > DELTA)
		messend4("Error in %s(%d): a != b (%f != %f)\n", fname, line, a, b);
}
#define assert_equals_doubles assert_equals_double

#define assert_equals_mat(a, b, n) assert_equals_mat_func(a, b, n, __FILE__, __LINE__)
void assert_equals_mat_func(double *ap, double *bp, int n, char *fname, int line)
{
	int i;
	for (i = 0; i < n * n; i ++)
        if (fabs(ap[i] - bp[i]) > DELTA)
            messend6("Error in %s(%d): a[%d] != b[%d] (%f != %f)\n", fname, line, i, i, ap[i], bp[i]);
}

#define assert_equals_vec(a, b, n) assert_equals_vec_func(a, b, n, __FILE__, __LINE__)
void assert_equals_vec_func(double *ap, double *bp, int n, char *fname, int line)
{
	int i;
	for (i = 0; i < n ; i ++)
        if (fabs(ap[i] - bp[i]) > DELTA)
            messend6("Error in %s(%d): a[%d] != b[%d] (%f != %f)\n", fname, line, i, i, ap[i], bp[i]);
}

#endif
