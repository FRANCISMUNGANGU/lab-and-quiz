#include <iostream>

using namespace std;

struct Course {
    string course_code;
    string name;
};

struct Grade{
    int marks;
    string grade;
};

struct Student{
    string registration_number;
    string name;
    int age;
    Course course;
    Grade grade;

};


char grading(int mark)
{
    if(mark > 69){
        return 'A';
    }else if (mark > 59 && mark < 70){
        return 'B';
    }else if(mark > 49 && mark < 60){
        return 'C';
    }else if (mark > 39 && mark < 50){
        return 'D';
    }else{
        return 'E';
    }
}



void calculate_grade(Student students[], int studentNumber){
    string regno;
    cout << "................NOTE! GRADES ARE UNEDITABLE............\n";
    cout << "Enter Registration number of the student you want to add grades to: ";
    cin >> regno;
    for(int i = 0; i < studentNumber; i++){
        if(students[i].registration_number == regno){
            cout << "Enter the student's marks: ";
            cin >> students[i].grade.marks;
            students[i].grade.grade = grading(students[i].grade.marks);
            cout << "Grades added successfully \n";

            cout << "Registration nummber: " << students[i].registration_number << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Age: " << students[i].age << "\n";
            cout << "Course name: " << students[i].course.name << "\n";
            cout << "Course code: " << students[i].course.course_code << "\n";
            cout << "Marks: " << students[i].grade.marks << "\n";
            cout << "Grade: " << students[i].grade.grade << "\n";
            return;
        }
    }
    cout << "Student not found";
}


void add_students(Student students[],const int Maximum, int& studentNumber)
{

        if(studentNumber < Maximum){
            Student addstudent;
            cout << "Student's name: \n";
            cin >> addstudent.name;

            cout << "Student's registration number: \n";
            cin >> addstudent.registration_number;

            cout << "Student's age: \n";
            cin >> addstudent.age;

            cout << "Student's course doing: \n";
            cin >> addstudent.course.name;

            cout << "Student's course code: \n";
            cin >> addstudent.course.course_code;

            cout << "The student was added successfully \n";
            students[studentNumber++] = addstudent;

        }else{
            cout << "The maximum number of students has been reached \n";
        }

    cout << "..........STUDENT DETAILS........... \n";
    char choose;
    for(int x = 0; x < studentNumber; x++){
        cout << "Registration nummber: " << students[x].registration_number << "\n";
        cout << "Name: " << students[x].name << "\n";
        cout << "Age: " << students[x].age << "\n";
        cout << "Course name: " << students[x].course.name << "\n";
        cout << "Course code: " << students[x].course.course_code << "\n";
    }
    cout << "Do you want to edit the student? Y or N: ";
    cin >> choose;
    if(choose == 'Y' || choose =='y'){
        string regno;
        cout << "Enter Registration number of the student you want to edit: ";
        cin >> regno;
        for(int i = 0; i < studentNumber; i++){
            if(students[i].registration_number == regno){
                cout << "Enter the correct student name: ";
                cin >> students[i].name;
                 cout << "Enter the correct student registration number: ";
                cin >> students[i].registration_number;
                cout << "Enter the correct student age: ";
                cin >> students[i].age;
                 cout << "Enter the correct student course name: ";
                cin >> students[i].course.name;
                 cout << "Enter the correct student course code: ";
                cin >> students[i].course.course_code;
                cout << "Student edited successfully \n";
                cout << "Proceed to add Grades........\n";
                calculate_grade(students, studentNumber);
                return;
            }
        }
        cout << "Student not found";
    }else if(choose == 'N' || choose == 'n' ){
        calculate_grade(students, studentNumber);
    }

}



int main()
{
    const int Maximum = 40;
    Student students[Maximum];
    int studentNumber = 0;
    int choice;
    cout << "Press 1 to add a student \n";
    cout << "Press 2 to edit a student's details \n";
    cout << "Press 3 to add student's marks and calculate the grade \n";
    cout << "Press 4 end the program \n";
    cin >> choice;

    switch(choice){
        case 1:
            add_students(students, Maximum, studentNumber);
            break;
        case 2:


        case 3:
            calculate_grade(students, studentNumber);
            break;
        case 4:
            cout << "Exiting the program......";
            break;
        default:
            cout << "Invalid input. \n";
    }
    return 0;

}


