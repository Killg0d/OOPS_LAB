#include<iostream>
using namespace std;
class intersect{
    int a[50],size;
    public:
    void getdata(){
        cout<<"Enter the size:";
        cin>>size;
        cout<<"\nEnter the elements:";
        for(int i=0;i<size;i++)
        cin>>a[i];
    }
    void display(){
        cout<<"\nArray elements are:";
        for(int i=0;i<size;i++)
        cout<<a[i]<<"\t";
    }    
    intersect operator^(intersect ob){
        intersect temp;
        temp.size=0;
        
        for(int i=0;i<size;i++)
        for(int j=0;j<ob.size;j++){
      
            if(a[i]==ob.a[j]){
            temp.a[temp.size++]=a[i];
            
            break;
            }
        }
        return temp;
    }
};
int main(){
    intersect obj1,obj2,obj3;
    obj1.getdata();
    obj2.getdata();
    obj3=obj1^obj2;
    obj3.display();
    return 0;
}
