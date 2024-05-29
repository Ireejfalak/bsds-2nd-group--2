#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    int age;

public:
Student(){}
    Student(int id, string name, int age) : id(id), name(name), age(age) {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }

    void display(){
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
    }
};

class Course {
private:
    string courseName;
    int credit_hours;

public:
Course(){}
    Course(string name, int hours) : courseName(name), credit_hours(hours) {}

    int getCourseHours() const { return credit_hours; }
    string getCourseName() const { return courseName; }

    void display() const {
        cout << "Course Name: " << courseName << ", Course Credit Hours: " << credit_hours << endl;
    }
};

class Grade {
private:
    int studentId;
    char grade;

public:
Grade(){}
    Grade(int studentId, char grade) : studentId(studentId), grade(grade) {}

    int getStudentId() { 
        return studentId;
    }

    char getGrade() { 
        return grade;
    }

    void display() const {
        cout << "Student ID: " << studentId << ", Grade: " << grade << endl;
    }
};

class AttendanceRecord {
private:
    int studentId;
    int attendancePercentage;

public:
AttendanceRecord(){}
    AttendanceRecord(int studentId, int attendance) : studentId(studentId), attendancePercentage(attendance) {}

    int getStudentId() const { return studentId; }
    int getAttendance() const { return attendancePercentage; }

    void display() const {
        cout << "Student ID: " << studentId << ", Attendance (%): " << attendancePercentage << " %" << endl;
    }
};

class StudentManagementSystem {
public:
    Student arr_students[5000];
    Course arr_courses[5000];
    Grade arr_grades[5000];
    AttendanceRecord arr_attendence[5000];

    int i_std = 0, i_crse = 0, i_grd = 0, i_atnd = 0;

public:

    StudentManagementSystem(){

    } 

    void addStudent() {
        int id, age;
        string name;
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Name: ";
        cin>>name;
        cout << "Enter Student Age: ";
        cin >> age;
        arr_students[i_std] = Student(id, name, age);
        i_std++;
    }

    void addCourse() {
        int courseHours;
        string courseName;

        cout << "Enter Course Name: ";
        cin>>courseName;

        cout << "Enter Course Credit Hours: ";
        cin >> courseHours;

        arr_courses[i_crse] = Course(courseName, courseHours); 
        i_crse++;
    }

    void addGrade() {
        int studentId;
        char grade;
        cout << "Enter Student ID: ";
        cin >> studentId;
        cout << "Enter Grade: ";
           cin >> grade;
        try{
            if( grade=='A'||grade=='B'||grade=='C'||grade=='D'||grade=='F'){
                arr_grades[i_grd] = Grade(studentId, grade);
                i_grd++;
            }
            else
                throw grade;
                }
            catch(char g){
            cout<<"Invalide Grade :"<<g<<"\n";
            }

       
    }

    void addAttendanceRecord() {
        int studentId, attendance;
        cout << "Enter Student ID: ";
        cin >> studentId;

        cout << "Enter Attendance (%): ";
        cin >> attendance;

        arr_attendence[i_atnd] = AttendanceRecord(studentId, attendance);
        i_atnd++;
    }


    void displayStudents(){
        for(int i=0; i<i_std; i++){
            arr_students[i].display();
        }
    }

    void displayCourses(){
        for(int i=0; i<i_crse; i++){
            arr_courses[i].display(); 
        }
    }

    void displayGrades(){
        for(int i=0; i<i_grd; i++){
            arr_grades[i].display();
        }
    }

    void displayAttendance(){
        for(int i=0; i<i_atnd; i++){
            arr_attendence[i].display();
        }
    }

};

int main(){

    StudentManagementSystem sms;

        int choice;
        do{
            cout << "\nStudent Management System Menu:\n";
            cout << "1. Add Student\n";
            cout << "2. Add Course\n";
            cout << "3. Add Grade\n";
            cout << "4. Add Attendance Record\n";
            cout << "5. Display Students\n";
            cout << "6. Display Courses\n";
            cout << "7. Display Grades\n";
            cout << "8. Display AttendanceRecords\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    sms.addStudent();
                    break;
                case 2:
                    sms.addCourse();
                    break;
                case 3:
                    sms.addGrade();
                    break;
                case 4:
                    sms.addAttendanceRecord();
                    break;
                case 5:
                    sms.displayStudents();
                    break;
                case 6:
                    sms.displayCourses();
                    break;
                case 7:
                    sms.displayGrades();
                    break;
                case 8:
                    sms.displayAttendance();
                    break;
                case 9:
                cout << "Thanks for using the student management system.\n";
                break;
                default:
                    cout << "Invalid choice";
            }
        } 
           while(choice != 9);



        return 0;
    }