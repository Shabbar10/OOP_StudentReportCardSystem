#include <iostream>
#include <string>
#include <vector>

class Report
{
private:
    int m_LCA[4], m_CT[4], m_MT[4], m_ET[4];
    bool m_valid;

protected:
    Report() :
        m_LCA{ 0,0,0,0 }, m_CT{ 0,0,0,0 }, m_MT{ 0,0,0,0 }, m_ET{ 0,0,0,0 }, m_valid{ false }
    { }

    void LCAMarks()
    {
        std::cout << "\nEnter student's LCA Marks in PCBM order:\n";

        int p, c, b, m;
        m_valid = true;
        
        do
        {
            std::cin >> p >> c >> b >> m;
            if (p < 0 || p > 20 || c < 0 || c > 20 || b < 0 || b > 20 || m < 0 || m > 20)
            {
                std::cout << "Incorrect range. LCA Marks must be between 0 and 20.\n";
                m_valid = false;
            }

        } while (!m_valid);

        m_LCA[0] = p;
        m_LCA[1] = c;
        m_LCA[2] = b;
        m_LCA[3] = m;
    }

    void ClassTestMarks()
    {
        std::cout << "\nEnter student's Class Test Marks in PCBM order:\n";

        int p, c, b, m;
        m_valid = true;

        do
        {
            std::cin.clear();
            std::cin.ignore();
            std::cin >> p >> c >> b >> m;
            if (p < 0 || p > 20 || c < 0 || c > 20 || b < 0 || b > 20 || m < 0 || m > 20)
            {
                std::cout << "Incorrect range. Class Test Marks must be between 0 and 20.\n";
                m_valid = false;
            }

        } while (!m_valid);

        m_CT[0] = p;
        m_CT[1] = c;
        m_CT[2] = b;
        m_CT[3] = m;
    }

    void MidTermMarks()
    {
        std::cout << "\nEnter student's Mid-Term Marks in PCBM order:\n";

        int p, c, b, m;
        m_valid = true;

        do
        {
            std::cin >> p >> c >> b >> m;
            if (p < 0 || p > 20 || c < 0 || c > 20 || b < 0 || b > 20 || m < 0 || m > 20)
            {
                std::cout << "Incorrect range. Mid-Term Test Marks must be between 0 and 20.\n";
                m_valid = false;
            }

        } while (!m_valid);

        m_MT[0] = p;
        m_MT[1] = c;
        m_MT[2] = b;
        m_MT[3] = m;
    }

    void EndTermMarks()
    {
        std::cout << "\nEnter student's End-Term Marks in PCBM order:\n";

        int p, c, b, m;
        m_valid = true;

        do
        {
            std::cin >> p >> c >> b >> m;
            if (p < 0 || p > 40 || c < 0 || c > 40 || b < 0 || b > 40 || m < 0 || m > 40)
            {
                std::cout << "Incorrect range. End-Term Test Marks must be between 0 and 40.\n";
                m_valid = false;
            }

        } while (!m_valid);

        m_ET[0] = p;
        m_ET[1] = c;
        m_ET[2] = b;
        m_ET[3] = m;

        std::cout << std::endl;
    }

    void GetReport()
    {
        std::cout << "\t\tP C B M\n";

        std::cout << "LCA:\t\t";
        for (int i = 0; i < 4; i++)
        {
            std::cout << m_LCA[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Class Test:\t";
        for (int i = 0; i < 4; i++)
        {
            std::cout << m_CT[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Mid-Term:\t";
        for (int i = 0; i < 4; i++)
        {
            std::cout << m_MT[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "End-Term:\t";
        for (int i = 0; i < 4; i++)
        {
            std::cout << m_ET[i] << " ";
        }
        std::cout << std::endl << "---------------------------------------------------------------------";
        std::cout << std::endl << std::endl;
    }
};

class Student : private Report
{
private:
    std::string m_name, m_course;
    int m_PRN, m_div, m_roll;

public:    

    Student() : m_name{ "" }, m_course{ "" }, m_PRN{ 0 }, m_div{ 0 }, m_roll{ 0 }
    { }

    void SetStudent()
    {
        std::cout << "Student Name: "; std::getline(std::cin, m_name);
        std::cout << "Student Course: "; std::getline(std::cin, m_course);
        std::cout << "Student PRN: "; std::cin >> m_PRN;
        std::cout << "Student Division: "; std::cin >> m_div;
        std::cout << "Student Roll No.: "; std::cin >> m_roll;
        std::cout << std::endl;

        LCAMarks();
        ClassTestMarks();
        MidTermMarks();
        EndTermMarks();
    }

    void GetStudent()
    {
        std::cout << "\nStudent Name: " << m_name << std::endl;
        std::cout << "Student Course: " << m_course << std::endl;
        std::cout << "Student PRN: " << m_PRN << std::endl;
        std::cout << "Student Division: " << m_div << std::endl;
        std::cout << "Student Roll No.: " << m_roll << std::endl << std::endl;

        GetReport();
    }
};

int main()
{
    short choice;
    std::vector<Student> sv;

    do
    {
        std::cout << "Do you want to (1) Insert Student Data or (2) View Student Data or (0) Exit?\n";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore();

        Student* s = new Student;

        if (choice == 1)
        {
            s->SetStudent();
            sv.push_back(*s);
        }
        else if (choice == 2)
        {
            for (int i = 0; i < sv.size(); i++)
            {
                sv[i].GetStudent();
            }
        }
        else
        {
            std::cout << "See you next time.\n";
        }
    } while (choice != 0);

    return 0;
}
