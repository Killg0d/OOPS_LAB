/*Write a C++ program to create a class called Matrix using 2-Dimensional array of
integers. Implement the following by overloading the operator == which checks the
compatibility of the two matrices to be added and subtracted. Perform the following
by overloading + and - operators. */
//tarun
//230970005
//11-09-2023
#include<iostream>
using namespace std;
class Matrix{
int arr[10][10],rows,cols;
public:Matrix():rows(0),cols(0){}
Matrix(int x,int y){
                rows=x;
                cols=y;
                }
                void get_details(void){
                        cout<<"Enter the no of rows:";cin>>rows;
                        cout<<"Enter the no of cols:";cin>>cols;
                        cout<<"Enter the elements:";
                        for(int i=0;i<rows;i++)
                                for(int j=0;j<cols;j++)
                                        cin>>arr[i][j];
                }
                bool operator==(Matrix a) const{
                    if(rows==a.rows && cols==a.cols)
                        return true;
                    else
                        return false;
                    
                }
                Matrix operator-(Matrix m2) const{
                        Matrix c(rows,cols);
                        for(int i=0;i<rows;i++){
                                for(int j=0;j<cols;j++)
                                        c.arr[i][j]=arr[i][j]-m2.arr[i][j];
                        }
                        return c;
                }
                Matrix operator+(Matrix m2) const{
                        Matrix c(rows,cols);
                        for(int i=0;i<rows;i++){
                                for(int j=0;j<cols;j++)
                                        c.arr[i][j]=arr[i][j]+m2.arr[i][j];
                        }
                        return c;
                }
                void display(){
                        cout<<"Elements are:"<<endl;
                        for(int i=0;i<rows;i++){
                                for(int j=0;j<cols;j++)
                                        cout<<arr[i][j]<<"\t";
                        cout<<endl;
                        }
                        cout<<endl;
                }
};
int main(){
        Matrix m1,m2,m3,m4;
        m1.get_details();
        m2.get_details();
        m1.display();
        m2.display();
        if(m1==m2){
            m3=m1+m2;
            m4=m1-m2;
            m3.display();
            m4.display();
        }
        else
            cout<<"Matrices are incompatible";
        cout<<endl;
        return 0;
}
   