#include "students.h"

Student::Student() 
    : first_name(""), last_name(""), gpa(0.0), grad_year(0), 
      grad_semester(""), enroll_year(0), enroll_semester(""), is_undergrad(true) {}

Student::~Student() {}

void Student::setName(const std::string& first, const std::string& last) {
    first_name = first;
    last_name = last;
}

void Student::setGPA(double gpa_value) {
    gpa = gpa_value;
}

void Student::setGraduationInfo(int year, const std::string& semester) {
    grad_year = year;
    grad_semester = semester;
}

void Student::setEnrollmentInfo(int year, const std::string& semester) {
    enroll_year = year;
    enroll_semester = semester;
}

void Student::setUndergrad(bool status) {
    is_undergrad = status;
}

void Student::displayInfo(std::ofstream& file) const {
    file << "Name: " << first_name << " " << last_name << "\n";
    file << "GPA: " << gpa << "\n";
    file << "Graduation: " << grad_semester << " " << grad_year << "\n";
    file << "Enrollment: " << enroll_semester << " " << enroll_year << "\n";
    file << "Undergraduate: " << (is_undergrad ? "Yes" : "No") << "\n";
}

Art_Student::Art_Student() : art_emphasis("") {}

void Art_Student::setArtEmphasis(const std::string& emphasis) {
    art_emphasis = emphasis;
}

void Art_Student::displayInfo(std::ofstream& file) const {
    Student::displayInfo(file);
    file << "Art Emphasis: " << art_emphasis << "\n\n";
}

Physics_Student::Physics_Student() : concentration("") {}

void Physics_Student::setConcentration(const std::string& conc) {
    concentration = conc;
}

void Physics_Student::displayInfo(std::ofstream& file) const {
    Student::displayInfo(file);
    file << "Concentration: " << concentration << "\n\n";
}
