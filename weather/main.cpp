#include <iostream>

using namespace std;

    class weather {

    public:
        int date;
        float highTemp, lowTemp, amountRain,amountSnow;
        weather();
        void inputData();
        void display();
        void average(int,weather *w);
    };

    weather::weather()
    {
        date=31;
        highTemp=30;
        lowTemp=-25;
        amountRain=0;
        amountSnow=0;
    }

    void weather::inputData()
    {
        cout<<"Enter Date: ";
        cin>>date;
        cout<<"Enter highest Temperature(Celsius): ";
        cin>>highTemp;
        cout<<"\nEnter lowest Temperature(Celsius): ";
        cin>>lowTemp;
        cout<<"\nEnter amount of Rain(in cm): ";
        cin>>amountRain;
        cout<<"\nEnter amount of Snow(in cm): ";
        cin>>amountSnow;
    }

    void weather::display()
    {
        cout<<"\t"<<date<<"\t\t"<<highTemp<<"\t\t"<<lowTemp<<"\t\t"<<amountRain<<"\t\t"<<amountSnow<<"\n";
    }

    void weather::average(int totalDays,weather w[31]){
        float avgHigh,totalHigh,avgLow,totalLow,avgRain,totalRain,avgSnow,totalSnow;
        totalHigh=totalLow=totalRain=totalSnow=0;
        int i;
        for(i=1;i<=totalDays;i++)
        {
            totalHigh+=w[i].highTemp;
            totalLow+=w[i].lowTemp;
            totalRain+=w[i].amountRain;
            totalSnow+=w[i].amountSnow;
        }
        avgHigh=totalHigh/totalDays;
        avgLow=totalLow/totalDays;
        avgRain=totalRain/totalDays;
        avgSnow=totalSnow/totalDays;
        cout<<"\nAverage High Temp:"<<avgHigh;
        cout<<"\nAverage Low Temp:"<<avgLow;
        cout<<"\nAverage Amount of Rain:"<<avgRain;
        cout<<"\nAverage Amount of Snow:"<<avgSnow;;
    }

    int main() {
        int ch, totalDays;
        char choice;
        weather w[31],temp[31],avg;
        cout<<"\n\t\t\t\t\tWEATHER REPORT";
        do
        {
        cout<<"\nEnter total number of days: ";
        cin>>totalDays;
        cout<<"\n1.Enter Data\n2.Display Report\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                for(int i=1;i<=totalDays;i++){
                    w[i].inputData();
                }
                break;

            case 2:
                cout<<"\n\n\tDate        High_temp\t\tLow_temp\tAmount_of_Rain\tAmount_of_Snow";
                for(int i=1;i<=totalDays;i++){
                cout<<"\n";
                w[i].display();
                }
                for(int i=1;i<=totalDays;i++){
                temp[i]=w[i];
                }
                avg.average(totalDays,temp);
                break;
        }
        cout<<"\nDo u want to continue?";
        cin>>choice;
        }while(choice=='y');
        return 0;
    }


