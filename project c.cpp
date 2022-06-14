#include <iostream>  //used to invoke the commonly used functions like cout,cin
#include <conio.h>   //used to provide console input/output
#include <string.h>  //used for string handling
#include <windows.h> //used for moving cursor in this program
#include <time.h>    //for current time and date
#include <fstream>   //file input and output
#include <iomanip>   //Header providing parametric manipulators
using namespace std;

int count = 0, count1 = 0, temp = 0, temp1 = 0;

// function used to place the cursor at a specific co-ordinate
void coor_pos(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// function for Sleep
void deLay(unsigned int msec)
{
    clock_t goal = msec + clock();
    while (goal > clock())
        ;
}

void messageBox()
{
    coor_pos(40, 8);
    cout << "\xc9";
    for (int i = 1; i <= 35; i++)
    {
        cout << "\xcd";
    }
    coor_pos(75, 8);
    cout << "\xbb";
    for (int i = 1; i <= 15; i++)
    {
        coor_pos(40, 8 + i);
        cout << "\xba";
        coor_pos(75, 8 + i);
        cout << "\xba";
    }
    coor_pos(40, 24);
    cout << "\xc8";
    for (int i = 1; i <= 34; i++)
    {
        cout << "\xcd";
    }
    cout << "\xbc";
}

// box drawing function in login and register page
void box_draw()
{
    coor_pos(50, 8);
    cout << "\xc9";
    for (int i = 1; i <= 20; i++)
    {
        cout << "\xcd";
    }
    coor_pos(70, 8);
    cout << "\xbb";
    for (int i = 1; i <= 1; i++)
    {
        coor_pos(50, 8 + i);
        cout << "\xba";
        coor_pos(70, 8 + i);
        cout << "\xba";
    }
    coor_pos(50, 10);
    cout << "\xc8";
    for (int i = 1; i <= 19; i++)
    {
        cout << "\xcd";
    }
    cout << "\xbc";
}

// Base class
class c_mail
{
private:
    string f_Name, l_Name, reg_username, log_username, msgText, regPass, logPass, phn, msg_username;
    char name[20];

public:
    void Loading();
    void mainMenu();
    void login();
    void Register();
    void Reg_rec_file();
    void login_validation();
    void message();
    void messageValidation();
    void home();
    void back();
    void messageLog();
    void clearLog();
    void ViewTeam();
    void Delete();
    // for user input login validation
    void username_Validation(string Username);
    void password_Validation(string Password);
};

// starting loading function
void c_mail::Loading()
{
    char n = 177;
    coor_pos(53, 14);
    cout << "Loading...";
    coor_pos(41, 15);
    for (int i = 0; i < 35; i++)
    {
        deLay(150);
        cout << n;
    }
}

void c_mail::mainMenu()
{
    system("cls");
    char n = 177;
    coor_pos(40, 9);
    for (int i = 0; i < 5; i++)
    {
        cout << n;
    }
    cout << "  Welcome to our C-mail Service  ";
    for (int i = 0; i < 5; i++)
    {
        cout << n;
    }
    coor_pos(42, 12);
    cout << "\xc9";
    for (int i = 1; i <= 38; i++)
    {
        cout << "\xcd";
    }
    coor_pos(80, 12);
    cout << "\xbb";
    for (int i = 1; i <= 10; i++)
    {
        coor_pos(42, 12 + i);
        cout << "\xba";
        coor_pos(80, 12 + i);
        cout << "\xba";
    }
    coor_pos(42, 23);
    cout << "\xc8";
    for (int i = 1; i <= 37; i++)
    {
        cout << "\xcd";
    }
    cout << "\xbc";
    coor_pos(35,34);
    cout << ">> If you are new to our service, Please register first.";
    coor_pos(35,35);
    cout << ">> Already a member\? You can directly Login.";
    coor_pos(50, 16);
    cout << "LOG IN";
    coor_pos(50, 19);
    cout << "REGISTER";
    coor_pos(50, 24);
    cout << "'L' for LOGIN";
    coor_pos(50, 26);
    cout << "'R' for REGISTER";
    coor_pos(50, 28);
    cout << "'T' for viewing Developer TEAMS";
    coor_pos(50,30);
    cout << "'E' for exiting the program";
    coor_pos(46, 32);
    cout << " Enter Your Choice: ";
    char c = toupper(getch());
    switch (c)
    {
    case 'L':
        login();
        break;
    case 'R':
        Register();
        break;
    case 'T':
        ViewTeam();
        break;
    case 'E':
        coor_pos(35,37);
        system("pause");
        exit(0);
    default:
        mainMenu();
        break;
    }
}

// login page function
void c_mail::login()
{
    system("cls");
    box_draw();
    coor_pos(55, 9);
    cout << "LOG-IN PAGE";
    // second box
    coor_pos(41, 12);
    cout << "\xc9";
    for (int i = 1; i <= 39; i++)
    {
        cout << "\xcd";
    }
    coor_pos(80, 12);
    cout << "\xbb";
    for (int i = 1; i <= 10; i++)
    {
        coor_pos(41, 12 + i);
        cout << "\xba";
        coor_pos(80, 12 + i);
        cout << "\xba";
    }
    coor_pos(41, 23);
    cout << "\xc8";
    for (int i = 1; i <= 38; i++)
    {
        cout << "\xcd";
    }
    cout << "\xbc";
    coor_pos(48, 16);
    cout << "Username: ";
    coor_pos(48, 18);
    cout << "Password: ";
    coor_pos(60, 16);
    cin >> log_username;
    username_Validation(log_username);
    if (temp == 0)
    {
        coor_pos(82, 16);
        cout << "Username doesn't exists.";
        coor_pos(48,24);
        getch();
        exit(4);
    }
    coor_pos(60, 18);
    int ch, n = 0;
    do
    {
        ch = getch();
        if (ch != 8 && isprint(ch))
        {
            cout << "*";
            name[n++] = ch;
        }
        if (ch == 8 && n)
        {
            name[n--] = '\0';
            cout << "\b \b";
        }
    } while (ch != 13);
    logPass = name;
    password_Validation(logPass);
    if (temp1 == 0)
    {
        coor_pos(82, 18);
        cout << "Invalid Password.";
        getch();
        exit(1);
    }
    login_validation();
    getch();
}

void c_mail::Register()
{

    system("cls");
    int m = 0, temp2 = 0;
    string user_, username[15];
    ifstream userfile;
    userfile.open("Username.txt");
    while (getline(userfile, user_))
    {
        username[m] = user_;
        m++;
    }
    box_draw();
    coor_pos(54, 9);
    cout << "REGISTER PAGE";
    // second box
    coor_pos(39, 12);
    cout << "\xc9";
    for (int i = 1; i <= 55; i++)
    {
        cout << "\xcd";
    }
    coor_pos(95, 12);
    cout << "\xbb";
    for (int i = 1; i <= 10; i++)
    {
        coor_pos(39, 12 + i);
        cout << "\xba";
        coor_pos(95, 12 + i);
        cout << "\xba";
    }
    coor_pos(39, 23);
    cout << "\xc8";
    for (int i = 1; i <= 55; i++)
    {
        cout << "\xcd";
    }
    cout << "\xbc";
    coor_pos(42, 24);
    cout << "Information:";
    coor_pos(41, 25);
    cout << ">> Username should be characters only.";
    coor_pos(41, 26);
    cout << ">> Password should be characters only.";
    // Entity
    coor_pos(42, 14);
    cout << "First Name :";
    coor_pos(68, 14);
    cout << "Last Name :";
    coor_pos(42, 16);
    cout << "phn      :";
    coor_pos(42, 18);
    cout << "Username   :";
    coor_pos(42, 20);
    cout << "Password   :";
    // Input Value
    coor_pos(55, 14);
    cin >> f_Name;
    coor_pos(80, 14);
    cin >> l_Name;
    coor_pos(55, 16);
    cin >> phn;
    coor_pos(55, 18);
    cin >> reg_username;
    for (int k = 0; k < m; k++)
    {
        if (reg_username.compare(username[k]) == 0)
        {
            temp2 = 1;
        }
    }
    if (temp2 == 1)
    {
        system("cls");
        coor_pos(40, 9);
        cout << "Username already exists. Please try another";
        getch();
        Register();
    }
    coor_pos(55, 20);
    cin >> regPass;
    Reg_rec_file();
    system("cls");
    coor_pos(40, 11);
    cout << "!!! Registered Successfully !!!";
    coor_pos(45, 13);
    cout << "Do you want to login\?";
    coor_pos(48, 15);
    cout << "1. Yes"
         << "\t\t\t"
         << "2. No";
    coor_pos(46, 17);
    cout << "Enter Your Choice: ";
    int ch = getch();
    switch (ch)
    {
    case '1':
        login();
        break;
    default:
        mainMenu();
        break;
    }
    getch();
}

// Function for viewing developers team
void c_mail::ViewTeam()
{
    system("cls");
    string view_team;
    ifstream view;
    view.open("TEAMS.txt");
    int b = 0;
    while (getline(view, view_team))
    {
        coor_pos(10, 5 + b);
        cout << view_team;
        b++;
    }
    getch();
    mainMenu();
}

// message deleting function
void c_mail::Delete()
{
    system("cls");
    coor_pos(35, 8);
    cout << "\xc9";
    for (int i = 1; i <= 38; i++)
    {
        cout << "\xcd";
    }
    coor_pos(73, 8);
    cout << "\xbb";
    for (int i = 1; i <= 30; i++)
    {
        coor_pos(35, 8 + i);
        cout << "\xba";
        coor_pos(73, 8 + i);
        cout << "\xba";
    }
    ofstream Delete;
    ifstream del;
    char showmsg;
    ifstream Nfile;
    Nfile.open((log_username + "-message").c_str());
    Nfile >> showmsg;
    del.open((log_username + "-message").c_str());
    if (!del || (showmsg == '\0'))
    {
        coor_pos(37, 12);
        cout << "You don't have any message to delete.";
    }
    else
    {
        Delete.open((log_username + "-message").c_str());
        Delete << "";
        coor_pos(37, 12);
        cout << "All message deleted successfully !";
    }
    back();
}

void c_mail::back()
{
    coor_pos(80, 11);
    cout << "Press 'B' to go back";
    coor_pos(80, 13);
    cout << "Press any other key to exit.";
    coor_pos(78, 15);
    cout << "Enter Your Choice: ";
    switch (getch())
    {
    case 'b':
        home();
        break;
    default:
        exit(0);
    }
}

// Home page after login
void c_mail::home()
{
    system("cls");
    coor_pos(41, 12);
    cout << "\xc9";
    for (int i = 1; i <= 39; i++)
    {
        cout << "\xcd";
    }
    coor_pos(80, 12);
    cout << "\xbb";
    for (int i = 1; i <= 10; i++)
    {
        coor_pos(41, 12 + i);
        cout << "\xba";
        coor_pos(80, 12 + i);
        cout << "\xba";
    }
    coor_pos(41, 23);
    cout << "\xc8";
    for (int i = 1; i <= 38; i++)
    {
        cout << "\xcd";
    }
    cout << "\xbc";
    coor_pos(43, 7);
    cout << "LOGGED IN !!!SUCCESSFULLY!!!";
    coor_pos(43, 8);
    cout << "____________________________";
    coor_pos(43, 10);
    cout << "Welcome, " << log_username;
    coor_pos(43, 14);
    cout << "1. For Showing message.";
    coor_pos(43, 15);
    cout << "2. For Sending message.";
    coor_pos(43, 16);
    cout << "3. For Deleting all receiced message.";
    coor_pos(43, 17);
    cout << "4. For Viewing sent Message Log";
    coor_pos(43, 18);
    cout << "5. For Clearing Log";
    coor_pos(43, 19);
    cout << "6. For Log Out";
    coor_pos(41, 22);
    cout << "Enter your choice: ";
    switch (getch())
    {
    case '1':
        messageValidation();
        break;
    case '2':
        message();
        break;
    case '3':
        Delete();
        break;
    case '4':
        messageLog();
        break;
    case '5':
        clearLog();
        break;
    case '6':
        system("cls");
        coor_pos(42, 10);
        cout << "Logging Out";
        for (int i = 0; i <= 10; i++)
        {
            coor_pos(54 + i, 10);
            deLay(150);
            cout << ".";
        }
        mainMenu();
        break;
    default:
        home();
        break;
    }
}
// clearing log
void c_mail::clearLog()
{
    system("cls");
    coor_pos(35, 8);
    cout << "\xc9";
    for (int i = 1; i <= 38; i++)
    {
        cout << "\xcd";
    }
    coor_pos(73, 8);
    cout << "\xbb";
    for (int i = 1; i <= 30; i++)
    {
        coor_pos(35, 8 + i);
        cout << "\xba";
        coor_pos(73, 8 + i);
        cout << "\xba";
    }
    ofstream Delete;
    ifstream del;
    char showmsg;
    ifstream Nfile;
    Nfile.open((log_username + "-log").c_str());
    Nfile >> showmsg;
    del.open((log_username + "-log").c_str());
    if (!del || (showmsg == '\0'))
    {
        coor_pos(37, 12);
        cout << "No message in the log.";
    }
    else
    {
        Delete.open((log_username + "-log").c_str());
        Delete << "";
        coor_pos(37, 12);
        cout << "All log cleared successfully";
    }
    back();
}

// Function for showing message
void c_mail::messageValidation()
{
    system("cls");
    coor_pos(35, 8);
    cout << "\xc9";
    for (int i = 1; i <= 38; i++)
    {
        cout << "\xcd";
    }
    coor_pos(73, 8);
    cout << "\xbb";
    for (int i = 1; i <= 30; i++)
    {
        coor_pos(35, 8 + i);
        cout << "\xba";
        coor_pos(73, 8 + i);
        cout << "\xba";
    }
    string showmsg;
    char text;
    ifstream Nfile, Kfile;
    Nfile.open((log_username + "-message").c_str());
    Kfile.open((log_username + "-message").c_str());
    int k = 0;
    Kfile >> text;
    if (!Nfile && !Kfile)
    {
        coor_pos(44, 15);
        cout << "No message received yet.!!!";
    }
    else if (text == '\0')
    {
        coor_pos(44, 15);
        cout << "No Messages.";
    }
    else
    {
        while (getline(Nfile, showmsg))
        {
            coor_pos(37, 12 + k);
            cout << showmsg;
            k++;
        }
    }
    Nfile.close();
    coor_pos(80, 10);
    cout << "Press 'B' to go back";
    coor_pos(80, 12);
    cout << "Press 'R' to refresh";
    coor_pos(80, 14);
    cout << "Press any other key to exit ";
    coor_pos(78, 17);
    cout << "Enter Your Choice: ";
    switch (getch())
    {
    case 'b':
        home();
        break;
    case 'r':
        messageValidation();
        break;
    default:
        exit(0);
    }
}

// username validation
void c_mail::username_Validation(string Username)
{
    int m = 0;
    temp = 0;
    string user, username[15];
    ifstream userfile;
    userfile.open("Username.txt");
    while (getline(userfile, user))
    {
        username[m] = user;
        m++;
    }
    for (int k = 0; k < m; k++)
    {
        if (Username.compare(username[k]) == 0)
        {
            temp = 1;
            break;
        }
    }
}

// password validation
void c_mail::password_Validation(string Password)
{
    int n = 0;
    temp1 = 0;
    string pass, password[15];
    ifstream passfile;
    passfile.open("Password.txt");
    while (getline(passfile, pass))
    {
        password[n] = pass;
        n++;
    }
    for (int k = 0; k < n; k++)
    {
        if (Password.compare(password[k]) == 0)
        {
            temp1 = 1;
            break;
        }
    }
}

// login function
void c_mail::login_validation()
{
    system("cls");
    string password;
    string username;
    ifstream Lfile;
    ifstream Mfile;
    Lfile.open("Username.txt");
    Mfile.open("Password.txt");
    if (!Lfile || !Mfile)
    {
        cout << "Register first to login";
    }
    else
    {
        while (getline(Lfile, username))
        {
            if (log_username.compare(username) == 0)
            {
                while (getline(Mfile, password))
                {
                    if (logPass.compare(password) == 0 && count == count1)
                    {
                        system("cls");
                        coor_pos(42, 10);
                        cout << "Logging in";
                        for (int i = 0; i <= 15; i++)
                        {
                            coor_pos(54 + i, 10);
                            deLay(150);
                            cout << ".";
                        }
                        home();
                        break;
                    }
                    count1++;
                }
            }
            count++;
        }
        Mfile.close();
        Lfile.close();
    }
}

// Writing in REG entries file, username file & password file
void c_mail::Reg_rec_file()
{
    ofstream myfile, Ufile, Pfile;
    myfile.open("REG-Entries.txt", ios::app);
    Ufile.open("Username.txt", ios::app);
    Pfile.open("Password.txt", ios::app);
    myfile << f_Name << " " << l_Name << "\t" << reg_username << "\t" << phn << endl;
    Ufile << reg_username << endl;
    Pfile << regPass << endl;
}

// for viewing message log
void c_mail::messageLog()
{
    system("cls");
    coor_pos(35, 8);
    cout << "\xc9";
    for (int i = 1; i <= 38; i++)
    {
        cout << "\xcd";
    }
    coor_pos(73, 8);
    cout << "\xbb";
    for (int i = 1; i <= 30; i++)
    {
        coor_pos(35, 8 + i);
        cout << "\xba";
        coor_pos(73, 8 + i);
        cout << "\xba";
    }
    string showmsg;
    ifstream Nfile;
    Nfile.open((log_username + "-log").c_str());
    int k = 0;
    if (!Nfile)
    {
        coor_pos(38, 15);
        cout << "You haven't send any message yet.!";
    }
    else
    {
        while (getline(Nfile, showmsg))
        {
            coor_pos(37, 12 + k);
            cout << showmsg;
            k++;
        }
    }
    Nfile.close();
    coor_pos(80, 10);
    cout << "Press 'B' to go back";
    coor_pos(80, 12);
    cout << "Press 'R' to refresh";
    coor_pos(80, 14);
    cout << "Press any other key to exit.";
    coor_pos(78, 17);
    cout << "Enter Your Choice: ";
    switch (getch())
    {
    case 'b':
        home();
        break;
    case 'r':
        messageValidation();
        break;
    default:
        exit(0);
    }
}

// sending message function
void c_mail::message()
{
    system("cls");
    messageBox();
    time_t t;
    time(&t);
    string s;
    string times = ctime(&t);
    coor_pos(40, 4);
    cout << "Send To (Username):";
    coor_pos(40, 7);
    cout << "Message Text Below";
    coor_pos(61, 4);
    cin >> msg_username;
    string receiver;
    ofstream mymessage, mlog;
    ifstream Rfile;
    Rfile.open("Username.txt");
    mlog.open((log_username + "-log").c_str(), ios::app);
    while (getline(Rfile, receiver))
    {
        if (msg_username.compare(receiver) == 0 && msg_username.compare(log_username) != 0)
        {
            mymessage.open((msg_username + "-message").c_str(), ios::app);
            getline(cin,s);
            coor_pos(43, 9);
            getline(cin, msgText);
            mymessage << "FROM : " << log_username << endl;
            mymessage << "MESSAGE:" << endl
                      << msgText << endl
                      << "RECEIVED" << endl
                      << times << endl;
            mlog << "To: " << msg_username << endl
                 << "MESSAGE:" << endl
                 << msgText << endl;
            system("cls");
            coor_pos(40, 8);
            cout << "Message sent successfully to " << msg_username;
            back();
            break;
        }
    }
}

int main()
{
    c_mail C;
    C.Loading();
    C.mainMenu();
    getch();
    return 0;
}
