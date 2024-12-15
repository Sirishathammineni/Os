

#include <stdio.h>

int n, pg[30], fr[10];

void lru();

int main()

{

 int i;

 printf("Enter total number of pages: \n");

 scanf("%d", &n);

 printf("Enter page sequence:\n");

 for (i = 0; i < n; i++)

 scanf("%d", &pg[i]);

 lru(); // Call the lru function

 return 0;

}

void lru()

{

 int count[10], i, j, fault = 0, flag, f, temp, min, m, x;

 printf("Enter the frame size: \n");

 scanf("%d", &f);

 for (i = 0; i < f; i++)
{

 fr[i] = -1;

 count[i] = -1; 
 }

 for (i = 0; i < n; i++)

{

 flag = 0;

 temp = pg[i];

 for (j = 0; j < f; j++)

{

 if (fr[j] == temp)

{

 flag = 1; // Page hit

 count[j] = i; 

 break;

 }

 }

 

 if (flag == 0)

{

 

 if (fault < f) 

{
fr[fault] = temp;

 count[fault] = i;
 fault++;

 } 

else 

{


 min = 0;

 for (m = 1; m < f; m++)

{

 if (count[m] < count[min]) 

{

 min = m;

 }

 }

 fr[min] = temp; 

 count[min] = i; 

 fault++;

 }

 }

 printf("\nPage frames after accessing page %d:\t", temp);

 for (x = 0; x < f; x++) 

{

 if (fr[x] != -1)

 printf("%d\t", fr[x]);
else

 printf("-\t"); 
 }

 }

 printf("\n\nTotal number of page faults = %d\n", fault);

}
