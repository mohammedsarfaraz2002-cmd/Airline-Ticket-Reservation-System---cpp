#include <iostream>
#include <cctype>
using namespace std;

bool isSeatAvailable(char  seats[][6], int r, int c)
{
    return seats[r][c] == '*'; //empty seats will have a *.
}

void printSeatingChart(char  seats[][6], char seat_class[])
{
    cout << "\t\t";
    for (char n = 'A'; n <= 'F'; n++) //this function is for the seat numbers from A-F.
    {
        cout << n << "\t";
    }
    cout << "\n\n";
    for (int i = 0; i < 13; i++)
    { //this is for the rows. From rows 1-13.
        cout << seat_class[i] << "\t" << "Row" << i + 1 << "\t"; //it will also display the word 'row'.
        for (int j = 0; j < 6; j++)
        {
            cout << seats[i][j] << "\t";
        }
        cout << "\n";
    }
}

char reserve(char  seats[][6])
{
    cout << "The train has 13 rows, with 6 seats in each row.\n"; //giving user information.

    int ticket_type = 0;
    int row_number = -1;
    int seat_number = -1;

    char t_type;
    while (true)
    {

        cout << "Enter ticket type:\n";
        cout << "F for First class\n";
        cout << "B for Business class\n";
        cout << "E for Economy class\n";

        cin >> t_type;

        if (t_type == 'f' or t_type == 'F')
        {
            ticket_type = 1;
            cout << "Row 1 and 2 are for First class....\n";
        }

        if (t_type == 'b' or t_type == 'B')
        {
            ticket_type = 2;
            cout << "Row 3 to 5 are for Business class....\n";
        }

        if (t_type == 'e' or t_type == 'E')
        {
            ticket_type = 3;
            cout << "Row 6 to 13 are for Economy class....\n";
        }

        if (ticket_type != 0)
            break;
        else
            cout << "Invalid ticket Type!!!\n";
    }

    cout << "Enter row number (based on your ticket class):\n";

    while (true)
    {

        int rnbr;
        cin >> rnbr;

        if (ticket_type == 1 and (rnbr >= 1 and rnbr <= 2))
        {
            row_number = rnbr;
        }

        if (ticket_type == 2 and (rnbr >= 3 and rnbr <= 5))
        {
            row_number = rnbr;
        }

        if (ticket_type == 3 and (rnbr >= 6 and rnbr <= 13))
        {
            row_number = rnbr;
        }

        if (row_number != -1)
        {
            break;
        }
        else
            cout << "Please enter a row number which belongs to the current type:\t";
    }

    cout << "Enter the seat number from A to F\n";

    while (true)
    {

        char s_num;
        cin >> s_num;

        if ((s_num >= 'A' and s_num <= 'F') or (s_num >= 'a' and s_num <= 'f'))
        {

            if (!isSeatAvailable(seats, row_number - 1, (char)tolower(s_num) - 'a'))
            {
                cout << "This seat is already assigned, please choose another seat: ";
            }
            else
            {
                seats[row_number - 1][(char)tolower(s_num) - 'a'] = 'X';
                break;
            }
        }
    }

    return t_type;
}

void calculate(int f_class, int b_class, int e_class)
{
    cout << "Booking summary\n";

    int total = 0;

    if (f_class != 0)
    {
        cout << "First class  tickets\t\t" << f_class << " x 400\n";
        total += f_class * 400;
    }

    if (b_class != 0)
    {
        cout << "Business class  tickets\t\t" << b_class << " x 300\n";
        total += b_class * 300;
    }

    if (e_class != 0)
    {
        cout << "Economy class  tickets\t\t" << e_class << " x 100\n";
        total += e_class * 100;
    }

    cout << "------------------------------------------------------\n";
    cout << "Total price for your order\t" << total;
}

int main()
{

    int  f_class = 0;
    int  b_class = 0;
    int  e_class = 0;

    char seat_class[] = { 'F', 'F', 'B', 'B', 'B', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E' };

    char seats[][6] = {
                {'*', '*', '*', '*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'},
                {'*','*','*','*','*','*'}
    };

    cout << "price of First class ticket is $400\n";
    cout << "price of Business class ticket is $300\n";
    cout << "price of Economy class ticket is $100\n";

    printSeatingChart(seats, seat_class);

    char choice;

    cout << "Do you want to start a booking now?  Y/y for yes and N/n for no\n";
    cin >> choice;

    if (choice == 'Y' or choice == 'y')
    {
        while (true)
        {
            char selection = reserve(seats);

            if (selection == 'f' or selection == 'F')
            {
                f_class++;
            }
            else if (selection == 'b' or selection == 'B')
            {
                b_class++;
            }
            else
            {
                e_class++;
            }

            cout << "do you want continue? Y/y for yes and N/n for no and p for print\n";
            cin >> choice;

            if (choice == 'P' or choice == 'p')
            {
                printSeatingChart(seats, seat_class);

                cout << "do you want continue? Y/y for yes and N/n for no.\n";
                cin >> choice;

                if (choice == 'N' or choice == 'n')
                {
                    calculate(f_class, b_class, e_class);
                    break;
                }
            }

            if (choice == 'N' or choice == 'n')
            {
                calculate(f_class, b_class, e_class);
                break;
            }
        }
    }

    return 0;
}