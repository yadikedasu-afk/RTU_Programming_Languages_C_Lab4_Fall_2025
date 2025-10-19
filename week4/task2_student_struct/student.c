//Studen Name:Edasu Yadik
//Studen ID  :231AEB028
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static char* dupstr(const char *src){
    size_t n = strlen(src) + 1;
    char *p = (char*)malloc(n);
    assert(p != NULL);
    memcpy(p, src, n);
    return p;
}

Student *student_new(int id, const char *name, float gpa){
    Student *s = (Student*)malloc(sizeof(Student));
    assert(s != NULL);
    s->id = id;
    s->name = dupstr(name);
    s->gpa = gpa;
    return s;
}

void student_set_name(Student *s, const char *name){
    free(s->name);
    s->name = dupstr(name);
}

void student_print(const Student *s){
    printf("Student{id=%d, name=\"%s\", gpa=%.2f}\n", s->id, s->name, s->gpa);
}

void student_free(Student *s){
    if(!s) return;
    free(s->name);
    free(s);
}
