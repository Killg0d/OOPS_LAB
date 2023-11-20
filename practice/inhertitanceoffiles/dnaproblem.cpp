#include<iostream>
#include<cstring>
#include <iomanip>

using namespace std;

class DNA{
    public:
        virtual int length() const=0;
        virtual void count_nucleotides() const=0;
};

class Sequence:public DNA{
    char dna[30];
    public:
        int length() const{
            int len;
            for(len=0;dna[len]!='\0';len++);
            return len;
        }
        void count_nucleotides() const{
            int a,c,g,t;
            a=c=g=t=0;
            for(int i=0;dna[i]!='\0';i++){
                if(dna[i]=='A')
                    a++;
                else if(dna[i]=='C')
                    c++;
                else if(dna[i]=='G')
                    g++;
                else   
                    t++;
            }
            cout<<"\nNucleotides:\n"<<right<<setfill(' ')<<setw(30)<<a<<" occurrences of adanine(A)\n";
            cout<<setw(30)<<c<<" occurrences of cytosine(C)\n";
            cout<<setw(30)<<g<<" occurrences of guanine(G)\n";
            cout<<setw(30)<<t<<" occurrences of thymine(T)\n";
        }
        void generateCodons(){
            char* res=new char;
            int k=0;
            for(int i=0;dna[i]!='\0';i++){
                if(i%3==0){
                    *(res+k)=' ';
                    k++;
                }
                *(res+k)=dna[i];
                k++;
            }
            *(res+k)='\0';
            cout<<"Codon: "<<res;
        }

        bool getDNA(){
            char ch;
            int i=0;
            cin>>dna;
            for(int i=0;dna[i]!='\0';i++){
                ch=toupper(dna[i]);
                switch(ch){
                    case 'A':
                    case 'C':
                    case 'G':
                    case 'T':
                            dna[i]=ch; 
                            break;
                    default: cout<<"\nInvalid character\n"<<ch;
                            return false;
                }
            }
            if(strlen(dna)<2){
                cout<<"\nDNA should be atleast 2 character long\n"; 
                return false;
            }
            return true;   
        }
        friend int operator==(Sequence d1,Sequence d2);

        friend float percentMatch(int length,int ham);

        friend ostream& operator <<(ostream&,Sequence&);

};

ostream& operator <<(ostream& out,Sequence& s){
    out<<"DNA String: "<<s.dna;
    out<<"\nString length: "<<s.length();
    s.count_nucleotides();
    s.generateCodons();
    return out;
}

int operator==(Sequence d1,Sequence d2){
    int ham=0;
    for(int i=0;d1.dna[i]!='\0';i++){
        if(d1.dna[i]!=d2.dna[i])
            ham++;
    }
    return ham;
}

float percentMatch(int length,int ham){
    return (((float)ham/length)*100);
}

int main(){
    Sequence s1,s2;
    cout<<"\nDNA sequence 1: ";
    if(!s1.getDNA())
        return 0;
    cout<<"\nDNA sequence 2: ";
    if(!s2.getDNA())
        return 0;
    if(s1.length()!=s2.length())
        cout<<"Both DNA length should match\n";
    else
    {
        cout<<right<<setfill(' ')<<setw(30)<<"Generating DNA Report"<<setw(10)<<' '<<endl;
        cout<<s1;
        cout<<endl<<setw(50)<<setfill('-')<<"\n";
        cout<<s2;
        cout<<endl<<setw(50)<<setfill('-')<<"\n";
        int hum=(s1==s2);
        cout<<"the humming distance between DNA string 1 and 2 is : "<<hum;
        cout<<endl<<"Percentage match: "<<percentMatch(10,hum)<<"%";
        cout<<endl<<setfill('-')<<setw(50);
    }
    return 0;
}