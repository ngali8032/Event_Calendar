📅 Event Calendar – C Project

A console-based Event Calendar application written in C that allows users to manage their daily events efficiently. This project supports creating, viewing, searching, deleting, and saving events, and is designed using a modular and scalable architecture.

🚀 Features
Add new events
View all stored events
Search events by date or ID
Delete events
Unique event ID generation (based on month and year)
File-based data persistence
Menu-driven console interface

🛠 Technologies Used
Programming Language: C
Compiler: GCC
Build Tool: Makefile
Platform: Linux (GitHub Codespaces / Ubuntu Terminal)

📁 Project Structure
Event_Calendar/
│
├── main.c              → Application entry point  
├── header.h            → Structs and function prototypes  
├── add_event.c         → Add event functionality  
├── delete.c            → Delete events  
├── display_events.c   → Display all events  
├── find.c              → Search events  
├── save.c              → Save events to file  
├── sync.c              → Load saved events  
├── calender.c          → Calendar and date handling  
└── Makefile            → Build instructions  

▶ How to Run in GitHub Codespaces
Click Code → Codespaces → Create codespace
Open the terminal
Compile the project:
make

Run the program:
./a.out

💻 How to Run Locally
git clone https://github.com/ngali8032/Event_Calendar.git
cd Event_Calendar
make
./a.out

🧠 Design Highlights
Uses struct to model real-world event data
Implements a unique event ID system based on month and year
Uses file handling (fopen, fread, fwrite) for data persistence
Built with modular C files for better maintainability
Designed to run efficiently in Linux environments

⚙ Challenges Faced
The most challenging part of this project was implementing the calendar logic, which required extensive debugging and refinement. It took more than 7 hours to make the date handling and event mapping work correctly. This experience helped build strong problem-solving and debugging skills.

🔮 Future Enhancements
Add time and reminders
Sort events by date
Support recurring events
Add a graphical interface

👨‍💻 Author
Narendra Gali
GitHub: https://github.com/ngali8032
