/*group f file 1 done */
/*#include <iostream>
#include<fstream> //use for i/o opereation on files 
#include<iomanip> //arrange data in columnwise manner
using namespace std;

void addstudent(){
    ofstream of;
    of.open("db.txt",ios::app);
    string name,rn,div,add;
    cout<<"enter student name :"<<endl;
    cin>>name;
    cout<<"enter student roll no :"<<endl;
    cin>>rn;
    cout<<"enter student div :"<<endl;
    cin>>div;
    cout<<"enter student address :"<<endl;
    cin>>add;
    of<<left<<setw(20)<<rn<<setw(20)<<name<<setw(20)<<div<<setw(20)<<add<<endl;
    of.close();
    cout<<"student added successfully "<<endl;
}
void deletestudent(){
    ifstream f;
    f.open("db.txt");
    string line,rn;
    cout<<"\nenter student roll no for searching :";
    cin>>rn;

    string data;
    while(getline(f,line)){
        if(line.find(rn)==string::npos){       //matlab line me roll no nhi hain to data me add karo
           data+=line;
           data+="\n";
        }

    }
    f.close();
    
    ofstream f2;  //open karo firse aur saved data copy karo firse db me
    f2.open("db.txt",ios::out);
    f2<<data;
    f2.close();

}

void searchstudent(){
    ifstream f;
    f.open("db.txt");
    string line,rn;
    cout<<"\nenter student roll no for searching :";
    cin>>rn;
    bool check=false;
    while(getline(f,line)){
        if(line.find(rn)!=string::npos){
            cout<<"students details ........"<<endl;
            cout<<line<<endl;
            check=true;
            break;
        }

    }
    f.close();
    if(check==false){
        cout<<"student not found !"<<endl;
    }

}

void printstudent(){
    ifstream f;
    f.open("db.txt");
    string line;
    cout<<"printing file data ......."<<endl;

    while(getline(f,line)){
        cout<<line<<endl;
    }
    cout<<"printing completed ......."<<endl;
    f.close();


}
int main(){
    ofstream f;
    f.open("db.txt",ios::out);
    f<<left<<setw(20)<<"rollno"<<setw(20)<<"name"<<setw(20)<<"div"<<setw(20)<<"address"<<endl;;
    f.close();
    int ch;
    while(ch!=-1){
        cout<<"\nEnter |1.Add Student |2.Delete Student |3.Search Student |4.Print Data |5.Exit :"<<endl;
        cin>>ch;

        switch(ch){
            case 1:
                addstudent();
                break;
            case 2:
                deletestudent();
                break;
            
            case 3:
                searchstudent();
                break;
            
            case 4:
                printstudent();
                break;
            case 5:
                return 0;
                break;

            default:
            cout<<"Please Reenter your choice :"<<endl;
            break;
            
        }
    }
    
    return 0;
}*/

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void addstud()
{
	ofstream f;
	f.open("stude1.txt",ios::app);
	string name,rn,div,add;
	cout<<"Enter the name of Student: ";
	cin>>name;
	cout<<"Enter roll no: ";
	cin>>rn;
	cout<<"Enter Division: ";
	cin>>div;
	cout<<"Enter Address: ";
	cin>>add;
	f<<left<<setw(20)<<name<<setw(20)<<rn<<setw(20)<<div<<setw(20)<<add<<endl;
	f.close();
	cout<<"student data entered successfully";
}

void del(){
	ifstream f;
	f.open("stude1.txt");
	string line, rn;
	cout<<"Enter rooll no: ";
	cin>>rn;
	
	string data;
	while(getline(f,line))
	{
		if(line.find(rn)==string::npos)
		{
			data+=line;
			data+="\n";
		}
		
	}
	f.close();
	ofstream f2;
	f2.open("stude1.txt",ios::out);
	f2<<data;
	f2.close();
	
}

void search(){
	ifstream f;
	f.open("stude1.txt");
	string line,rn;
	cout<<"Enter the rolll no: ";
	cin>>rn;
	
	bool check=false;
	while(getline(f,line))
	{
		if(line.find(rn)!=string::npos)
		{
			cout<<"Srudent details:";
			cout<<line<<endl;
			check=true;
			break;
		}
	}
	f.close();
	if(check==false){
		cout<<"student not found!!";
	}
}

void print(){
	ifstream f;
	f.open("stude1.txt",ios::out);
	string line;
	
	while(getline(f,line)){
		cout<<line<<endl;
	}
	f.close();
}

int main()
{
	fstream f;
	f.open("stude1.txt",ios::out);
	f<<left<<setw(20)<<"Name: "<<setw(20)<<"Roll No: "<<setw(20)<<"Division: "<<setw(20)<<"Address: "<<endl;
	f.close();
	
	int ch;
	while(ch!=-1)
	{
		cout<<"\n1.Add Student \n2.Delete \n3.Search \n4.Print \nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				addstud();
				break;
			
			case 2:
				del();
				break;
			
			case 3:
				search();
				break;
				
			case 4:
				print();
				break;
				
			case 5:
				return 0;
			
		}
	}
}




