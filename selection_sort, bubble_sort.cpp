#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(int arr[], int len) {
    cout << "-------- selection_sort --------\n";
    int i;
    int j;
    int min;
    int loc;

   for(i=0; i<len; i++){
      min = arr[i];
      loc = i;
      for(j=i+1; j<len; j++){
         if(min > arr[j]){
            min = arr[j];
            loc = j;
         }
      }
      swap(arr[i], arr[loc]);

      cout << "i = " << i << "\t";
      cout << "j = " << j << "\t";
      cout << "min = " << min << "\t";
      cout << "location = " << loc << "\t" << "Result = ";

      for(int i=0; i<len; i++) {
         cout << arr[i] << " ";
      }
      cout << endl;
   }

   cout << "Final selection_sort = ";
   for(int i=0; i<len; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
   cout << endl;
}

void bubble_sort(int arr[], int len) {
    cout << "-------- bubble_sort --------\n";
    int i;
    int j;

   for(i=0; i<len; i++) {
      for(j=0; j<len-i-1; j++) {
         if(arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);

            cout << "i = " << i << "\t";
            cout << "j = " << j << "\t" << "Result = ";
            for(int i=0; i<len; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
         }
      }
   }
   cout << "Final Bubble_sort = ";
   for(int i=0; i<len; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main(void) {
   int arr[8] = {4,7,1,3,2,8,6,5};
   int arr2[8] = {4,7,1,3,2,8,6,5};
   int len = 8;

   selection_sort(arr, len);
   bubble_sort(arr2, len);
}