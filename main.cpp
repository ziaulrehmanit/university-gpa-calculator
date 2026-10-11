#include<iostream>
#include<string>
#include<limits>
#include<iomanip>

using namespace std;

int totalMarks(int total_marks[],int number_of_courses)
{
    int sum_of_total_marks=0;
    for (int i = 0; i < number_of_courses; i++)
    {
        sum_of_total_marks+=total_marks[i];
	}
    return sum_of_total_marks;
}

float obtainedMarks(float obtained_marks[],int number_of_courses)
{
    float sum_of_obtained_marks=0;
    for (int i = 0; i < number_of_courses; i++)
    {
        sum_of_obtained_marks+=obtained_marks[i];
	}
    return sum_of_obtained_marks;
}

void percentage_of_subjects(float percentage[],int total_marks[],float obtained_marks[],int number_of_courses)
{
	for (int i=0; i < number_of_courses; i++)
	{
		percentage[i]=(obtained_marks[i]/total_marks[i])*100;
	}
}

void grade_points_of_subjects(float percentage[],int number_of_courses,float grade_points[],string grade[])
{
    for (int i = 0; i < number_of_courses; i++)
    {
        if (percentage[i]>=90)
        {
            grade_points[i]=4.00;
            grade[i]="A+";
        }
        else if (percentage[i]>=85 && percentage[i]<=89)
        {
            grade_points[i]=3.70;
            grade[i]="A";
        }
        else if (percentage[i]>=80 && percentage[i]<=84)
        {
            grade_points[i]=3.30;
            grade[i]="B+";
        }
        else if (percentage[i]>=75 && percentage[i]<=79)
        {
            grade_points[i]=3.00;
            grade[i]="B";
        }
        else if (percentage[i]>=70 && percentage[i]<=74)
        {
            grade_points[i]=2.70;
            grade[i]="B-";
        }
        else if (percentage[i]>=65 && percentage[i]<=69)
        {
            grade_points[i]=2.30;
            grade[i]="C+";
        }
        else if (percentage[i]>=60 && percentage[i]<=64)
        {
            grade_points[i]=2.00;
            grade[i]="C";
        }
        else if (percentage[i]>=50 && percentage[i]<=59)
        {
            grade_points[i]=1.00;
            grade[i]="D";
        }
        else
        {
            grade_points[i]=0.00;
            grade[i]="F";
        }
    }
}

int creditHours(int credit_hours[],int number_of_courses)
{
    int total_credit_hours=0;
    for (int i = 0; i < number_of_courses; i++)
    {
        total_credit_hours+=credit_hours[i];
    }
    return total_credit_hours;
}

void gpaPoints(float  gpa_points[],int credit_hours[],float grade_points[],int number_of_courses)
{
    for (int i = 0; i < number_of_courses; i++)
    {
        gpa_points[i]=credit_hours[i]*grade_points[i];
    }
}

float gpaPoints_sum(float gpa_points[],int number_of_courses)
{
    float sum_of_gpa_points=0;
    for (int i = 0; i < number_of_courses; i++)
    {
        sum_of_gpa_points+=gpa_points[i];
    }
    return sum_of_gpa_points;
}

