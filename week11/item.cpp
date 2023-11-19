// Write a C++ program to create an item database and store the following information:
// i. Item name ii. Item code iii. Unit price iv. Quantity on hand
// Then implement the following:
// i. Add a new record
// ii. Modify the existing record
// iii. Delete a record.
// Use random access file concept. The item code should be generated automatically.
#include <iostream>
#include <fstream>
using namespace std;
class Item
{
    int itemcode;
    char name[50];
    float unitprice, quantity;

public:
    static int Itemcount();
    void storeItem();
    void readItem(int);
    friend istream &operator>>(istream &, Item &);
    friend ostream &operator<<(ostream &, Item &);
};
int Item::Itemcount()
{
    ifstream ifile("itemdb.txt");
    ifile.seekg(0, ios::end);
    return (ifile.tellg() / sizeof(Item));
}
istream &operator>>(istream &in, Item &i)
{
    int n = Item::Itemcount();
    cout << "Enter item details for item number :" << ++n << endl;
    i.itemcode = n;
    
    cout << "Enter item name : ";
    in >> i.name;
    cout << "Enter unit price : ";
    in >> i.unitprice;
    cout << "Enter quantity : ";
    in >> i.quantity;
    return in;
}
ostream &operator<<(ostream &out, Item &i)
{
    cout << "\nName of item : ";
    out << i.name;
    cout << "\nUnit Price : " ;
    out<< i.unitprice;
    cout << "\nQuantity : ";
    out << i.quantity;
    return out;
}
void Item::readItem(int i)
{
    ifstream infile("itemdb.txt");
    infile.seekg(i * sizeof(Item), ios::beg);
    infile.read((char *)this, sizeof(Item));
}
void modifyRecord()
{
    int id;
    cout << "\nEnter the id:";
    cin >> id;
    if (id > Item::Itemcount())
    {
        cout << "Id not found!";
        return;
    }
    Item temp;
    temp.readItem(id - 1);
    cout << temp;
    cout << "\nModify values:";
    cin >> temp;
    fstream file("itemdb.txt", ios::in | ios::out);
    file.seekp((id - 1) * sizeof(temp), ios::beg);
    file.write((char *)&temp, sizeof(temp));
    cout << "\nData Modified";
}
void Item::storeItem()
{
    ofstream outFile("itemdb.txt", ios::out | ios::app);
    if (!outFile)
    {
        cout << "Error in opening output file";
        exit(1);
    }
    outFile.write((char *)this, sizeof(Item));
    outFile.close();
}

void storeItem(Item i)
{
    ofstream outFile("itemdb.txt", ios::out | ios::app);
    if (!outFile)
    {
        cout << "Error in opening output file";
        exit(1);
    }
    outFile.write((char *)&i, sizeof(Item));
    outFile.close();
}
void read()
{
    int id;
    cout << "\nEnter the id:";
    cin >> id;
    if (id > Item::Itemcount())
    {
        cout << "Id not found!";
        return;
    }
    Item temp;
    temp.readItem(id - 1);
    cout << temp;
}
void deleteRecord()
{
    int id;
    cout << "\nEnter the id:";
    cin >> id;
    if (id > Item::Itemcount())
    {
        cout << "Id not found!";
        return;
    }
    ifstream iofile("itemdb.txt");
    ofstream tmp("temp.txt");
    Item temp;
    if (!iofile || !tmp)
    {
        cout << "\nFile not found.";
        return;
    }
    int count = 0;
    while (iofile.read((char *)&temp, sizeof(Item)))
    {
        count++;
        if(count!=id)
            tmp.write((char *)&temp, sizeof(Item));
        else cout<<"\nRecord deleted";
        if (iofile.eof())
        {
            break;
        }
    }
    iofile.close();
    tmp.close();
    remove("itemdb.txt");
    rename("temp.txt", "itemdb.txt");
}
int main()
{
    int ch;
    Item *itm;
    do
    {
        cout << "\n\n\tMenu" << endl;
        cout << "1.Add new item." << endl;
        cout << "2.Display Item." << endl;
        cout << "3.Modify Item." << endl;
        cout << "4.Delete Item." << endl;
        cout << "5.Exit." << endl;
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            itm = new Item();
            cin >> *itm;
            itm->storeItem();
            delete itm;
            break;
        case 2:
            read();
            break;
        case 3:
            modifyRecord();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            cout << "\nExit\n";
            break;
        default:
            cout << "\nINVALID CHOICE\n";
            break;
        }
    } while (ch != 5);
    
    
    cout << endl;
    return 0;
}
