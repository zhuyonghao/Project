// 用链表实现学生信息管理，实现基本的输入输出、增、删、改、查、排序、输出名次表等。
#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int ID;
    double score;
    Student *next;
    Student(string s, int i, double d) : name(s), ID(i), score(d), next(nullptr) {}
};

class StudentManager
{
public:
    StudentManager() : head(nullptr) {}
    void AddOne();
    void BatchAdd();
    void Print();
    void Delete(int ID);
    void Edit(int ID);
    bool Search(int ID);
    void IDSort();
    void ScoreSort();
    void printTranscript();

private:
    Student *head;
};

void StudentManager::AddOne()
{
    string name;
    int ID;
    double score;
    cout << "Enter name, ID, score: ";
    cin >> name >> ID >> score;

    if (head == nullptr)
        head = new Student(name, ID, score);
    else
    {
        Student *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new Student(name, ID, score);
    }
}

void StudentManager::BatchAdd()
{
    int num;
    cout << "Enter the number of students to add: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        AddOne();
    }
}

void StudentManager::Print()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Student *curr = head;
    cout << "name" << '\t' << "ID" << '\t' << "score" << endl;
    while (curr != nullptr)
    {
        cout << curr->name << '\t' << curr->ID << '\t' << curr->score << endl;
        curr = curr->next;
    }
}

void StudentManager::Delete(int IDtoDelete)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->ID == IDtoDelete)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Student *curr = head;
    while (curr->next->ID != IDtoDelete && curr != nullptr && curr->next != nullptr)
    {
        curr = curr->next;
    }

    if (curr == nullptr || curr->next == nullptr)
    {
        cout << "ID not found" << endl;
        return;
    }

    Student *temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

void StudentManager::Edit(int IDtoedit)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Student *curr = head;
    while (curr != nullptr && curr->ID != IDtoedit)
    {
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        cout << "ID not found" << endl;
        return;
    }

    string name;
    int id;
    double score;
    cout << "Enter modified name, ID and score: ";
    cin >> name >> id >> score;
    curr->name = name;
    curr->ID = id;
    curr->score = score;
}

bool StudentManager::Search(int IDtoSearch)
{
    Student *curr = head;
    while (curr != nullptr)
    {
        if (curr->ID == IDtoSearch)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void StudentManager::IDSort()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    bool swapped;
    Student *end = nullptr;

    do
    {
        swapped = false;
        Student *current = head;
        Student *prev = nullptr;

        while (current->next != end)
        {
            if (current->ID > current->next->ID)
            {
                Student *nextNode = current->next;
                if (prev != nullptr)
                {
                    prev->next = nextNode;
                }
                else
                {
                    head = nextNode;
                }

                Student *temp = nextNode->next;
                nextNode->next = current;
                current->next = temp;

                prev = nextNode;
                swapped = true;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }

        end = current;

    } while (swapped);
}

void StudentManager::ScoreSort()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    bool swapped;
    Student *end = nullptr;

    do
    {
        swapped = false;
        Student *current = head;
        Student *prev = nullptr;

        while (current->next != end)
        {
            if (current->score > current->next->score)
            {
                Student *nextNode = current->next;
                if (prev != nullptr)
                {
                    prev->next = nextNode;
                }
                else
                {
                    head = nextNode;
                }

                Student *temp = nextNode->next;
                nextNode->next = current;
                current->next = temp;

                prev = nextNode;
                swapped = true;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }

        end = current;

    } while (swapped);
}

void StudentManager::printTranscript()
{
    ScoreSort();
    Print();
}

int main()
{
    StudentManager sm;
    sm.BatchAdd();
    sm.Print();
    sm.AddOne();
    sm.Print();
    sm.Delete(1);
    sm.Print();
    sm.Edit(2);
    sm.Print();
    if (sm.Search(3))
        cout << "found" << endl;
    else
        cout << "not found" << endl;
    sm.IDSort();
    sm.Print();
    sm.printTranscript();
}