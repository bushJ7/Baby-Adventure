#include <stdio.h>
struct Patient{
    int patient_id;
    char name[50];
    int age;
    char diagnosis[100];
    char doctor[50];
};
// ly heang
void add_patient(int size,int amount,struct Patient patients[]);
// ronith
void delete_patient(int id,int size,struct Patient patients[]);
// sithika
void search(int id,int size,struct Patient patients[]);
// kimnai
void update_status(int id,int size,struct Patient patients[]);

void main(){

    printf("hello world");
}
