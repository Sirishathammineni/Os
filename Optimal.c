

#include <stdio.h>

#include <stdbool.h>

bool contains(int frame[], int frameSize, int page)

{

 for (int i = 0; i < frameSize; i++) 

{

 if (frame[i] == page)

{

 return true;

 }

 }

 return false;

}

int findOptimalPage(int pages[], int n, int frame[], int frameSize, int currentIndex) 

{

 int res = -1, farthest = currentIndex;

 for (int i = 0; i < frameSize; i++)

{

 int j;

 for (j = currentIndex; j < n; j++)

{

 if (frame[i] == pages[j])

{

 if (j > farthest)
{

 farthest = j;

 res = i;

 }

 break;

 }

 }

 if (j == n)

 return i;

 }

 return (res == -1) ? 0 : res;

}

void optimalPageReplacement(int pages[], int n, int frameSize) 

{

 int frame[frameSize];

 bool isPageFault[n];

 int pageFaults = 0;

 for (int i = 0; i < frameSize; i++)

 frame[i] = -1;

 for (int i = 0; i < n; i++)

 isPageFault[i] = false;

 for (int i = 0; i < n; i++)

{
 if (!contains(frame, frameSize, pages[i])) 

{


 int replaceIndex;

 if (i < frameSize) 

{

 replaceIndex = i;

 }

else

{

 replaceIndex = findOptimalPage(pages, n, frame, frameSize, i + 1);

 }

 frame[replaceIndex] = pages[i];

 isPageFault[i] = true;

 pageFaults++;

 printf("Frame state after inserting page %d: ", pages[i]);

 for (int j = 0; j < frameSize; j++)

{

 if (frame[j] != -1)

 printf("%d ", frame[j]);

 else

 printf("- ");
}

 printf("\n");

 }

 }

 printf("Total Page Faults: %d\n", pageFaults);

}

int main() 

{

 int pages[50], n, frameSize, i;

 printf("Enter the number of pages: ");

 scanf("%d", &n);

 printf("Enter the page sequence of %d pages: ", n);

 for (i = 0; i < n; i++)

 scanf("%d", &pages[i]);

 printf("Enter the frame size: ");

 scanf("%d", &frameSize);

 optimalPageReplacement(pages, n, frameSize);

 return 0;

}
