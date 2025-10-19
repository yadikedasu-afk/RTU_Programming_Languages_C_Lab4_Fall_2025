//Studen Name:Edasu Yadik
//Studen ID  :231AEB028
#include "db.h"
#include <stdio.h>

int main(void){
    StudentDB db; 
    db_init(&db);

    db_add(&db, student_new(1, "Alice", 3.80f));
    db_add(&db, student_new(2, "Bob",   2.90f));
    db_add(&db, student_new(3, "Edasu Yadık", 3.70f));
    db_print_all(&db);

    Student *bob = db_find_by_id(&db, 2);
    if(bob){ bob->gpa = 3.15f; }

    db_remove_by_id(&db, 1);

    puts("--- after update & remove ---");
    db_print_all(&db);

    db_free(&db);
    return 0;
}
