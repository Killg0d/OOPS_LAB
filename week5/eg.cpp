#include<iostream>
#include<cstring>
using namespace std;
class eg{
    int alpha;
    
    public:
    eg():alpha(0){}
    void const_function(const eg e) const{
        
        
        cout<<alpha;
    } 
};
int main() {
    eg e;
    e.const_function(e);
    return 0;
}