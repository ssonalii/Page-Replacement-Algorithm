#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
//FIND LRU
int findLRU(int time[], int n){
int i, minimum = time[0], pos = 0;

for(i = 1; i < n; ++i){
if(time[i] < minimum){
minimum = time[i];
pos = i;
}
}
return pos;
}
//FIND LRU

//FUNCTIONS
void homescreen();
void back();
void fifo();
void lru();
void opr();
//FUNCTIONS

//code
int main()
{
    homescreen();
}

void homescreen()
{
    int ch;
    printf("Select an option for page replacement\n\n");
    printf("1.FIFO (First In First Out)\n2.LRU (Least Recently Used)\n3.Optimal Page Replacement\n4.Exit");
    printf("\n\nEnter your choice: ");
    ch=toupper(getch());
    if(ch=='1')
     {
        system("cls");
        printf("***************************************************\n");
        printf("You have selected FIFO page replacement algorithm\n");
        printf("***************************************************\n");
        fifo();
    }
    else if(ch=='2')
    {
        system("cls");
        printf("***************************************************\n");
        printf("You have selected LRU page replacement algorithm\n");
        printf("***************************************************\n");
        lru();
    }
    else if(ch=='3')
    {
        system("cls");
        printf("***************************************************\n");
        printf("You have selected Optimal page replacement algorithm\n");
        printf("***************************************************\n");
        opr();
    }
    else if(ch=='4')
    {
        system("cls");
        printf("\n\n\t\t\t\t\t\tThanks for using the program\n\n\n");
        getch();
        exit(1);
    }
    else
    {
        printf("(Invalid Choice)");
        printf("\n\nPress any key to continue");
        getch();
        system("cls");
        homescreen();
    }
}

void back()
{
    int ch;
    system("cls");
    printf("Thanks for using the program\n");
    printf("To use the program again press R\n");
    printf("To exit the program press E\n");
    ch=toupper(getch());
    if(ch=='R' || ch=='r')
    {
        system("cls");
        homescreen();
    }
    else if(ch=='E' || ch=='e')
    exit(1);
    else
    {
        printf("\nInvalid Option..");
        printf("\n\nPress any key to continue");
        getch();
        back();
    }
}
//FIFO PAGE REPLACEMENT
void fifo()
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
printf("Total Page Hits: %d\n",pageHits);
printf("\n\nPress any key to continue");
getch();
back();
}
//FIFO PAGE REPLACEMENT

//LRU PAGE REPLACEMENT
void lru()
{
int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0, hits=0;
printf("Enter number of pages: ");
scanf("%d", &no_of_pages);
printf("\nEnter reference string\n");
for(i = 0; i < no_of_pages; ++i)
{
printf("Value No. [%d]: ", i + 1);
scanf("%d", &pages[i]);
}
printf("\nEnter number of frames: ");
scanf("%d", &no_of_frames);
for(i = 0; i < no_of_frames; ++i){
frames[i] = -1;
}
for(i = 0; i < no_of_pages; ++i){
flag1 = flag2 = 0;
for(j = 0; j < no_of_frames; ++j){
if(frames[j] == pages[i]){
counter++;
time[j] = counter;
flag1 = flag2 = 1;
break;
}
}
if(flag1 == 0){
for(j = 0; j < no_of_frames; ++j){
if(frames[j] == -1){
counter++;
faults++;
frames[j] = pages[i];
time[j] = counter;
flag2 = 1;
break;
}
}
}
if(flag2 == 0){
pos = findLRU(time, no_of_frames);
counter++;
faults++;
frames[pos] = pages[i];
time[pos] = counter;
}
printf("\n");
for(j = 0; j < no_of_frames; ++j){
printf("%d\t", frames[j]);
}
}
hits = no_of_pages - faults;
printf("\n\nTotal Page Faults = %d", faults);
printf("\nTotal Page Hits = %d", hits);
printf("\n\nPress any key to continue");
getch();
back();
}
//LRU PAGE REPLACEMENT

//OPTIMAL PAGE REPLACEMENT
void opr()
{
int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0, hits=0;
printf("Enter number of pages: ");
scanf("%d", &no_of_pages);
printf("\nEnter page reference string\n");
for( i = 0; i < no_of_pages; i++)
{
printf("Value No. [%d]: ", i + 1);
scanf("%d", &pages[i]);//taking input for the values
}
printf("\nEnter number of frames: ");
scanf("%d", &no_of_frames);
for(i = 0; i < no_of_frames; ++i){
frames[i] = -1;
}
for(i = 0; i < no_of_pages; ++i){
flag1 = flag2 = 0;
for(j = 0; j < no_of_frames; ++j){
if(frames[j] == pages[i])
{
flag1 = flag2 = 1;
break;
}
}
if(flag1 == 0){
for(j = 0; j < no_of_frames; ++j){
if(frames[j] == -1){
faults++;
frames[j] = pages[i];
flag2 = 1;
break;
}
}
}
if(flag2 == 0){
flag3 =0;
for(j = 0; j < no_of_frames; ++j){
temp[j] = -1;
for(k = i + 1; k < no_of_pages; ++k){
if(frames[j] == pages[k]){
temp[j] = k;
break;
}
}
}
for(j = 0; j < no_of_frames; ++j){
if(temp[j] == -1){
pos = j;
flag3 = 1;
break;
}
}
if(flag3 ==0){
max = temp[0];
pos = 0;
for(j = 1; j < no_of_frames; ++j){
if(temp[j] > max){
max = temp[j];
pos = j;
}
}
}
frames[pos] = pages[i];
faults++;
}
printf("\n");
for(j = 0; j < no_of_frames; ++j){
printf("%d\t", frames[j]);
}
}
hits = no_of_pages - faults;
printf("\n\nTotal Page Faults = %d", faults);
printf("\nTotal Page Hits = %d", hits);
printf("\n\nPress any key to continue");
getch();
back();
}
//OPTIMAL PAGE REPLACEMENT
