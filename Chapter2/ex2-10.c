/*
 * Excercise 2-10
  Rewrite the function lower, which converts upper case letters to lower case,
   with a conditional expression instead of if-else.
*/

# include <stdio.h>

unsigned char Tolower(char x);

int main(void)
{
	char a[]="abcAbcedgEFG3344567";
	int i=0;
	 //puts(a);
	while(a[i]!='\0')
	{
		putchar(Tolower(a[i]));
		i++;
	}	
	return 0;
}


unsigned char Tolower(char x)
{
	return (x >= 'A' & x <= 'Z') ? x-'A'+'a': x;
}
