#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Student {
    public:
        Student(std::string last, std::string first, unsigned int percent)
        {
            lastName = last;
            firstName = first;
            grade = percent;
        };
        std::string getLastName() { return lastName; }
        std::string getFirstName() { return firstName; }
        unsigned int getGrade() { return grade; }
    private:
        std::string lastName;
        std::string firstName;
        unsigned int grade;
};

class Section {
    public:
        Section(){size = 0;};
        void addStudent(std::string lastName, std::string firstName, unsigned int grade)
        {
            Student *newStudent = new Student(lastName, firstName, grade);
            if(size == 0)
            {
                section[0] = newStudent;
                minGrade = newStudent->getGrade();
                maxGrade = newStudent->getGrade();
            }
            else
            {
                if(newStudent->getGrade() < minGrade) minGrade = newStudent->getGrade();
                if(newStudent->getGrade() > maxGrade) maxGrade = newStudent->getGrade();

                int i = size;
                while ((i > 0) && (newStudent->getLastName() < section[i-1]->getLastName()))
                {
                    section[i] = section[i-1];
                    i = i - 1;
                }
                section[i] = newStudent;
            }
            size++;
            calculateMean();
            calculateSD();
        };
        void printStudents()
        {
            cout << "Last Name, First Name, Grade" << endl;
            cout << "----------------------------" << endl;
            for(unsigned int i = 0; i < size; i++)
            {
                cout << section[i]->getLastName() << ", " << section[i]->getFirstName() << ", " << section[i]->getGrade() << endl;
            }
        };
        void calculateMean()
        {
            float sum = 0;
            for(unsigned int i = 0; i < size; i++)
            {
                sum += section[i]->getGrade();
            }
            mean = sum/size;
        };
        void calculateSD()
        {
            float sum = 0.0;
            for(unsigned int i = 0; i < size; i++)
            {
                sum += pow((section[i]->getGrade() - mean), 2);
            }
            standardDeviation = sqrt(sum/size);
        };
        void printStats()
        {
            cout << "Minimum Grade: " << minGrade << endl;
            cout << "Maximum Grade: " << maxGrade << endl;
            cout << "Mean: " << mean << endl;
            cout << "Standard Deviation: " << standardDeviation << endl;
        };
    private:
        Student* section[100];
        unsigned int size;
        unsigned int minGrade;
        unsigned int maxGrade;
        float mean;
        float standardDeviation;
};

int main()
{
    Section *CMPT225 = new Section();
    CMPT225->addStudent("Jalali", "Paymon", 1);
    CMPT225->addStudent("Do", "Andrew", 4);
    CMPT225->addStudent("lo", "Andrew", 7);
    CMPT225->addStudent("lo", "Andrew", 2);
    CMPT225->addStudent("lo", "Andrew", 6);
    CMPT225->printStudents();
    CMPT225->printStats();

    return 0;
}