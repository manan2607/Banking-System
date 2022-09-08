#include<iostream>
#include<string>
#include<fstream>

using namespace std;
class account
{
    private:
    int accnumber;
    string fname;
    string lname;
    int balance;
    int password;
    string f[25];
    string l[25];
    int b[25];
    int p[25];

    public:
    account()
    {
        ifstream in;
        int i=0;
        in.open("data.txt");
        if (!in)
        {
            ofstream file("data.txt");
            ifstream in;
            in.open("data.txt");
        } 
        while(in.eof()==0)
        {
            int x;
            x=i%4;
            switch(x)
            {
                case 0:
                {
                    getline(in,fname);
                    f[(i/4)]=fname;
                    i++;
                    break;
                }
                case 1:
                {
                    getline(in,lname);
                    l[((i-1)/4)]=lname;
                    i++;
                    break;
                }
                case 2:
                {
                    int num1;
                    string bal;
                    getline(in,bal);
                    num1 = stoi(bal);
                    b[((i-2)/4)]=num1;
                    i++;
                    break;
                }
                case 3:
                {
                    int num2;
                    string pass;
                    getline(in,pass);
                    num2 = stoi(pass);
                    p[((i-3)/4)]=num2;
                    i++;
                    break;
                }
            }
        }
        in.close();
    }

    void open_account()
    {
        cout<<"Enter your Account Number: "<<endl;
        cin>>accnumber;

        cout<<"Enter your First name: "<<endl;
        cin>>fname;
        f[(accnumber-1)]=fname;

        cout<<"Enter your Last name: "<<endl;
        cin>>lname;
        l[(accnumber-1)]=lname;

        cout<<"Enter Your Deposit Amount: "<<endl;
        cin>>balance;
        b[(accnumber-1)]=balance;

        cout<<"Set Your Password: "<<endl;
        cin>>password;
        p[(accnumber-1)]=password;
    }

    void get_data()
    {
        cout<<"Enter Your Account Number: ";
        cin>>accnumber;
        cout<<endl;

        int temp1, temp2;
        cout<<"Enter Your Password: ";
        cin>>temp1;
        cout<<endl;
        temp2=p[(accnumber-1)];
        if(temp2==temp1)
        {
            cout<<"Your Name: "<<f[(accnumber-1)]<<" "<<l[(accnumber-1)]<<endl;
            cout<<"Your Current Balance: "<<b[(accnumber-1)]<<endl;
            cout<<endl;
        }
        else
        {
            cout<<"Invalid Password.";
            cout<<endl;
        }
    }

    void deposit_amt()
    {
        cout << "Enter Your Account Number: ";
        cin >> accnumber;
        cout << endl;

        
        int temp1, temp2;
        cout<<"Enter Your Password: ";
        cin>>temp1;
        cout<<endl;
        temp2=p[(accnumber-1)];
        if(temp2==temp1)
        {
        int amt1, amt2;
        cout << "Enter Your Amount To Be Deposited : ";
        cin >> amt1;
        cout << endl;
        amt2 = b[(accnumber - 1)];
        amt2=amt1+amt2;
        b[(accnumber - 1)] = amt2;
        cout<<"Your Amount deposit was Successful."<<endl;
        cout<<"Your Current Balance is: "<<b[(accnumber-1)]<<endl;
        cout<<endl;
        }
        else
        {
            cout<<"Invalid Password."<<endl;
            cout<<endl;
        }
    }

    void wth_amt()
    {
        cout<<"Enter Your Account Number: ";
        cin>>accnumber;
        cout<<endl;

        int temp1, temp2;
        cout<<"Enter Your Password: ";
        cin>>temp1;
        cout<<endl;
        temp2=p[(accnumber-1)];
        if(temp2==temp1)
        {
            cout<<"Your Name: "<<f[(accnumber-1)]<<" "<<l[(accnumber-1)]<<endl;
            cout<<"Your Current Balance: "<<b[(accnumber-1)]<<endl;
            cout<<"Withdrawable Amount: "<<b[(accnumber-1)]-500<<endl;
            cout<<endl;
            int amt1, amt2;
            cout << "Enter Your The Amount To Be Withdraw : ";
            cin >> amt1;
            cout << endl;
            amt2 = b[(accnumber - 1)];
            amt2 = amt2-amt1;
            if(amt2>=500)
            {b[(accnumber - 1)] = amt2;
            cout<<"Your Current Balance is: "<<b[(accnumber-1)]<<endl;
            cout<<endl;}
            else
            {cout<<"Insufficient Balance"<<endl;}
        }
        else
        {
            cout<<"Invalid Password."<<endl;
            cout<<endl;
        }
    }

    void change_pass()
    {
        cout<<"Enter Your Account Number: ";
        cin>>accnumber;
        cout<<endl;

        int temp1, temp2, temp3;
        cout<<"Enter Your Password: ";
        cin>>temp1;
        cout<<endl;
        temp2=p[(accnumber-1)];
        if(temp2==temp1)
        {
            cout<<"Enter Your New Password: ";
            cin>>temp3;
            cout<<endl;
            p[(accnumber-1)]=temp3;
            cout<<"Password Change Successful."<<endl;
            cout<<endl;
        }
        else
        {
            cout<<"Invalid Password.";
            cout<<endl;
        }
    }

    ~account()
    {
        int i=0;
        int n=25;
        ofstream out;
        out.open("data.txt");
        while(i<n)
        {
            out<<f[i]<<endl;
            out<<l[i]<<endl;
            out<<b[i]<<endl;
            out<<p[i]<<endl;
            i++;
        }
        out.close();
    }
};

int main()
{
    account A1;
    int x;
    cout<<"Welcome To Banking System"<<endl;
    cout<<"1.Open Account"<<endl;
    cout<<"2.Balance Enquiry"<<endl;
    cout<<"3.Deposit"<<endl;
    cout<<"4.Withdraw"<<endl;
    cout<<"5.Change Password"<<endl;
    cout<<"6.Quit"<<endl;
    cout<<"Select an option: "<<endl;
    cin>>x;

    switch(x)
    {
        case 1:
        {
            A1.open_account();
            cout<<"Your account opening was successful."<<endl;
            cout<<endl;
            break;
        }
        case 2:
        {
            A1.get_data();
            break;
        }
        case 3:
        {
            A1.deposit_amt();
            break;
        }
        case 4:
        {
            A1.wth_amt();
            break;
        }
        case 5:
        {
            A1.change_pass();
            break;
        }
        case 6:
        {
            break;
        }
    }    
}