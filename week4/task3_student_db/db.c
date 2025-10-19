//Studen Name:Edasu Yadik
//Studen ID  :231AEB028
#include "db.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static void db_grow(StudentDB *db){
    if(db->size < db->capacity) return;
    size_t newcap = db->capacity ? db->capacity * 2 : 4;
    Student **ni = (Student**)realloc(db->items, newcap * sizeof(Student*));
    assert(ni != NULL);
    db->items = ni;
    db->capacity = newcap;
}

void db_init(StudentDB *db){
    db->items = NULL;
    db->size = 0;
    db->capacity = 0;
}

void db_free(StudentDB *db){
    if(!db) return;
    for(size_t i=0;i<db->size;++i)
        student_free(db->items[i]);
    free(db->items);
    db->items = NULL;
    db->size = db->capacity = 0;
}

void db_add(StudentDB *db, Student *s){
    db_grow(db);
    db->items[db->size++] = s;
}

Student* db_find_by_id(const StudentDB *db, int id){
    for(size_t i=0;i<db->size;++i)
        if(db->items[i]->id == id)
            return db->items[i];
    return NULL;
}

int db_remove_by_id(StudentDB *db, int id){
    for(size_t i=0;i<db->size;++i){
        if(db->items[i]->id == id){
            student_free(db->items[i]);
            memmove(&db->items[i], &db->items[i+1], (db->size - i - 1)*sizeof(Student*));
            db->size--;
            return 1;
        }
    }
    return 0;
}

void db_print_all(const StudentDB *db){
    printf("DB(size=%zu):\n", db->size);
    for(size_t i=0;i<db->size;++i)
        student_print(db->items[i]);
}
