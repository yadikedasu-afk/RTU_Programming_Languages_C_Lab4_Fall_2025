//Studen Name:Edasu Yadik
//Studen ID  :231AEB028
#ifndef DB_H
#define DB_H
#include <stddef.h>
#include "student.h"

typedef struct {
    Student **items;
    size_t size;
    size_t capacity;
} StudentDB;

void db_init(StudentDB *db);
void db_free(StudentDB *db);
void db_add(StudentDB *db, Student *s);
Student* db_find_by_id(const StudentDB *db, int id);
int db_remove_by_id(StudentDB *db, int id);
void db_print_all(const StudentDB *db);

#endif
