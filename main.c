#include "ft_printf.h"
#include <stdio.h>

//Start the program
//Call ft_printf function with an input
//Call original printf function to test if our outputs match
int main(void)
{
    //Char Test Cases(c): Top = Original Printf Output | Bottom = My Printf Output
    printf("Char Test Cases(c): Top = Original Printf Output | Bottom = My Printf Output\n");

    printf("Char Test Case 1\n");
    printf("%c\n", 'a');
    ft_printf("%c\n\n", 'a');

    printf("Char Test Case 2\n");
    printf("%10c\n", 'a');
    ft_printf("%10c\n\n", 'a');

    printf("Char Test Case 3\n");
    printf("%-20c\n", 'a');
    ft_printf("%-20c\n\n", 'a');

    ft_printf("--------------------------------------------------------------------------\n");
//---------------------------------------------------------------------------------------

    //String Test Cases(s): Top = Original Printf Output | Bottom = My Printf Output
    printf("String Test Cases(s): Top = Original Printf Output | Bottom = My Printf Output\n");

    printf("String Test Case 1\n");
    printf("%s\n", "Roshan");
    ft_printf("%s\n\n", "Roshan");

    printf("String Test Case 2\n");
    printf("%3s\n", "Roshan");
    ft_printf("%3s\n\n", "Roshan");

    printf("String Test Case 3\n");
    printf("%25s\n", "Roshan");
    ft_printf("%25s\n\n", "Roshan");

    printf("String Test Case 4\n");
    printf("%-25s\n", "Roshan");
    ft_printf("%-25s\n\n", "Roshan");

    ft_printf("--------------------------------------------------------------------------\n");

//---------------------------------------------------------------------------------------

    //Percentage(%) Test Cases: Top = Original Printf Output | Bottom = My Printf Output
    printf("Percentage Test Case: Top = Original Printf Output | Bottom = My Printf Output\n");

    printf("Percentage Test Case 1\n");
    printf("%%\n");
    ft_printf("%%\n\n");

    printf("Percentage Test Case 2\n");
    printf("%-100%\n");
    ft_printf("%-100%\n\n");

    printf("Percentage Test Case 3\n");
    printf("%10%\n");
    ft_printf("%10%\n\n");

    ft_printf("--------------------------------------------------------------------------\n");

//---------------------------------------------------------------------------------------

    //Pointer Address(p) Test Cases: Top = Original Printf Output | Bottom = My Printf Output
    printf("Pointer Address(p) Test Case: Top = Original Printf Output | Bottom = My Printf Output\n");
    
    static int s;
    int a;
    int *p;
    /* obtain a block big enough for one int from the heap */
    p = malloc(sizeof(int));

    printf("Pointer Address Test Case 1\n");
    printf("&s = %p\n", (void *) &s);
    printf("&a = %p\n", (void *) &a);
    printf("&p = %p\n", (void *) &p);
    printf("p = %p\n\n", (void *) p);

    ft_printf("&s = %p\n", (void *) &s);
    ft_printf("&a = %p\n", (void *) &a);
    ft_printf("&p = %p\n", (void *) &p);
    ft_printf("p = %p\n\n", (void *) p);
    free(p);

    printf("Pointer Address Test Case 2\n");
    printf("&s = %-20p\n", (void *) &s);
    printf("&a = %-20p\n", (void *) &a);
    printf("&p = %-20p\n", (void *) &p);
    printf("p = %-20p\n\n", (void *) p);

    ft_printf("&s = %-20p\n", (void *) &s);
    ft_printf("&a = %-20p\n", (void *) &a);
    ft_printf("&p = %-20p\n", (void *) &p);
    ft_printf("p = %-20p\n\n", (void *) p);

    printf("Pointer Address Test Case 3\n");
    printf("&s = %20p\n", (void *) &s);
    printf("&a = %20p\n", (void *) &a);
    printf("&p = %20p\n", (void *) &p);
    printf("p = %20p\n\n", (void *) p);

    ft_printf("&s = %20p\n", (void *) &s);
    ft_printf("&a = %20p\n", (void *) &a);
    ft_printf("&p = %20p\n", (void *) &p);
    ft_printf("p = %20p\n\n", (void *) p);

    ft_printf("--------------------------------------------------------------------------\n");

//---------------------------------------------------------------------------------------

    //Decimal Test Cases(i or d): Top = Original Printf Output | Bottom = My Printf Output
    printf("Decimal Test Cases(i or d): Top = Original Printf Output | Bottom = My Printf Output\n");

    printf("Decimal Test Section 1\n");
    printf("%d\n", 20);
    ft_printf("%d\n\n", 20);
    
    printf("%+d\n", 20);
    ft_printf("%+d\n\n", 20);

    printf("% d\n", 20);
    ft_printf("% d\n\n", 20);

    printf("%d\n", -20);
    ft_printf("%d\n\n", -20);
    
    printf("%+d\n", -20);
    ft_printf("%+d\n\n", -20);

    printf("% d\n", -20);
    ft_printf("% d\n\n", -20);

    printf("Decimal Test Section 2\n");
    printf("%-.10d\n", 1234);
    ft_printf("%-.10d\n\n", 1234);

    printf("%-.10d\n", -1234);
    ft_printf("%-.10d\n\n", -1234);

    printf("%0.10d\n", 1234);
    ft_printf("%0.10d\n\n", 1234);

    printf("%0.10d\n", -1234);
    ft_printf("%0.10d\n\n", -1234);

    printf("%+.25d\n", 1234);
    ft_printf("%+.25d\n\n", 1234);

    printf("%+.25d\n", -1234);
    ft_printf("%+.25d\n\n", -1234);

    printf("% .25d\n", 1234);
    ft_printf("% .25d\n\n", 1234);

    printf("% .30d\n", -1234);
    ft_printf("% .30d\n\n", -1234);

    printf("Decimal Test Section 3\n");
    printf("%30d\n", 876321);
    ft_printf("%30d\n\n", 876321);

    printf("%30d\n", -876321);
    ft_printf("%30d\n\n", -876321);

    printf("%030d\n", 876321);
    ft_printf("%030d\n\n", 876321);

    printf("%030d\n", -876321);
    ft_printf("%030d\n\n", -876321);

    printf("%+30d\n", 876321);
    ft_printf("%+30d\n\n", 876321);

    printf("%+30d\n", -876321);
    ft_printf("%+30d\n\n", -876321);

    printf("% 30d\n", 876321);
    ft_printf("% 30d\n\n", 876321);

    printf("% 30d\n", -876321);
    ft_printf("% 30d\n\n", -876321);

    printf("%-30d\n", 876321);
    ft_printf("%-30d\n\n", 876321);

    printf("%-30d\n", -876321);
    ft_printf("%-30d\n\n", -876321);

    printf("%0.030d\n", 876321);
    ft_printf("%0.030d\n\n", 876321);

    printf("%0.030d\n", -876321);
    ft_printf("%0.030d\n\n", -876321);

    printf("%030.13d\n", 876321);
    ft_printf("%030.13d\n\n", 876321);

    printf("%030.13d\n", -876321);
    ft_printf("%030.13d\n\n", -876321);

    printf("Decimal Test Section 4\n");   

    printf("%0.52ld\n", 3121323213121231322);
    ft_printf("%0.52ld\n\n", 3121323213121231322);

    ft_printf("--------------------------------------------------------------------------\n");

//---------------------------------------------------------------------------------------

    //Octal Test Cases(o): Top = Original Printf Output | Bottom = My Printf Output
    printf("Decimal Test Cases(o): Top = Original Printf Output | Bottom = My Printf Output\n");

    printf("Octal Test Section 1\n");
    printf("%o\n", 9);
    ft_printf("%o\n\n", 9);

    printf("%.10o\n", 9);
    ft_printf("%.10o\n\n", 9);

    printf("%0.10o\n", 9);
    ft_printf("%0.10o\n\n", 9);

    printf("%-.10o\n", 9);
    ft_printf("%-.10o\n\n", 9);

    printf("%#.10o\n", 9);
    ft_printf("%#.10o\n\n", 9);

    printf("%.10o\n", -9);
    ft_printf("%.10o\n\n", -9);

    printf("%0.10o\n", -9);
    ft_printf("%0.10o\n\n", -9);

    printf("%-.10o\n", -9);
    ft_printf("%-.10o\n\n", -9);

    printf("%#.15o\n", -9);
    ft_printf("%#.15o\n\n", -9);

    printf("%0.2o\n", -9);
    ft_printf("%0.2o\n\n", -9);

    printf("%#.2o\n", -9);
    ft_printf("%#.2o\n\n", -9);

    printf("Octal Test Section 2\n");
    printf("%20o\n", -5);
    ft_printf("%20o\n\n", -5);

    printf("%-20o\n", -5);
    ft_printf("%-20o\n\n", -5);

    printf("%020o\n", -5);
    ft_printf("%020o\n\n", -5);
    
    printf("%020.3o\n", -5);
    ft_printf("%020.3o\n\n", -5); 

    printf("%#20.5o\n", -5);
    ft_printf("%#20.5o\n\n", -5); 

    printf("%#20.50o\n", -5);
    ft_printf("%#20.50o\n\n", -5);

    ft_printf("--------------------------------------------------------------------------\n");

//---------------------------------------------------------------------------------------

    //Unsigned Integer Test Cases(u): Top = Original Printf Output | Bottom = My Printf Output
    printf("Unsigned Integer Test Cases(u): Top = Original Printf Output | Bottom = My Printf Output\n");

    printf("Unsigned Integer Section 1\n");
    printf("%u\n", 999);
    ft_printf("%u\n\n", 999);

    printf("%.80u\n", 999);
    ft_printf("%.80u\n\n", 999);

    printf("%-.80u\n", 999);
    ft_printf("%-.80u\n\n", 999);

    printf("%0.80u\n", 999);
    ft_printf("%0.80u\n\n", 999);

    printf("%.2u\n", 999);
    ft_printf("%.2u\n\n", 999);

    printf("%-.2u\n", 999);
    ft_printf("%-.2u\n\n", 999);

    printf("%0.2u\n", 999);
    ft_printf("%0.2u\n\n", 999);

    printf("%0.2u\n", -999);
    ft_printf("%0.2u\n\n", -999);

    printf("Unsigned Integer Section 2\n");
    printf("%20u\n", 50123);
    ft_printf("%20u\n\n", 50123);

    printf("%-20u\n", 50123);
    ft_printf("%-20u\n\n", 50123);

    printf("%020u\n", 50123);
    ft_printf("%020u\n\n", 50123);

     printf("%020.20u\n", 50123);
    ft_printf("%020.20u\n\n", 50123);

    ft_printf("--------------------------------------------------------------------------\n");

//---------------------------------------------------------------------------------------

    //Hexadecimal Test Cases(x or X): Top = Original Printf Output | Bottom = My Printf Output
    printf("Hexadecimal Test Cases(x or X): Top = Original Printf Output | Bottom = My Printf Output\n");

    printf("Hexadecimal Section 1\n");
    printf("%.42x\n", 765);
    ft_printf("%.42x\n\n", 765);

    printf("%.42x\n", 765);
    ft_printf("%.42x\n\n", 765);

    printf("%-.42x\n", 765);
    ft_printf("%-.42x\n\n", 765);

    printf("%0.42x\n", 765);
    ft_printf("%0.42x\n\n", 765);

    printf("%#.42x\n", 765);
    ft_printf("%#.42x\n\n", 765);

    printf("%.1x\n", 765);
    ft_printf("%.1x\n\n", 765);

    printf("%-.1x\n", 765);
    ft_printf("%-.1x\n\n", 765);

    printf("%0.1x\n", 765);
    ft_printf("%0.1x\n\n", 765);

    printf("%#.1x\n", 765);
    ft_printf("%#.1x\n\n", 765);

    printf("%56x\n", 765);
    ft_printf("%56x\n\n", 765);

    printf("%056.3x\n", 765);
    ft_printf("%056.3x\n\n", 765);

    printf("%#56.3x\n", 765);
    ft_printf("%#56.3x\n\n", 765);

    ft_printf("--------------------------------------------------------------------------\n");

//---------------------------------------------------------------------------------------

    //Floating Function Cases(f): Top = Original Printf Output | Bottom = My Printf Output
    printf("Floating Function Cases(f): Top = Original Printf Output | Bottom = My Printf Output\n");
    printf("Note: Floating outputs between functions will differ because of randomness involved for extended float values\n");

    printf("Floating Function Section 1\n");
    printf("%f\n", -765.123);
    ft_printf("%f\n\n", -765.123);

    printf("%+f\n", -765.123);
    ft_printf("%+f\n\n", -765.123);

    printf("% f\n", -765.123);
    ft_printf("% f\n\n", -765.123);

    printf("%+f\n", 765.123);
    ft_printf("%+f\n\n", 765.123);

    printf("% f\n", 765.123);
    ft_printf("% f\n\n", 765.123);

    printf("%30f\n", 765.123);
    ft_printf("%30f\n\n", 765.123);

    printf("% 30f\n", 765.123);
    ft_printf("% 30f\n\n", 765.123);

    printf("%#30f\n", 765.123);
    ft_printf("%#30f\n\n", 765.123);

    printf("%-30f\n", 765.123);
    ft_printf("%-30f\n\n", 765.123);

    printf("%+30f\n", -765.123);
    ft_printf("%+30f\n\n", -765.123);

    printf("%+30f\n", 765.123);
    ft_printf("%+30f\n\n", 765.123);

    printf("%030f\n", -765.123);
    ft_printf("%030f\n\n", -765.123);

    printf("%030f\n", 765.123);
    ft_printf("%030f\n\n", 765.123);

    ft_printf("--------------------------------------------------------------------------\n");

//---------------------------------------------------------------------------------------

    //Random Combinations (For Fun): Top = Original Printf Output | Bottom = My Printf Output
    printf("Random Combinations (For Fun): Top = Original Printf Output | Bottom = My Printf Output\n");

    printf("c = %20c, d = %0.10d, and f = % .12f\n", 'a', 300, 9.2);
    ft_printf("c = %20c, d = %0.10d, and f = % .12f\n\n", 'a', 300, 9.2);

    printf("s = %-.20s o = %-12.2o x = %.21x\n", "Roshan", 12, -32);
    ft_printf("s = %-.20s o = %-12.2o x = %.21x\n", "Roshan", 12, -32);

	return (0);
}