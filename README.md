🚘 M-Tag Based Toll Management System (C++)
📌 Overview

This project is a console-based simulation of an electronic toll collection system (M-Tag) developed in C++.
It automates toll operations by registering vehicles with a unique M-Tag ID, deducting toll charges, managing balances, and permanently storing records using file handling.

The project demonstrates how core C++ programming concepts can be applied to solve a real-world problem.

🎯 Objectives

Automate toll collection to reduce manual delays

Register vehicles using unique M-Tag IDs

Implement automatic toll deduction

Manage vehicle balances (check & recharge)

Store and retrieve data permanently

✨ Features

Vehicle registration with M-Tag ID

Automatic toll deduction with balance validation

Account balance check and recharge

Vehicle search functionality

Display and delete vehicle records

Persistent data storage using text files

Console-based car animation during toll deduction

🛠 Technologies & Concepts Used

Language: C++

IDE: Visual Studio Code

Concepts:

Structures

Arrays

Functions

File Handling (I/O)

Menu-Driven Programming

⚙️ How the System Works

Program loads saved vehicle data from a file at startup

A menu is displayed to the user

User selects an operation (add vehicle, deduct toll, etc.)

Corresponding function executes

Updated data is saved back to the file on exit

▶️ How to Run the Project

Clone the repository:

git clone https://github.com/TheSilentCompiler/M-tag_Automated_toll-_Management_system.git


Open the project in Visual Studio Code

Compile and run the program:

g++ main.cpp -o mtag
./mtag


(For Windows, run using your compiler setup.)

📂 Data Storage

Vehicle data is stored in a text file

Data is automatically loaded at program start

Data is saved when the program exits

🚧 Limitations

Console-based (no graphical user interface)

Platform-dependent due to system libraries

🔮 Future Improvements

Add a graphical user interface (GUI)

Improve input validation

Make the system cross-platform

Use database storage instead of text files

👨‍💻 Author

Muhammad Bilal
Computer Science Student

📜 License

This project is for educational purposes.
