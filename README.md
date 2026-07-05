# 🏥 Hospital Patient Record System

## Project Overview

The Hospital Patient Record System is a console-based application developed in **C** that helps hospital staff manage patient records throughout the entire treatment process. The system supports patient registration, doctor assignment, status updates, billing, discharge, and permanent data storage using text file handling.

---

## How the Program Works

When the program starts, it automatically attempts to load existing patient records from `patient_information.txt`. If the file does not exist (such as during the first run), the program simply starts with an empty patient list.

The program follows the patient's journey through the hospital:

1. **Add New Patient**
   - Register a new patient by entering their personal information.
   - The patient's status is automatically set to **Waiting**.
   - Billing information, diagnosis, and assigned doctor are initialized with default values.

2. **Assign Doctor**
   - Select a patient by their ID.
   - The system displays a list of available doctors.
   - The receptionist or nurse selects a doctor to assign to the patient.

3. **Update Patient Status**
   - The patient's treatment status can be updated (e.g., Under Treatment, Stable, Critical, etc.).
   - Discharged patients cannot have their status changed.

4. **Calculate Patient Bill**
   - Enter the service fee and medicine cost.
   - The system automatically calculates the total bill.

5. **Discharge Patient**
   - Before discharge, the patient's bill must be calculated.
   - The user enters the final diagnosis.
   - The system automatically changes the patient's status to **Discharged** and prints a discharge summary, including the patient's information, doctor, diagnosis, and billing details.

6. **Save and Exit**
   - All patient records are saved to `patient_information.txt`.
   - The saved data will be loaded automatically the next time the program is executed.

---

## Features

- Add new patient records
- Display all patient records
- Search patient by ID
- Update patient status
- Assign doctor to patient
- Calculate patient bill
- Discharge patient and print receipt
- Automatically load and save patient records using text files

---

## Technologies & Programming Concepts Used

- **C Programming Language**
- **Functions** (Modular programming)
- **Structures & Nested Structures** (Patient, Doctor, and Bill records)
- **Arrays** (Storing multiple patient records and doctor information)
- **Loops** (`for`, `while`, and `do-while`)
- **Conditional Statements** (`if`, `else`, and `switch`)
- **String Handling** (`string.h` functions such as `strcpy()`, `strcmp()`, and `strcspn()`)
- **File Handling** (`fopen()`, `fclose()`, `fprintf()`, and `fscanf()`)
- **Input Validation** (Checking for invalid operations such as discharging a patient before calculating the bill)
- **Linear Search Algorithm** (Searching patients by their ID)
- **Formatted Input/Output** (`printf()`, `scanf()`, and `fgets()`)
- **Data Persistence** (Saving and loading patient records using text files)
