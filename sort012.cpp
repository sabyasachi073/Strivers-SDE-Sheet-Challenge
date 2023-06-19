#include <bits/stdc++.h> 

// Using Dutch National flag algorithm
void sort012(int *arr, int n)
{
   int low=0;
   int mid=0;
   int high=n-1;

   while(mid<=high) {
      if(arr[mid]==0) {
         swap(arr[mid], arr[low]);
         mid++;
         low++;
      }

      else if(arr[mid]==1) {
         mid++;
      }

      else {
         swap(arr[mid], arr[high]);
         high--;
      }
   }
}

/*
// Using count sort
void sort012(int *arr, int n)
{
   int count0 = 0;
   int count1 = 0;
   int count2 = 0;

   for(int i=0; i<n; i++) {
      if(arr[i]==0)
         count0++;
         
      if(arr[i]==1)
         count1++;

      if(arr[i]==2)
         count2++;
   }

   int i;
   for(i=0; i<count0; i++) {
      arr[i] = 0;
   }

   for(; i<count0+count1; i++) {
      arr[i] = 1;
   }
   
   for(; i<count0+count1+count2; i++) {
      arr[i] = 2;
   }
}
*/
