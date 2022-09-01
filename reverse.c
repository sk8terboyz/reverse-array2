#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int nums[10];
  int i = 0;
  int file;
  int wr;
  char buffer[10] = {0};

  printf("Enter 10 numbers for the array\n");

  while(i != 10)
  {
    scanf("%d", &nums[i]);
    i++;
  }

  //opening file to write to
  file = open("reverseOrder.txt", O_WRONLY | O_CREAT, 0644);

  printf("\nYour numbers in reverse order are : ");
  //printing files to console and file
  while(i > 0)
  {
    //convert numbers to ASCII
    sprintf(buffer, "%d", nums[i]);
    i--;
    if(i == 0)
    {
      printf("%i", nums[i]);
    }
    else
    {
      printf("%i, ", nums[i]);
    }
    wr = write(file, nums, sizeof(nums));
  }
  //move onto the next line
  printf("\n");
  //close file
  close(file);

  return 0;
}
