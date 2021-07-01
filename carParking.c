#include
#include
#include
#define A 10
using namespace std;
static int total;
class car
{
private:
 int mm,dd,yyyy;
 int h,m,s; int cn;
public:
 void entry()
 {
    cout<<"ENTER THE CAR NUMBER                            ::";
    cin>>cn;
    cout<<"ENTER THE ENTRY DATE:   MM DD YYYY              ::";
    cin>>mm>>dd>>yyyy;
    cout<<"ENTER THE ENTRY TIME:   HH MM SS(24 HOUR FORMAT)::";
    cin>>h>>m>>s;
    ofstream
    fout.open("data.txt",ios::app|ios::binary);
    fout.write((char*)(this),sizeof(*this));
    }
    void entry_data()
    {
        if(get_total()<10)
        {
            entry();
        }
        else
        {
            cout<<"NO VACENT SPACE IN THE PARKING"<<endl;
            cout<<"********************************************************"<<endl;
            total--;
        }
    }


   void exit()
    {
        raj:
    int mm1,dd1,yyyy1;
    int h1,m1,s1;
    int cn1;
    cout<<"ENTER THE CAR NUMBER                           ::";
    cin>>cn1;
    cout<<"ENTER THE EXIT DATE:   MM DD YYYY              ::";
    cin>>mm1>>dd1>>yyyy1;
    cout<<"ENTER THE EXIT TIME:   HH MM SS(24 HOUR FORMAT)::"<<endl;
    cin>>h1>>m1>>s1;
    ifstream fin;
    fin.open("data.txt",ios::binary);
    fin.seekg(0,ios::end);
    int count=fin.tellg()/sizeof(*this);
    int rks,raj=0;
    for(int i=0;i<count;i++)
    {
        fin.seekg((i)*sizeof(*this));
        fin.read((char*)(this),sizeof(*this));
        if(cn1==cn)
        {
            rks=i;

    if(yyyy1<yyyy)
    {
        cout<<"********************************************************"<<endl;
        cout<<"INVALID DATE AND TIME ENTERED"<<endl;
        cout<<"REENTER DATE AND TIME"<<endl;
        cout<<"********************************************************"<<endl;
        raj=1;
      goto raj;
    }
    double x=(((yyyy1-yyyy)*365*24)+((mm1-mm)*30*24)+((dd1-dd)*24)+(h1-h)+((m1-m)/60)+((s1-s)/3600));
    double charge;
      if (x <= 3)
            charge = 2;
       else if (x >24)
            charge = 8*((x)/24);
       else if (x > 3)
            charge = 2 + (x - 3) * (.5);
    cout<<"***********************************************************************************************************"<<endl;
    cout<<"CAR NUMBER"<<"\t"<<"ENTERY DATE"<<"\t"<<"ENTERY TIME"<<"\t"<<"EXIT DATE"<<"\t"<<"EXIT TIME"<<"\t"<<"TOTAL PARKING CHARGE"<<endl;
    cout<<cn<<setw(A+5)<<mm<<"-"<<dd<<"-"<<yyyy<<setw(A+2)<<h<<":"<<m<<":"<<s<<setw(A)<<mm1<<"-"<<dd1<<"-"<<yyyy1<<setw(A)<<h1<<":"<<m1<<":"<<s1<<setw(A)<<"$"<<charge<<endl;
    cout<<"***********************************************************************************************************"<<endl;
    fstream ftin;
    ftin.open("temp.txt",ios::out|ios::binary);
    fin.seekg(0);
    for(int j=0;j<count;j++)
    {
     fin.read((char*)(this),sizeof(*this));
     if(j==rks)
        continue;
     ftin.write((char*)(this),sizeof(*this));
    }

    fin.close();
    ofstream fout;
    fout.open("data.txt",ios::binary);
    ftin.close();
    ftin.open("temp.txt",ios::in|ios::binary);
    for(int k=0;k<count-1;k++)
    {
        ftin.read((char*)(this),sizeof(*this));
        fout.write((char*)(this),sizeof(*this));
    }
    ftin.close();
    remove("temp.txt");
    raj=1;
    }
    }

    if(raj==0)
       {
            cout<<"********************************************************"<<endl;
            cout<<"*************THIS CAR IS NOT PARKED HERE****************"<<endl;
            cout<<"********************************************************"<<endl;
            total++;
        raj=0;
        }
    }
/* double calculate(double x) { double charge; if (x <= 3) charge = 2; else if (x >24) charge = 8*((x)/24); else if (x > 3) charge = 2 + (x - 3) * (.5); return charge; }*/

    void show_record()
    {
    ifstream fin;
    fin.open("data.txt",ios::in|ios::binary);
    fin.seekg(0,ios::end);
    int count=fin.tellg()/sizeof(*this);
    cout<<"********************************************************"<<endl;
    cout<<"*****************RECORD IS SHOWN BELOW******************"<<endl;
    cout<<"********************************************************"<<endl;

    cout<<"CAR NUMBER"<<"\t"<<"ENTERY DATE"<<"\t"<<"ENTERY TIME"<<"\t"<<endl<<endl;
    for(int i=0;i<count;i++)
    {
        fin.seekg((i)*sizeof(*this));
        fin.read((char*)(this),sizeof(*this));
        cout<<cn<<setw(A+5)<<mm<<":"<<dd<<":"<<yyyy<<setw(A-1)<<h<<":"<<m<<":"<<s<<"\t"<<endl;
    }
    cout<<"********************************************************"<<endl;
    cout<<"TOTAL SPACE VACANT IN THE PARKING::"<<10-(get_total())<<endl;
    }
    operator++(int)
   {
       total=get_total();
       total++;
   }
    operator--(int)
   {
       total=get_total();
       total--;
   }
   int return_total()
   {
       return(total);
   }
   int get_total()
   {
    ifstream fin;
    fin.open("data.txt",ios::in|ios::binary);
    fin.seekg(0,ios::end);
    int count=fin.tellg()/sizeof(*this);
    return(count);
   }
};

int main()
 {
  car c;
   int a;
    char y='y';
     while(y=='y'||y=='Y')
      {
       cout<<""<<endl;
       cout<<"DO SELECT ONE FROM GIVEN OPTION"<<endl;
        cout<<"ENTER 1 FOR ENTRY ::"<<endl;
         cout<<"ENTER 2 FOR EXIT ::"<<endl;
          cout<<"ENTER 3 FOR SHOW RECORD::";
          cin>>a; cout<<"***************"<<endl;
          switch(a)
           {
            case 1:
            {
             c++;
             c.entry_data();
             cout<<"TOTAL NUMBER OF CAR IN THE GARAGE::"<<c.return_total()<<endl;
             break;
            }
            case 2:
             {
              c--;
              c.exit();
              cout<<"TOTAL NUMBER OF CAR LEFT IN THE GARAGE::"<<c.return_total()<<endl;
              break;
             }
             case 3:
             {
              c.show_record();
              break;
             }
             default:
             {
              cout<<"ENTER THE VALID NUMBER"<<endl;
              break;
             }
              cout<<"DO YOU WANT TO CONTINUE IF YES ENTER (Y/y)"<<endl;
              cin>>y;
             }
             }
             return 0;

              }
