#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Student
{
public:
    Student(size_t NUMBER,
            string NAME,
            char GENDER,
            int AGE,
            double GRADE,
            string CLASS) : number(NUMBER), name(NAME), gender(GENDER), age(AGE), grade(GRADE), Class(CLASS)
    {
    }

    void displayInfo() const;
    string getClass() const { return Class; }
    double getGrade() const { return grade; }

private:
    size_t number;
    string name;
    char gender; // m/f
    int age;
    double grade;
    string Class;
};

void Student::displayInfo() const
{
    cout << "number: " << number << '\t' << "name: " << name << '\t' << "gender: " << gender << endl;
    cout << "age: " << age << '\t' << "grade: " << grade << '\t' << "class: " << Class << endl;
    cout << endl;
}

class StudentManageSystem
{
public:
    void add();
    void batchAdd();
    void displayAll();
    void displayViaGrade();
    void displayViaClass();

private:
    vector<Student> students;
};

void StudentManageSystem::add()
{
    ifstream inStudentFile("Students.txt", ios::in);

    if (!inStudentFile)
    {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    size_t number;
    string name;
    char gender;
    int age;
    double grade;
    string Class;

    cout << "Enter student's info:\n";
    inStudentFile >> number >> name >> gender >> age >> grade >> Class;

    Student stu(number, name, gender, age, grade, Class);
    students.push_back(stu);
}
void StudentManageSystem::batchAdd()
{
    int n = 0;
    cout << "Enter the number of students to add: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
        add();
}
void StudentManageSystem::displayAll()
{
    for (const Student &stu : students)
        stu.displayInfo();
}

bool compareGrade(const Student &stu1, const Student &stu2)
{
    return stu1.getGrade() > stu2.getGrade();
}

void StudentManageSystem::displayViaGrade()
{
    sort(students.begin(), students.end(), compareGrade);
    displayAll();
}

void StudentManageSystem::displayViaClass()
{
    string Class;
    cout << "Enter class to search: ";
    cin >> Class;

    for (const Student &stu : students)
        if (stu.getClass() == Class)
            stu.displayInfo();
}

int main()
{
    enum Choice
    {
        exit,
        batchAdd,
        displayAll,
        displayViaGrade,
        displayViaClass
    };

    StudentManageSystem sms;

    while (true)
    {
        int Choice;
        cout << "Enter choice:\n0: exit\t1: batchAdd\t2: displayAll\n"
             << "3: displayViaGrade\t4: displayViaClass\n";
        cin >> Choice;

        switch (Choice)
        {
        case exit:
            return 0;
            break;
        case batchAdd:
            sms.batchAdd();
            break;
        case displayAll:
            sms.displayAll();
            break;
        case displayViaGrade:
            sms.displayViaGrade();
            break;
        case displayViaClass:
            sms.displayViaClass();
            break;
        }
    }
}