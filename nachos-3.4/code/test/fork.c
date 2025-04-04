#include "syscall.h"

int global_cnt=0;

void sum(){

	int i;

	for (i=0;i<100;i++)
	{
	    global_cnt++;
	}
	Exit(i);
}

int main()
{
    Fork(sum);
    Exit(0);
}
