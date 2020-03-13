
/*David Meyer
  Midterm: Take Home Programming
  CS3600
  March 3, 2020*/

#include <stdio.h>
#includ<pthread.h>

static int num[9];

//927168

void reverse(int[] temp) {
	int newArr[9];
	for (int i = 8; i >= 0; i--) {
		int index = 8-i;

		if (index == 0) {
			newArr[index] = temp[i];
		}

		while (index > 1) {
			newArr[index] = temp[i];
		}
	}//For

	num = newArr;
}

int main()
{


}
