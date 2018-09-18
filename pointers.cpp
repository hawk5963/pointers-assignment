// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <cstring>
#include<iostream> 
#include<limits>

using namespace std;

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

void CalculateStudentAverage(void *object, double *average);

int main(int argc, char **argv)
{
    Student student;
    double average = 0;

    // Sequence of user input -> store in fields of `student`
    
    //get id, must be > -1
    int idNum;
    printf("Please enter the student's id number: ");
    cin >> idNum;
    //validate input by using a while loop that breaks if cin doesn't fail.
    while(true)
    {
        
        if(cin.fail() or idNum < 0 or cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "Sorry, I cannot understand your answer\n";
            cout << "Please enter the student's id number: ";
            cin >> idNum;
        }
        else{
            break;
        }
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
    //get first name
    char *firstName = new char[128];
    cout << "Please enter the student's first name: ";
    cin >> firstName;
    
    //validate input by using a while loop that breaks if cin doesn't fail.
    while(true)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "Sorry, I cannot understand your answer\n";
            cout << "Please enter the student's first name: ";
            cin >> firstName;
        }
        else{
            break;
        }
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    //get last name
    char *lastName = new char[128];
    cout << "Please enter the student's last name: ";
    cin >> lastName;
    
    //validate input by using a while loop that breaks if cin doesn't fail.
    while(true)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "Sorry, I cannot understand your answer\n";
            cout << "Please enter the student's last name: ";
            cin >> lastName;
        }
        else{
            break;
        }
    }
    
    //get number of assignments to grade, should be > 0
    //clear cin
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    int n_assignments;
    cout << "Please enter how many assignments were graded: ";
    cin >> n_assignments;
    
    //validate input by using a while loop that breaks if cin doesn't fail.
    while(true)
    {
        if(cin.fail() or n_assignments < 0 or n_assignments > 2147483647 or cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "Sorry, I cannot understand your answer\n";
            cout << "Please enter how many assignments were graded: ";
            cin >> n_assignments;
        }
        else{
            break;
        }
    }
    
    //use a while loop to keep prompting for assignments while increasing the assignments var so it breaks eventually when it equals numAssignments
    
    //current assignment # we're on
    int assignment = 0;
    //array to hold grades. This will eventually be assigned as the student's grade array
    double *grades = new double[n_assignments];
    double grade;
    while(assignment < n_assignments)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        //get assignment's score
        printf("Please enter grade for assignment %d: ",assignment);
        //add grade to array
        cin >> grade;
        grades[assignment] = grade;
        
        //validate the score. If it passes, add it to total.
        while(true)
        {
            if(cin.fail() or grade < 0 or cin.peek() != '\n')
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cerr << "Sorry, I cannot understand your answer\n";
                printf("Please enter grade for assignment %d :",assignment);
                //add grade to array
                cin >> grade;
                grades[assignment] = grade;
            }
            else{
                break;
            }
        }
        assignment++;
    }
    double *g = grades;
    char *first = firstName;
    char *last = lastName;
    //Create student with information we've gathered thus far.
    Student deepInDebt = {idNum,firstName,lastName,n_assignments,g};
    
    Student *st = &deepInDebt;
    
    // Call `CalculateStudentAverage(Student object we created might need to pass in the memory address of that too, &average which is the memory address of average)
    CalculateStudentAverage(st,&average);
    
    // Output `average` 
    printf ("Student: %s %s [%d]\n",firstName,lastName,idNum);
    printf ("  Average grade: %.1f\n",average);

    return 0;
}
void CalculateStudentAverage(void *object, double *average)
{
    Student *obj = (Student *)object;
    double total = 0;
    int count = 0;
    // Code to calculate and store average grade
    while(count < obj->n_assignments)
    {
        //add to total
        total = total + obj->grades[count];
        count = count + 1;
    }
    int num = obj->n_assignments;
    *average = total/num;
}
