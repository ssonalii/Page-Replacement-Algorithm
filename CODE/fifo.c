#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>

//code
int main()
{
//declaring variables..
int values[50], pageFaults = 0, m, n, s, pages, frames,pageHits=0;
printf("\nEnter the number of Pages: ");
scanf("%d", &pages); //taking input for total number of pages
printf("\nEnter the string values:\n");
//for loop start
for( m = 0; m < pages; m++)
{
printf("Value No. [%d]: ", m + 1);  
scanf("%d", &values[m]);//taking input for the values
}
//for loop end
printf("\nEnter total number of frames: ");
scanf("%d", &frames); //taking input for frames

int temp[frames];
for(m = 0; m < frames; m++)
{
temp[m] = -1;
}
for(m = 0; m < pages; m++)
{
s = 0;
for(n = 0; n < frames; n++)
{
if(values[m] == temp[n])
{
s++;
pageFaults--;
}
}
pageFaults++;
if((pageFaults <= frames) && (s == 0))
{
temp[m] = values[m];
}
else if(s == 0)
{
temp[(pageFaults - 1) % frames] = values[m];
}
printf("\n");
for(n = 0; n < frames; n++)
{
printf("%d\t", temp[n]);
}
}
pageHits=pages-pageFaults;
printf("\n\n");
printf("\nTotal Page Faults: %d\n", pageFaults);
printf("Total Page Hits: %d",pageHits);
printf("\n\n");
}
//FIFO PAGE REPLACEMENT
