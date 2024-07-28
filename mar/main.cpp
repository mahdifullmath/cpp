#include <iostream>
using namespace std;
void intersection(float arr1[], float arr2[], float arr3[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
         if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
         {   cout << arr1[i] << " ";   i++; j++; k++; }
         else if (arr1[i] < arr2[j])
             i++;
         else if (arr2[j] < arr3[k])
             j++;
         else
             k++;
    }
}
void bubble_sort(float arr[], int n)
{
	int i, temp, flag = 1;
	while (flag == 1)
	{
		flag = 0;
		for (i = 0; i < n - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = 1;
			}
		}
	}
	return;
}
int main()
{
    int n1,n2,n3,i;
    float *arr1;
    cin>>n1;
    arr1 = new float[n1];
    float *arr2;
    cin>>n2;
    arr2 = new float[n2];
    float *arr3;
    cin>>n3;
    arr3 = new float[n3];
    cout<<"Enter the array 1 :"<<'\n';
    for(i=0;i<n1;++i)
    {
        cin>>*(arr1+i);
    }
    cout<<"Enter the array 2 :"<<'\n';
    for(i=0;i<n2;++i)
    {
        cin>>*(arr2+i);
    }
    cout<<"Enter the array 3 :"<<'\n';
    for(i=0;i<n3;++i)
    {
        cin>>*(arr3+i);
    }
    bubble_sort(arr1,n1);
    bubble_sort(arr2,n2);
    bubble_sort(arr3,n3);
    cout<<"similar elements are : "<<endl;
    intersection(arr1,arr2,arr3,n1,n2,n3);
    getchar();
    return 0;
}
