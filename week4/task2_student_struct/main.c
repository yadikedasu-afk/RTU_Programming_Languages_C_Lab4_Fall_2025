//Studen Name:Edasu Yadik
//Studen ID  :231AEB028
#include "student.h"

int main(void){
    Student *a = student_new(101, "Edasu Yadık", 3.45f);
    student_print(a);

    student_set_name(a, "Edasu Yadık - Updated");
    a->gpa = 3.80f;
    student_print(a);

    student_free(a);
    return 0;
}

