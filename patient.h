#ifndef PATIENT_H
#define PATIENT_H
 
#include "data.h"

void prompt_id(char id[]);
int find_index(Patient patient[], int size, char target_id[]);
void add_patient(Patient patient[], int *size);
void search_patient(Patient patient[], int size);
void discharge(Patient patient[], int size);
void assign_doctor(Patient patient[], int size, Doctor Dr[], int dr_amount);
void update_status(Patient patient[], int size);
void display(Patient patient[], int size);
 
#endif
 