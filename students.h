#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
#include <fstream>

class Student {
protected:
    std::string first_name;
    std::string last_name;
    double gpa;
    int grad_year;
    std::string grad_semester;
    int enroll_year;
    std::string enroll_semester;
    bool is_undergrad;

public:
    Student();
    virtual ~Student();
    void setName(const std::string& first, const std::string& last);
    void setGPA(double gpa_value);
    void setGraduationInfo(int year, const std::string& semester);
    void setEnrollmentInfo(int year, const std::string& semester);
    void setUndergrad(bool status);
    virtual void displayInfo(std::ofstream& file) const;
};

class Art_Student : public Student {
private:
    std::string art_emphasis;

public:
    Art_Student();
    void setArtEmphasis(const std::string& emphasis);
    void displayInfo(std::ofstream& file) const override;
};

class Physics_Student : public Student {
private:
    std::string concentration;

public:
    Physics_Student();
    void setConcentration(const std::string& conc);
    void displayInfo(std::ofstream& file) const override;
};

#endif // STUDENTS_H
