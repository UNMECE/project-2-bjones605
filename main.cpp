#include <iostream>
#include <vector>
#include <fstream>
#include "students.h"

int main() {
    std::vector<Art_Student*> art_students;
    std::vector<Physics_Student*> physics_students;

    for (int i = 0; i < 5; ++i) {
        Art_Student* art = new Art_Student();
        art->setName("ArtFirst" + std::to_string(i + 1), "ArtLast" + std::to_string(i + 1));
        art->setGPA(3.5 + i * 0.1);
        art->setGraduationInfo(2025, "Spring");
        art->setEnrollmentInfo(2021, "Fall");
        art->setUndergrad(true);
        art->setArtEmphasis((i % 3 == 0) ? "Art Studio" : (i % 3 == 1) ? "Art History" : "Art Education");
        art_students.push_back(art);
    }

    for (int i = 0; i < 5; ++i) {
        Physics_Student* physics = new Physics_Student();
        physics->setName("PhysicsFirst" + std::to_string(i + 1), "PhysicsLast" + std::to_string(i + 1));
        physics->setGPA(3.7 + i * 0.05);
        physics->setGraduationInfo(2026, "Fall");
        physics->setEnrollmentInfo(2022, "Spring");
        physics->setUndergrad(false);
        physics->setConcentration((i % 2 == 0) ? "Biophysics" : "Earth and Planetary Sciences");
        physics_students.push_back(physics);
    }


    std::ofstream outfile("student_info.dat");
    if (outfile.is_open()) {
        for (const auto& art : art_students) {
            art->displayInfo(outfile);
        }
        for (const auto& physics : physics_students) {
            physics->displayInfo(outfile);
        }
        outfile.close();
    }

    for (auto& art : art_students) {
        delete art;
    }
    for (auto& physics : physics_students) {
        delete physics;
    }

    return 0;
}
