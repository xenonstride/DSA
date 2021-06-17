#include <iostream>
#define MAX 10
using namespace std;

class Array{
    private:
        int *arr;
        int max=MAX,n=0;

        //this is needed in C because array out of bounds gives an error in C
        //But it is not needed in C++ because : https://stackoverflow.com/questions/1239938/accessing-an-array-out-of-bounds-gives-no-error-why
        // instead you could only just increase the value of max
        void increaseSize(){
            int *newarr;
            newarr=new int[n*2];
            for(int i=0;i<n;i++){
                newarr[i]=arr[i];
            }
            arr=newarr;
            max=n*2;
            cout<<endl<<"increased size"<<endl;
        }

        //same explanation as above
        void decreaseSize(){
            int *newarr;
            newarr=new int[max/2];
            for(int i=0;i<n;i++){
                newarr[i]=arr[i];
            }
            arr=newarr;
            max=max/2;
            cout<<endl<<"decreased size"<<endl;
        }

        void checkSize(){
            if (n==max)
                increaseSize();
            else if(n==max/4)
                decreaseSize();
        }

    public:
        Array(){
            arr=new int[MAX];
        }

        int size(){
            return n;
        }

        int capacity(){
            return max;
        }

        int is_empty(){
            return n>0?n:0;
        }

        int at(int i){
            return arr[i];
        }

        void printArray(){
            cout<<endl<<"[ ";
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"]"<<endl;
        }

        void push(int x){
            checkSize();
            arr[n++]=x;
        }

        void insert(int index, int x){
            if(index>n-1) {
                cout<<endl<<"Not Allowed to insert at index greater than "<<n-1;
                return;
            }
            checkSize();
            for(int i=n-1;i>=index;i--){
                arr[i+1]=arr[i];
            }
            arr[index]=x;
            n++;
        }

        void prepend(int x){
            checkSize();
            for(int i=n-1;i>=0;i--){
                arr[i+1]=arr[i];
            }
            arr[0]=x;
            n++;
        }

        int pop(){
            checkSize();
            return arr[--n];
        }

        void removeAtIndex(int index){
            for(int i=index;i<n-1;i++){
                arr[i]=arr[i+1];
            }
            n--;
            checkSize();
        }

        void remove(int x){
            for(int i=0;i<n;i++){
                if(arr[i]==x)
                    removeAtIndex(i);
            }
            checkSize();
        }

        int find(int x){
            for(int i=0;i<n;i++){
                if(arr[i]==x)
                    return i;
            }
            return -1;
        }
};

void arrdetails(Array a){
    cout<<endl<<"Array : ";
    a.printArray();
    cout<<"Size : "<<a.size()<<"       "<<"Max : "<<a.capacity();
}

int main(){
    Array a1;

    for(int i=0;i<20;i++){
        a1.push(i);
    }
    arrdetails(a1);

    cout<<endl<<"at 6 index : "<<a1.at(6)<<endl;
    if(!a1.is_empty()) cout<<"Empty"<<endl;
    else cout<<"not empty"<<endl;

    a1.insert(14,8008);
    a1.insert(5,588);
    arrdetails(a1);

    cout<<endl<<a1.pop();
    cout<<endl<<a1.pop();

    a1.prepend(999);
    a1.push(654);
    a1.push(64);
    a1.push(34);
    a1.push(83);
    a1.push(984);
    arrdetails(a1);

    a1.removeAtIndex(18);
    a1.remove(999);
    arrdetails(a1);

    cout<<endl<<"Found 34 at : "<<a1.find(34);
    cout<<endl<<"Found 999 at : "<<a1.find(999);
    cout<<endl<<"Found 10 at : "<<a1.find(10);
    cout<<endl<<"Found 1000000 at : "<<a1.find(10000000);

    arrdetails(a1);
    
}