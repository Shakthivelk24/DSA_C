#include <stdio.h>
#include <stdlib.h>
int bS(int arr[],int l,int r,int key){
    if(l>r){
        return -1;
    }
    int mid = l+(r-l)/2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[mid]>key)
        return bS(arr,l,mid-1,key);
    return bS(arr,mid+1,r,key);
}
int main(){
   int n,key;
   printf("Enter the number of element in sorted array : ");
   scanf("%d",&n);
   int arr[n];
   printf("Enter %d sorted element : \n");
   for(int i=0;i<n;i++){
     scanf("%d",&arr[i]);
   }
   printf("Enter the element to search : ");
   scanf("%d",&key);
   int res = bS(arr,0,n-1,key);
   if(res != -1){
    printf("The element is found in %d position\n",res+1);
   }
   else{
    printf("The element is not found");
   }
   return 0;

}





































