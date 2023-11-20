#include <iostream>
#include <fstream>
#include <cstring>
#include <typeinfo>
using namespace std;

const int MAX=1;
enum caketype
{
    Tranquil,
    Bash,
    Wedding
};

enum weight
{
    half,
    one,
    two,
    four,
    six
};

enum flavours
{
    Vanilla,
    Butterscotch,
    Chocolate,
    RedVelvet,
    Pista
};

void findtype(caketype c)
{
    switch (c)
    {
    case Tranquil:
        cout << "Vanilla";
        break;
    case Bash:
        cout << "Bash";
        break;
    case Wedding:
        cout << "Vanilla";
        break;
    default:
        break;
    }
}
void findflavour(flavours f)
{
    switch (f)
    {
    case Vanilla:
        cout << "Vanilla";
        break;
    case Butterscotch:
        cout << "Butterscotch";
        break;
    case Chocolate:
        cout << "Chocolate";
        break;
    case RedVelvet:
        cout << "RedVelvet";
        break;
    case Pista:
        cout << "Pista";
        break;
    default:
        cout << "Unknown flavour";
    }
}
void findweight(weight w)
{
    switch (w)
    {
    case half:
        cout << "0.5";
        break;
    case one:
        cout << "1";
        break;
    case two:
        cout << "2";
        break;
    case four:
        cout << "4";
        break;
    case six:
        cout << "6";
        break;
    default:
        cout << "Unknown Weight";
    }
}

class Cake
{
    int orderno;
    char name[20];
    int custno;
    caketype c;
    flavours f;
    weight w;
    float quantity;
    float price;
    char date[10];
    char time[6];

    public:
    weight getweight()
    {
        return w;
    }
    flavours getflavour()
    {
        return f;
    }
    caketype gettype()
    {
        return c;
    }
    int getorderno()
    {
        return orderno;
    }

    const char *getname()
    {
        return name;
    }

    float getquantity()
    {
        return quantity;
    }

    int getcustno()
    {
        return custno;
    }

    float getprice()
    {
        return price;
    }

    const char *getdate()
    {
        return date;
    }

    const char *gettime()
    {
        return time;
    }
    void chooseFlavor()
    {
        int i;

        cout << "Enter the flavor choice (0 for Vanilla, 1 for Butterscotch, 2 for Chocolate, 3 for RedVelvet, 4 for Pista): ";
        cout << "\nFlavour: ";
        cin >> i;

        switch (i)
        {
        case Vanilla:
            f = Vanilla;
            break;
        case Butterscotch:
            f = Butterscotch;
            break;
        case Chocolate:
            f = Chocolate;
            break;
        case RedVelvet:
            f = RedVelvet;
            break;
        case Pista:
            f = Pista;
            break;
        default:
            cout << "Unknown flavour" << endl;
            break;
        }
    }
    void chooseWeight()
    {
        int weightChoice;

        cout << "Enter the weight choice (0 for Half, 1 for One, 2 for Two, 3 for Four, 4 for Six): ";
        cin >> weightChoice;

        switch (weightChoice)
        {
        case half:
            w = half;
            break;
        case one:
            w = one;
            break;
        case two:
            w = two;
            break;
        case four:
            w = four;
            break;
        case six:
            w = six;
            break;
        default:
            cout << "Unknown weight" << endl;
        }
    }
    void settype()
    {
        int type;

        cout << "Enter the type (0 for Tranquil Temptation, 1 for Birthday Bash, 2 for Wishful Wedding): ";
        cin >> type;

        switch (type)
        {

        case Tranquil:
            type = Tranquil;
            break;
        case Bash:
            type = Bash;
            break;
        case Wedding:
            type = Wedding;
            break;

        default:
            cout << "Unknown type" << endl;
        }
    }
    virtual void setcake()
    {
        cout << "Enter the cakes details:\nOrder number: ";
        cin >> orderno;
        cout << "\nName of the cake: ";
        cin >> name;
        if (!strcmp(name, "0"))
        {
            exit(0);
        }
        cout << "\nCustomer's number: ";
        cin >> custno;
        settype();
        chooseFlavor();
        chooseWeight();
        cout << "\nQuantity: ";
        cin >> quantity;
        cout << "\nPrice per kg: Rs";
        cin >> price;
        cout << "\nDate (dd/mm/yyyy): ";
        cin >> date;
        cout << "\ntime (hh:mm): ";
        cin >> time;
    }

    virtual int computePrice() = 0;
    virtual void printBill() = 0;

};
class Traquil : public Cake
{
    float napkins;
    int noofnapkins;
    int noofwrapping;
    float wrapping;

public:
    Traquil()
    {
        napkins = 2;
        wrapping = 10.5;
    }
    void setnapkins()
    {
        cout << "\nNumber of Napkins: ";
        cin >> noofnapkins;
    }
    void setwrapping()
    {
        cout << "\nNumber of wrappings: ";
        cin >> noofwrapping;
    }
    virtual int computePrice()
    {
        int total = 0;
        total += getquantity() * getprice() + noofnapkins * napkins + noofwrapping * wrapping;
        return total;
    }
    void setcake() override
    {
        Cake::setcake();
        setnapkins();
        setwrapping();
    }
    virtual void printBill()
    {
        cout << "\n\t\tCake Loft";
        cout << "\nDate:" << getdate() << "\t\t\t\tTime of Order" << gettime();
        cout << "\n\t\tCake Type";
        findtype(gettype());
        cout << "\n\t\tOrder no:" << getorderno();
        cout << "\n\t\tCustomer number" << getcustno();
        cout << "\n\tCustomer name:" << getname();
        cout << "\n\tQuantity ordered:" << getquantity();
        cout << "--------------------------------------------------------------";
        cout << "\n\tSerial#\t Name of Cake \tFlavour Weight (in kgs)\t Unit Price";
        cout << "\n1\t\t" << getname();
        findflavour(getflavour());
        cout << "\t" << getprice();
        cout << "\t\t\t\tTotal" << computePrice();
    }
};
int main()
{
    Cake *arr[MAX];
    int total;
    for (int i = 0; i < MAX; i++)
    {
        int type;

        cout << "Enter the type (0 for Tranquil Temptation, 1 for Birthday Bash, 2 for Wishful Wedding): ";
        cin >> type;
        
        switch (type)
        {

        case Tranquil:
            arr[i] = new Traquil();
            arr[i]->setcake();
            arr[i]->printBill();
            total+=arr[i]->computePrice();
            break;
        case Bash:
            arr[i] = new Traquil();
            arr[i]->setcake();
            arr[i]->printBill();
            total+=arr[i]->computePrice();
            break;
        case Wedding:
            arr[i] = new Traquil();
            arr[i]->setcake();
            arr[i]->printBill();
            total+=arr[i]->computePrice();
            break;

        default:
            cout << "Unknown type" << endl;
        }
    }
    cout<<total;
    return 0;
}
