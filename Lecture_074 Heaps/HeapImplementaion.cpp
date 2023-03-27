#include<iostream>
//#include<string>
//#include<vector>

// heap is a complete binary tree
// left and right node have values less then root node
using namespace std;
class heap{
    public:
    int *arr;
    int size;
    heap(){
        size=0;
        arr=new int[100];
    }

   //inserting elements 
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else return;
        }
    }

    //deleting element
    void deletefromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        // deleteing
        arr[1]=arr[size];
        size--;
        //taking node to its correct position
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<size && arr[leftIndex]>arr[i]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[rightIndex]>arr[i]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return;
            }
        }
    }

 
    //printing
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

   //heapify
    void heapify(int *arr,int n,int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;

        if(left<=n && arr[largest] < arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest] < arr[right]){
            largest=right;
        }
        // checking if the largest is updated or note
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }

    //heapsort
    void heapsort(int arr[],int n){
        int size=n;
        while(size>1){
            // step 1
            swap(arr[size],arr[1]);
            size--;
            heapify(arr,size,1);
        }
    }


int main(){
    heap h;
    h.insert(1); h.insert(3); h.insert(2); h.insert(5); h.print();
    h.deletefromHeap();
    h.print();

    //heap creation
    int arr[6]={-1,54,53,55,52,50};   
    int n=6;
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
    cout<<"printing array after heapify"<<endl;
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }

    //heapsort
    heapsort(arr,n);
    cout<<"printing array heap sort"<<endl;
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}