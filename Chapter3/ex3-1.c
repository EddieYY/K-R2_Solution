/*Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time. */

#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

#define MAXX 20000

int main(void)
{
	int test[MAXX];
	clock_t time_taken, time_taken2;
	for(int i=0; i<MAXX; i++)
		test[i]=i;

	for(int i=0, time_taken=clock(); i< MAXX;i++ ){
		binsearch(test[i], test, MAXX);
	}
	time_taken = clock() - time_taken;
 	printf("binsearch() took %lu clocks (%lu seconds)\n", (unsigned long) time_taken, (unsigned long) time_taken / CLOCKS_PER_SEC);
	for(int i=0, time_taken2=clock(); i< MAXX;i++ ){
		binsearch2(test[i], test, MAXX);
	}
	time_taken2 = clock() - time_taken2;
 	printf("binsearch2() took %lu clocks (%lu seconds)\n", (unsigned long) time_taken2, (unsigned long) time_taken / CLOCKS_PER_SEC);


}



/*
int main(void)
{
	int test[] = {1, 3, 5, 7, 9, 11, 13, 15};
	 for(int i=(sizeof(test)/sizeof(int))-1; i>=0; --i){
    		printf("looking for %d. Index=%d\n",test[i],binsearch(test[i], test, sizeof(test)/sizeof(*test)));
    		printf("i=%d, sizeof(test)=%lu, sizeof(int)=%lu, sizeof(*test)=%lu\n", i, sizeof(test), sizeof(int), sizeof(*test));
    		printf("binsearch2: looking for %d. Index=%d\n",test[i],binsearch2(test[i], test, sizeof(test)/sizeof(*test)));
	 	}
	return 0;
}*/
int binsearch(int x, int v[], int n)
{
	int low, mid, high;
	low=0;
	high=n-1;
	while(low < high){
		mid=low+(high-low);
		if(x > v[mid]){
			low=mid+1;
		}else if(x<v[mid]){
			high = mid-1;
		}else{
			return mid;
		}
	}
	return -1;

}

int binsearch2(int x, int v[], int n)
{
	int low, mid, high;
	low=0;
	high=n-1;
	while(low < high){
		mid=low+(high-low);
		if(x >= v[mid]){
			low=mid;
		}else{
			high = mid-1;
		}
	}
	return (x==v[low]) ? low : -1;
}

