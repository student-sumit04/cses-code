   //what is heap
//it a complete binary tree that comes with the property of heap order property
//in the tree or heap if node is the i th index then 2*i is the left index and 2*i+1 is the
// right index and the parent is (i/2)  -->this is the 1 based indexing 



#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;

class heap{
    public:
    vt<int> arr = vt<int>(100);
    int sz=0;
    void insert(int val){
        if(sz == static_cast<int>(arr.size()) - 1){
            cout << "Heap is full" << endl;
            return;
        }
        sz=sz+1;
        int ind=sz;
        arr[ind]=val;
        while(ind>1){
            int par=ind/2;
            if(arr[par]<arr[ind]){
                swap(arr[par],arr[ind]);
                ind=par;
            }
            else{
                return ;
            }
        }
    }

    //the time complexity is O(log n)

    void deleteope(){
        if(sz==0){cout<<"NOthing to delete"<<endl;
        return ;}

        //swap first node
        arr[1]=arr[sz];
        sz--;
        int ind=1;
        while(true){
            int leftind=(2*ind);
            int rightind=(2*ind+1);
            int largest=ind;

            if(leftind<=sz && arr[largest]<arr[leftind]){
                largest=leftind;
            }
            if(rightind<=sz && arr[largest]<arr[rightind]){
                largest=rightind;
            }
            if(largest == ind){
                return;
            }

            swap(arr[ind],arr[largest]);
            ind=largest;
        }




    }
    //the time complexit is O(log n)

    void heapify(int arr[],int n ,int ind){
        int largest=ind;
        int left=2*ind;
        int right=2*ind+1;

        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest !=ind){
            swap(arr[largest],arr[ind]);
            heapify(arr,n,largest);
        }
    }
    // the time complexity is O(n)

};

int main(){
    heap maxHeap;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i=0; i<n; i++){
        int value;
        cin >> value;
        maxHeap.insert(value);
    }

    cout << "Max-heap: ";
    for(int i=1; i<=maxHeap.sz; i++){
        cout << maxHeap.arr[i] << ' ';
    }
    cout << endl;

    maxHeap.deleteope();

    cout << "After deleting the maximum element: ";
    for(int i=1; i<=maxHeap.sz; i++){
        cout << maxHeap.arr[i] << ' ';
    }
    cout << endl;

    return 0;
}