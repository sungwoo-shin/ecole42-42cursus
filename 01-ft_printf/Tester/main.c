#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>



int	main(void)
{
	int	ret1;
	int	ret2;
	char *p;

	ret1 = printf("-->|%-16.p|<--\n", p);
	printf("\n%d\n", ret1);
	ret2 = ft_printf("-->|%-16.p|<--\n", p);
	printf("\n");
	printf("%d\n", ret2);
	printf("==========\n");
}


// int	main(void)
// {
// 	int	ret1;
// 	int	ret2;
// 	char *p = NULL;

// 	// ret1 = printf("%42.25u", INT_MAX);
// 	// printf("\n%d\n", ret1);
// 	// ret2 = ft_printf("%42.25u", INT_MAX);
// 	// printf("\n");
// 	// printf("%d\n", ret2);
// 	// printf("==========\n");

// 	ret1 = printf("%42.25u", -1);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25u", -1);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");
// }

// "%42.25u"
// "%42.25x"
// "%42.25X"
// "%42.25u"
// "%42.25x"



// "%42.25u"
// "%42.25x"
// "%42.25X"
// "%42.25u"
// "%42.25x"
// ret1 = printf("%42.25u", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25u", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25x", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25x", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25X", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25X", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25u", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25u", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25x", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25x", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// "%42.25X"
// "%42.25u"
// "%42.25x"
// "%42.25X"
// "%42.25u"
// ret1 = printf("%42.25X", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25X", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25u", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25u", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25x", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25x", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25X", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25X", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25u", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25u", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// "%42.25x"
// "%42.25X"
// "%42.25u"
// "%42.25x"
// "%42.25X"
// ret1 = printf("%42.25x", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25x", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25X", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25X", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25u", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25u", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25x", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25x", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// 	ret1 = printf("%42.25X", 8);
// 	printf("\n%d\n", ret1);
// 	ret2 = ft_printf("%42.25X", 8);
// 	printf("\n");
// 	printf("%d\n", ret2);
// 	printf("==========\n");

// "%42.25u"
// "%42.25x"
// "%42.25X"
// "%42.25u"
// "%42.25x"





// "%42.25X"
// "%42.25u"
// "%42.25x"
// "%42.25X"


// 1st '*' = 42, 2nd '*' = 25
// prefix는 항상 마지막에 나오는구나!!


// - 없는거
// + 추가된거

// . 있을때 -> pointer가 0일때 -> 0x만 나와야됨
// 지금은 0x0

// .만 있을때


// type c test case
// int main(void)
// {
// 	printf("printf: \n");
// 	printf("res: %c\n", 'a');
// 	printf("%5c\n", 'a');
// 	printf("%-5c\n", 'a');
// 	printf("%%\n");
// 	printf("\n");

// 	printf("ft_printf: \n");
// 	ft_printf("res: %c", 'a');
// 	printf("\n");
// 	ft_printf("%5c", 'a');
// 	printf("\n");
// 	ft_printf("%-5c", 'a');
// 	printf("\n");
// 	ft_printf("%%");
// }

// //type p test case
// int	main(void)
// {
// 	char *ptr;

// 	printf("printf:\n");
// 	printf("%p\n", ptr);
// 	printf("%-p\n", ptr);
// 	printf("%10p\n", ptr);
// 	printf("%.p\n", ptr);
// 	printf("==========\n");

// 	printf("ft_printf:\n");
// 	ft_printf("%p", ptr);
// 	printf("\n");
// 	ft_printf("%-p", ptr);
// 	printf("\n");
// 	ft_printf("%10p", ptr);
// 	printf("\n");
// 	ft_printf("%.p", ptr);
// }

// // type u test case
// int	main(void)
// {
// 	printf("printf:\n");
// 	printf("%u\n", 123);
// 	printf("%u\n", -123);
// 	printf("%d\n", INT_MAX);
// 	printf("%d\n", INT_MIN);
// 	printf("%u\n", INT_MAX);
// 	printf("%u\n", INT_MIN);
// 	printf("==========\n");