int main() 
{
    cout<<"\n\n\t\t\"University GPA Calculator\"\n"<<endl;
    int number_of_courses;
    cout<<"Enter Your Total Number of Courses(5-8): ";
    int i=0;
    while(i<3)
	{
        cin>>number_of_courses;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            i++;
            if (i==2)
            {
                cout<<"\nAs you entered wrong values 3 times, Program terminates.\n\n";
                return 0;
            }
            cout<<"Invalid Input: Enter Again Your Total Number of Courses(5-8): ";
        }
        else if (number_of_courses>4 && number_of_courses<9)
        {
            break;
        }
        else
        {
            i++;
            if (i==2)
            {
                cout<<"\nAs you entered wrong values 3 times, Program terminates.\n\n";
                return 0;
            }
            cout<<"\nInvalid Input: Enter Again Your Total Number of Courses(5-8): ";
        }
    }
    string subject_names[number_of_courses];
    for (int i = 0; i < number_of_courses; i++)
    {   
        string temp;
        if (i == 0) cin.ignore();
        cout<<"Enter Course Code for Subject "<<i+1<<" : ";
        getline(cin , temp);
        subject_names[i] = temp;
    }
    
    cout<<"\nNow if you enter any wrong value, program terminates.\n";
    int credits_hours[number_of_courses];
    int practical[number_of_courses];
    int theory[number_of_courses];
    int total_marks[number_of_courses];
    float obtained_marks[number_of_courses];
    int choice;

    for (int i = 0; i < number_of_courses; i++)
    {
        cout<<"\nEnter Credit Hours for "<<subject_names[i]<<" (1 to 4): ";
        cin>>credits_hours[i];
        if (cin.fail())
        {
            cout<<"\nAs you entered wrong value. Program terminates.\n\n";
            return 0;
        }
        if (credits_hours[i]==1)
        {
            cout<<"(1 - 0)\n";
            theory[i]=1,practical[i]=0;
        }
        else if (credits_hours[i]==2)
        {
            cout<<"(2 - 0)\n";
            theory[i]=2,practical[i]=0;
        }
        else if (credits_hours[i]==3)
        {
            cout<<"Enter your choice for theory and practical credit hours : \n";
            cout<<"1. (2 - 1) \n";
            cout<<"2. (3 - 0) \n";
            cin>>choice;
            if (choice==1)
            {
                theory[i]=2,practical[i]=1;
            }
            else if(choice==2)
            {
                theory[i]=3,practical[i]=0;
            }
            else
            {
                if (cin.fail())
                {
                    cout<<"\nAs you entered wrong value. Program terminates.\n\n";
                    return 0;    
                }
            }
            
        } 
        else if (credits_hours[i]==4)
        {
            cout<<"Enter your choice for theory and practical credit hours : \n";
            cout<<"1. (2 - 2) \n";
            cout<<"2. (3 - 1) \n";
            cin>>choice;
            if (choice==1)
            {
                theory[i]=2,practical[i]=2;
            }
            else if(choice==2)
            {
                theory[i]=3,practical[i]=1;
            }
            else
            {
                cout<<"\nAs you entered wrong value. Program terminates.\n\n";
                return 0;
            }    
        }
        else
        {
            cout<<"\nAs you entered wrong value. Program terminates.\n\n";
            return 0;
        }
        
        total_marks[i]=20*credits_hours[i];
        cout<<"Total Marks of "<<subject_names[i]<<" are: "<<total_marks[i]<<endl;
        cout<<"Enter Obtained Marks For "<<subject_names[i]<<": ";
        cin>>obtained_marks[i];
        if (cin.fail())
        {
            cout<<"\nAs you entered wrong value. Program terminates.\n\n";
            return 0;
        }
        if (credits_hours[i]<=0 || credits_hours[i]>4 || obtained_marks[i]<0 || obtained_marks[i]>total_marks[i])
        {
            cout<<"\nAs you entered wrong value. Program terminates.\n\n";
            return 0;
        }
        
    }
    
    int sum_of_total_marks=totalMarks(total_marks,number_of_courses);

    float sum_of_obtained_marks=obtainedMarks(obtained_marks,number_of_courses);

    float percentage[number_of_courses];
    percentage_of_subjects(percentage,total_marks,obtained_marks,number_of_courses);
    float total_percentage=(sum_of_obtained_marks/sum_of_total_marks)*100;

    float grade_points[number_of_courses];
    string grade[number_of_courses];
    grade_points_of_subjects(percentage,number_of_courses,grade_points,grade);

    int total_credit_hours=creditHours(credits_hours,number_of_courses);

    float gpa_points[number_of_courses];
    gpaPoints(gpa_points,credits_hours,grade_points,number_of_courses);
    float sum_of_gpa_points=gpaPoints_sum(gpa_points,number_of_courses);

    float GPA=sum_of_gpa_points/total_credit_hours;

    cout<<"\n\n\t\t\t\t\"YOUR RESULT\""<<endl<<endl;
    cout<<setw(10)<<left<<"Courses"<<left<<setw(10)<<"\t\tCredit Hours"<<left<<setw(10)<<"\t\tPercentage"<<left<<setw(10)<<"\t\tGrade Points"<<left<<setw(10)<<"\tGrade"<<endl;

    for (int i = 0; i < number_of_courses; i++)
    {
        cout<<setw(8)<<left<<subject_names[i]<<" ("<<theory[i]<<" - "<<practical[i]<<")"<<setw(10)<<"\t"<<credits_hours[i]<<setw(10)<<"\t"<<setw(7)<<setprecision(3)<<percentage[i]<<setw(10)<<"\t"<<grade_points[i]<<setw(10)<<"\t"<<grade[i]<<endl;
    }

    cout<<endl<<setw(13)<<"GPA "<<setprecision(3)<<GPA<<endl;
    cout<<setw(13)<<"Marks "<<sum_of_obtained_marks<<"/"<<sum_of_total_marks<<endl;
    cout<<setw(13)<<"Percentage "<<setprecision(4)<<total_percentage<<"%"<<endl<<endl;
    
}