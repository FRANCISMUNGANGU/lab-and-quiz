#include <iostream>
#include <vector>

using namespace std;

// Define the Course struct
struct Course {
    string course_code;
    string name;
};

// Define the Grade struct
struct Grade {
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


// Define the Student class
class StudentManager {
private:
    const int Maximum = 40;
    vector<Student> students;

public:
    // Function to add a new student
    void addStudent() {
        if (students.size() < Maximum) {
            Student newStudent;
            cout << "Student's name: ";
            cin >> newStudent.name;
            cout << "Student's registration number: ";
            cin >> newStudent.registration_number;
            cout << "Student's age: ";
            cin >> newStudent.age;
            cout << "Student's course name: ";
            cin >> newStudent.course.name;
            cout << "Student's course code: ";
            cin >> newStudent.course.course_code;
            cout << "The student was added successfully\n";
            students.push_back(newStudent);
        } else {
            cout << "The maximum number of students has been reached\n";
        }
    }

    // Function to edit a student's details
    void editStudent() {
        string regno;
        cout << "Enter Registration number of the student you want to edit: ";
        cin >> regno;
        for (auto& student : students) {
            if (student.registration_number == regno) {
                cout << "Enter the correct student name: ";
                cin >> student.name;
                cout << "Enter the correct student registration number: ";
                cin >> student.registration_number;
                cout << "Enter the correct student age: ";
                cin >> student.age;
                cout << "Enter the correct student course name: ";
                cin >> student.course.name;
                cout << "Enter the correct student course code: ";
                cin >> student.course.course_code;
                cout << "Student edited successfully\n";
                return;
            }
        }
        cout << "Student not found\n";
    }

    // Function to calculate grades for a student
    void calculateGrade() {
        string regno;
        cout << "Enter Registration number of the student you want to add grades to: ";
        cin >> regno;
        for (auto& student : students) {
            if (student.registration_number == regno) {
                cout << "Enter the student's marks: ";
                cin >> student.grade.marks;
                student.grade.grade = grading(student.grade.marks);
                cout << "Grades added successfully\n";
                displayStudentDetails(student);
                return;
            }
        }
        cout << "Student not found\n";
    }

    // Function to display student details
    void displayStudentDetails(const Student& student) {
        cout << "Registration number: " << student.registration_number << "\n";
        cout << "Name: " << student.name << "\n";
        cout << "Age: " << student.age << "\n";
        cout << "Course name: " << student.course.name << "\n";
        cout << "Course code: " << student.course.course_code << "\n";
        cout << "Marks: " << student.grade.marks << "\n";
        cout << "Grade: " << student.grade.grade << "\n";
    }

private:
    // Function to calculate grade based on marks
    char grading(int mark) {
        if (mark > 69) {
            return 'A';
        } else if (mark > 59) {
            return 'B';
        } else if (mark > 49) {
            return 'C';
        } else if (mark > 39) {
            return 'D';
        } else {
            return 'E';
        }
    }
};

int main() {
    StudentManager manager;
    int choice;

    cout << "Press 1 to add a student\n";
    cout << "Press 2 to edit a student's details\n";
    cout << "Press 3 to add student's marks and calculate the grade\n";
    cout << "Press 4 to end the program\n";
    cin >> choice;

    switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.editStudent();
            break;
        case 3:
            manager.calculateGrade();
            break;
        case 4:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid input\n";
    }

    return 0;
}
