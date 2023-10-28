/* Consider a class called book details which stores the
 information about a book such as 
 book id integer starting from one book 
  title string 
  number of copies integer 
  price float 
  create the above class with necessary input and output functions
   and store the objects of this class in a file called bookinfo.dat 
   you need to display the details of a particular book 
   based on the book id entered by the user using the concept of random access file
    write a complete programme to implement the solution of the above given problem.*/
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class Book_details{
    static int count;
    int id;
    char title[50];
    int copies;
    float price;
    public:
    Book_details(){id=count+1;
    }
    Book_details(char name[],int c,float p):copies(c),price(p){
        strcpy(title,name);
        id=count+1;
    };
    void getdata(){
        cout<<"\nEnter the book title:";
        cin.ignore();
        cin.getline(title,50);
        cout<<"\nEnter the number of copies:";
        cin>>copies;
        cout<<"\nEnter the price:";
        cin>>price;
    }
    void display(){
        cout<<setw(4)<<left<<id<<setw(20)<<left<<title<<setw(7)<<left<<copies<<setw(8)<<price<<endl;
    }
};
int Book_details::count;
int main(){
    int n;
    do{
        cout<<"Enter the number of books:";
        cin>>n;
    }while(n<1||n>10);
    Book_details bk[n];
    for(int i=0; i<n;i++)
        bk[i].getdata();
    cout<<setw(4)<<left<<"ID"<<setw(20)<<left<<"TITLE"<<setw(7)<<left<<"COPIES"<<setw(8)<<"PRICE"<<endl;
    for(int i=0;i<n;i++)
        bk[i].display();
    cout<<endl;
    return 0;
}