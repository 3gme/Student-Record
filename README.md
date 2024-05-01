# Student Record System
## Overview
The Student Record System is a C program designed to manage student information including names, IDs, passwords, ages, total grades, and genders.

## Modes
The system operates in two modes:

### Admin Mode
In admin mode, users are prompted to enter the admin password. They have three attempts to enter the correct password. Once authenticated, they gain access to the following options:
1. Add student record
2. Remove student record
3. View student record
4. View all student records
5. Edit admin password
6. Edit student total grade

### User Mode
User mode is intended for students. Upon opening the program, users are prompted to enter their ID and password. After successful authentication, they gain access to the following options:
1. View your record
2. Edit your password
3. Edit your name

## Data Storage
All user and admin data, including passwords, are stored in a text file. Upon opening the program, the most recent student and admin data is retrieved. Any changes made are saved back to the file.
