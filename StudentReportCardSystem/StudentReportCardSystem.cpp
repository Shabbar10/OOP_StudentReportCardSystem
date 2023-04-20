#include <iostream>
#include <string>
#include <fstream>
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

    void SetMarks()
    {
        std::cout << "\nEnter student's LCA Marks in PCBM order:\n";

        int lp, lc, lb, lm,
            cp, cc, cb, cm,
            mp, mc, mb, mm,
            ep, ec, eb, em;

        do
        {
            m_valid = true;

            std::cin.clear();
            std::cin.ignore();
            std::cin >> lp >> lc >> lb >> lm;
            if (!(std::cin))
            {
                std::cout << "Invaid input.\n";
                m_valid = false;
            }
            else if (lp < 0 || lp > 20 || lc < 0 || lc > 20 || lb < 0 || lb > 20 || lm < 0 || lm > 20)
            {
                std::cout << "Incorrect range. LCA Marks must be between 0 and 20.\n";
                m_valid = false;
            }

        } while (!m_valid);

        m_LCA[0] = lp;
        m_LCA[1] = lc;
        m_LCA[2] = lb;
        m_LCA[3] = lm;

        std::cout << "\nEnter student's Class Test Marks in PCBM order:\n";

        do
        {
            m_valid = true;

            std::cin.clear();
            std::cin.ignore();
            std::cin >> cp >> cc >> cb >> cm;
            if (!(std::cin))
            {
                std::cout << "Invaid input.\n";
                m_valid = false;
            }
            else if (cp < 0 || cp > 20 || cc < 0 || cc > 20 || cb < 0 || cb > 20 || cm < 0 || cm > 20)
            {
                std::cout << "Incorrect range. Class Test Marks must be between 0 and 20.\n";
                m_valid = false;
            }

        } while (!m_valid);

        m_CT[0] = lp;
        m_CT[1] = lc;
        m_CT[2] = lb;
        m_CT[3] = lm;

        std::cout << "\nEnter student's Mid-Term Marks in PCBM order:\n";

        do
        {
            m_valid = true;

            std::cin >> mp >> mc >> mb >> mm;
            if (!(std::cin))
            {
                std::cout << "Invaid input.\n";
                m_valid = false;
            }
            else if (mp < 0 || mp > 20 || mc < 0 || mc > 20 || mb < 0 || mb > 20 || mm < 0 || mm > 20)
            {
                std::cout << "Incorrect range. Mid-Term Test Marks must be between 0 and 20.\n";
                m_valid = false;
            }

        } while (!m_valid);

        m_MT[0] = mp;
        m_MT[1] = mc;
        m_MT[2] = mb;
        m_MT[3] = mm;

        std::cout << "\nEnter student's End-Term Marks in PCBM order:\n";

        do
        {
            m_valid = true;

            std::cin >> ep >> ec >> eb >> em;

            if (!(std::cin))
            {
                std::cout << "Invaid input.\n";
                m_valid = false;
            }
            else if (ep < 0 || ep > 40 || ec < 0 || ec > 40 || eb < 0 || eb > 40 || em < 0 || em > 40)
            {
                std::cout << "Incorrect range. End-Term Test Marks must be between 0 and 40.\n";
                m_valid = false;
            }

        } while (!m_valid);

        m_ET[0] = ep;
        m_ET[1] = ec;
        m_ET[2] = eb;
        m_ET[3] = em;

        std::cout << std::endl;
    }

    void GetReport()
    {
        std::cout << "\t\tP\tC\tB\tM\n";

        std::cout << "LCA:\t\t";
        for (int i = 0; i < 4; i++)
        {
            printf("%02d\t", m_LCA[i]);
        }
        std::cout << std::endl;

        std::cout << "Class Test:\t";
        for (int i = 0; i < 4; i++)
        {
            printf("%02d\t", m_CT[i]);
        }
        std::cout << std::endl;

        std::cout << "Mid-Term:\t";
        for (int i = 0; i < 4; i++)
        {
            printf("%02d\t", m_MT[i]);
        }
        std::cout << std::endl;

        std::cout << "End-Term:\t";
        for (int i = 0; i < 4; i++)
        {
            printf("%02d\t", m_ET[i]);
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
        bool bvalid{ true };

        std::cout << "Student Name: "; std::getline(std::cin, m_name);
        std::cout << "Student Course: "; std::getline(std::cin, m_course);
        do {
            std::cout << "Student PRN: "; std::cin >> m_PRN;
            if (!(std::cin))
            {
                std::cout << "Invaid input.\n";
                bvalid = false;
            }
        } while (!bvalid);

        std::cout << "Student Division: "; std::cin >> m_div;
        do {
            if (!(std::cin))
            {
                std::cout << "Invaid input.\n";
                bvalid = false;
            }
        } while (!bvalid);

        std::cout << "Student Roll No.: "; std::cin >> m_roll;
        do {
            if (!(std::cin))
            {
                std::cout << "Invaid input.\n";
                bvalid = false;
            }
        } while (!bvalid);

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

        if (!(std::cin))
        {
            std::cout << "Invalid input.\n\n";
            choice = 1;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

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
