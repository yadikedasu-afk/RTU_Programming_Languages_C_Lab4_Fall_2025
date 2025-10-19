//Studen Name:Edasu Yadik
//Studen ID  :231AEB028
#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    int id;
    char *name;
    float gpa;
} Student;

Student *student_new(int id, const char *name, float gpa);
void student_set_name(Student *s, const char *name);
void student_print(const Student *s);
void student_free(Student *s);

#endif
