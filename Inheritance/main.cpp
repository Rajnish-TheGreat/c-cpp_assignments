#include <iostream>
#include <string>

using namespace std;

class basicInfo{
	protected:
		string name, dob, blood_group;
    public:
		void getBasic();
		void showBasic();
};


void basicInfo::getBasic(){
	cout<<"\nName: ";
	cin>>name;
	cout<<"\nDOB(DD/MM/YY): ";
	cin>>dob;
	cout<<"\nBlood Group: ";
	cin>>blood_group;
}

void basicInfo::showBasic(){
	cout<<"\n"<<name<<"\t"<<dob<<"\t"<<blood_group<<"\t";
}


class healthInfo{
	protected:
		float height, weight;
	public:
		void getHealth();
		void showHealth();
};

void healthInfo::getHealth(){
	cout<<"\nHeight(in cm): ";
	cin>>height;
	cout<<"\nWeight(in Kg): ";
	cin>>weight;
}

void healthInfo::showHealth(){
	cout<<height<<"\t"<<weight<<"\t";
}


class policyInfo{
	protected:
		unsigned long int policy_no;
		string address;
	public:
		void getPolicy();
		void showPolicy();
};

void policyInfo::getPolicy(){
	cout<<"\nInsurance Policy Number: ";
	cin>>policy_no;
	cout<<"\nAddress: ";
	cin>>address;
}

void policyInfo::showPolicy(){
	cout<<policy_no<<"\t"<<address<<"\t";
}


class detailInfo: public basicInfo, public healthInfo, public policyInfo{
	protected:
		unsigned long int phone;
		string license;
	public:
		bool flag=0;
		void getDetail();
		void showDetail();
		bool searchData(string ser);
};

void detailInfo::getDetail(){
	getBasic();
	getHealth();
	getPolicy();
	cout<<"\nPhone No: ";
	cin>>phone;
	cout<<"\nLicense No: ";
	cin>>license;
}

void detailInfo::showDetail(){
	showBasic();
	showHealth();
	showPolicy();
	cout<<phone<<"\t"<<license<<"\n";
}


bool detailInfo::searchData(string ser){
    return (!flag && name==ser);
}

int main(){
	string ser;
	int choice, n;
	detailInfo person[50];
    do{
		cout<<"\n\tMenu: \n1 Create Database \n2 Display Database \n3 Search \n4 Add New Entry \n5 Modify \n6 Delete a entry \n7 Exit \nEnter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter Number of records: ";
				cin>>n;
				for(int i=0;i<n;++i){
					person[i].getDetail();
				}
				break;
			case 2:
				cout<<"\nName\tDOB\tBG\tHeight\tWeight\tPolicyNo\tAddress\tPhoneNo\tLicenseNo\n";
				for(int i=0;i<n;++i){
                    person[i].showDetail();
				}
				break;
            case 3:
				cout<<"\nEnter Name: ";
				cin>>ser;
				for(int i=0;i<n;++i){
					if(person[i].searchData(ser)){
                        cout<<"\nName\tDOB\tBG\tHeight\tWeight\tPolicyNo\tAddress\tPhoneNo\tLicenseNo\n";
						person[i].showDetail();
					}
				}
				break;
			case 4:
				person[n++].getDetail();
				break;
			case 5:
				cout<<"\nEnter Name: ";
				cin>>ser;
				for(int i=0;i<n;++i){
					if(person[i].searchData(ser)){
						person[i].getDetail();
						break;
					}
				}
				break;
			case 6:
				cout<<"\nEnter Name: ";
				cin>>ser;
				for(int i=0;i<n;++i){
					if(person[i].searchData(ser)){
                        person[i].flag=1;
                        person[i]=person[i+1];
                        break;
					}
				}
				cout<<"\nRecord successfully deleted\n";
                n--;
				break;
			case 7:
				break;
			default:
				cout<<"\nInvalid Choice!!!";
		}
	}while(choice!=7);
	return 0;
}

