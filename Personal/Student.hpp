



class Student                                             // classe student - objeto alunos : sams etc
{
    public:
    double addCourse (int hours, double grade)         //addcourse gpa semesterhour - membros
    {
        double weightedGPA;
        weightedGPA = this->semesterHours * this->gpa;

        this->semesterHours += hours;                   // aqui todos os This podem ser removidos.
        weightedGPA += grade * hours;
        this->gpa = weightedGPA / this->semesterHours;
        return this->gpa;
    }

    int semesterHours;
    double gpa;
};
