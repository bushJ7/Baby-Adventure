# Hospital Patient Record System

## Project Overview
A console-based Hospital Patient Record System written in C that manages patient information from registration until discharge. The system uses structures and text file handling to store patient records permanently.

## Features
- Add new patient
- Display all patients
- Search patient by ID
- Update patient status
- Assign doctor
- Calculate patient bill
- Discharge patient and print receipt
- Save and load patient records

## Patient Workflow

Program Start
    ↓
Load Existing Data
    ↓
Add Patient
    ↓
Status = Waiting (Automatically)
    ↓
Assign Doctor
    ↓
Update Status
    ↓
Calculate Bill
    ↓
Enter Final Diagnosis
    ↓
Discharge Patient
(Status = Discharged)
    ↓
Print Receipt
    ↓
Save Data
    ↓
Exit

## Data Persistence

The program automatically loads data from `patient_information.txt` when it starts.

- If the file exists, all patient records are loaded.
- If the file does not exist, the program starts with an empty record list.

Patient data is saved back to the file when the user selects **Save and Exit**.

## Technologies Used

- C Programming
- Structures & Nested Structures
- Arrays
- Functions
- File Handling (`fprintf`, `fscanf`)
- String Handling

## Future Improvements

- Edit patient information
- Delete patient records
- Appointment scheduling
- Database integration
- Login system