// 	printf("ft_printf:\n");
// 	ft_printf("%u", 123);
// 	printf("\n");
// 	ft_printf("%u", -123);
// 	printf("\n");
// 	ft_printf("%d", INT_MAX);
// 	printf("\n");
// 	ft_printf("%d", INT_MIN);
// 	printf("\n");
// 	ft_printf("%u", INT_MAX);
// 	printf("\n");
// 	ft_printf("%u", INT_MIN);
// }

// //type d test case
// int	main(void)
// {
// 	printf("printf:\n");
// 	printf("res: %d\n", 123); // gen_str + no opt

// 	printf("%5d\n", 123); // w
// 	printf("%-5d\n", 123); // -w
// 	printf("%05d\n", 123); // 0w
// 	printf("==========\n");
// 	printf("%*d\n", 5, 123); // * 우측
// 	printf("%*d\n", -5, 123); // * 좌측
// 	printf("%-*d\n", 5, 123); // * 좌측
// 	printf("%-*d\n", -5, 123); // * 좌측
// 	printf("==========\n");
// 	printf("%0*d\n", 5, 123); // 0*
// 	printf("%0*d\n", -5, 123); // 0*
// 	printf("==========\n");
// 	printf("%.5d\n", 123); // .p
// 	printf("%-.5d\n", 123); // -.p
// 	printf("%0.5d\n", 123); // 0.p
// 	printf("==========\n");
// 	printf("%.*d\n", 5, 123); // .*
// 	printf("%-.*d\n", 5, 123); // -.*
// 	printf("%0.*d\n", 5, 123); // 0.*
// 	printf("==========\n");

// 	printf("ft_printf:\n");
// 	ft_printf("res: %d", 123);
// 	printf("\n");

// 	ft_printf("%5d", 123); // w
// 	printf("\n");
// 	ft_printf("%-5d", 123); // -w
// 	printf("\n");
// 	ft_printf("%05d", 123); // 0w
// 	printf("\n");

// 	ft_printf("%*d", 5, 123); // * 우측
// 	printf("\n");
// 	ft_printf("%*d", -5, 123); // * 좌측
// 	printf("\n");
// 	ft_printf("%-*d", 5, 123); // * 좌측
// 	printf("\n");
// 	ft_printf("%-*d", -5, 123); // * 좌측
// 	printf("\n");

// 	ft_printf("%0*d", 5, 123); // 0*
// 	printf("\n");
// 	ft_printf("%0*d", -5, 123); // 0*
// 	printf("\n");
// 	ft_printf("%.5d", 123); // .p
// 	printf("\n");
// 	ft_printf("%-.5d", 123); // -.p
// 	printf("\n");
// 	ft_printf("%0.5d", 123); // 0.p
// 	printf("\n");

// 	printf("==========\n");
// 	ft_printf("%.*d", 5, 123); // .*
// 	printf("\n");
// 	ft_printf("%-.*d", 5, 123); // -.*
// 	printf("\n");
// 	ft_printf("%0.*d", 5, 123); // 0.*
// }

// // type s test case
// int main(void)
// {
// 	printf("printf: \n");
// 	printf("%s\n", "abc");
// 	printf("%5s\n", "abc");
// 	printf("%2s\n", "abc");

// 	printf("%-5s\n", "abc");
// 	printf("%-5.s\n", "abc");
// 	printf("%-5.2s\n", "abc");
// 	printf("%-5.5s\n", "abc");

// 	printf("res: %5.2s\n", "abc");
// 	printf("==========\n");

// 	printf("ft_printf:\n");
// 	ft_printf("%s", "abc");
// 	printf("\n");
// 	ft_printf("%5s", "abc");
// 	printf("\n");
// 	ft_printf("%2s", "abc");
// 	printf("\n");

// 	ft_printf("%-5s", "abc");
// 	printf("\n");
// 	ft_printf("%-5.s", "abc");
// 	printf("\n");
// 	ft_printf("%-5.2s", "abc");
// 	printf("\n");
// 	ft_printf("%-5.5s", "abc");
// 	printf("\n");

// 	ft_printf("res: %5.2s", "abc");
// }
