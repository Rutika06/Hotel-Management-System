#include <iostream>
#include <string.h>
#include <conio.h>
#define max_rooms 100
using namespace std;

class Guest
{
public:
    char guest_name[100];
    char guest_address[100];
    char guest_phone[12];
    char start_date[20];
    char end_date[20];
    float advance_payment;
    int reservation_id;
};

class Accommodation
{
public:
    char air_conditioning;
    char comfort_type;
    char size_type;
    int room_no;
    int daily_rate;
    int room_status;

    class Guest guest_info;
    class Accommodation addAccommodation(int);
    void findAccommodation(int);
    void removeAccommodation(int);
    void displayAccommodation(Accommodation);
};

class Accommodation accommodations[max_rooms];
int room_count = 0;

Accommodation Accommodation::addAccommodation(int room_no)
{
    class Accommodation accommodation;
    accommodation.room_no = room_no;
    cout << "\nType AC/Non-AC (A/N): ";
    cin >> accommodation.air_conditioning;
    cout << "\nType Comfort (S/N): ";
    cin >> accommodation.comfort_type;
    cout << "\nType Size (B/S): ";
    cin >> accommodation.size_type;
    cout << "\nDaily Rent: ";
    cin >> accommodation.daily_rate;
    accommodation.room_status = 0;

    cout << "\n Room Added Successfully!";
    getch();
    return accommodation;
}

void Accommodation::findAccommodation(int room_no)
{
    int i, found = 0;
    for (i = 0; i < room_count; i++)
    {
        if (accommodations[i].room_no == room_no)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "Room Details\n";
        if (accommodations[i].room_status == 1)
        {
            cout << "\nRoom is Reserved";
        }
        else
        {
            cout << "\nRoom is available";
        }
        displayAccommodation(accommodations[i]);
        getch();
    }
    else
    {
        cout << "\nRoom not found";
        getch();
    }
}

void Accommodation::displayAccommodation(Accommodation tempAccommodation)
{
    cout << "\nRoom Number: \t" << tempAccommodation.room_no;
    cout << "\nType AC/Non-AC (A/N) " << tempAccommodation.air_conditioning;
    cout << "\nType Comfort (S/N) " << tempAccommodation.comfort_type;
    cout << "\nType Size (B/S) " << tempAccommodation.size_type;
    cout << "\nRent: " << tempAccommodation.daily_rate;
}

class HotelManagement : protected Accommodation
{
public:
    void checkIn();
    void getAvailableAccommodation();
    void searchGuest(char *);
    void checkOut(int);
    void guestReport();
};

void HotelManagement::guestReport()
{
    if (room_count == 0)
    {
        cout << "\n No Guest in Hotel !!";
    }
    for (int i = 0; i < room_count; i++)
    {
        if (accommodations[i].room_status == 1)
        {
            cout << "\n Guest First Name : " << accommodations[i].guest_info.guest_name;
            cout << "\n Room Number : " << accommodations[i].room_no;
            cout << "\n Address (only city) : " << accommodations[i].guest_info.guest_address;
            cout << "\n Phone : " << accommodations[i].guest_info.guest_phone;
            cout << "\n---------------------------------------";
        }
    }
    getch();
}

void HotelManagement::checkIn()
{
    int i, found = 0, room_no;

    class Accommodation accommodation;
    cout << "\nEnter Room number: ";
    cin >> room_no;
    for (i = 0; i < room_count; i++)
    {
        if (accommodations[i].room_no == room_no)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        if (accommodations[i].room_status == 1)
        {
            cout << "\nRoom is already Booked";
            getch();
            return;
        }

        cout << "\nEnter reservation id: ";
        cin >> accommodations[i].guest_info.reservation_id;

        cout << "\nEnter Guest Name (First Name): ";
        cin >> accommodations[i].guest_info.guest_name;

        cout << "\nEnter Address (only city): ";
        cin >> accommodations[i].guest_info.guest_address;

        cout << "\nEnter Phone: ";
        cin >> accommodations[i].guest_info.guest_phone;

        cout << "\nEnter From Date: ";
        cin >> accommodations[i].guest_info.start_date;

        cout << "\nEnter to Date: ";
        cin >> accommodations[i].guest_info.end_date;

        cout << "\nEnter Advance Payment: ";
        cin >> accommodations[i].guest_info.advance_payment;

        accommodations[i].room_status = 1;

        cout << "\n Guest Checked-in Successfully..";
        getch();
    }
}

void HotelManagement::getAvailableAccommodation()
{
    int i, found = 0;
    for (i = 0; i < room_count; i++)
    {
        if (accommodations[i].room_status == 0)
        {
            displayAccommodation(accommodations[i]);
            cout << "\n\nPress enter for next room";
            found = 1;
            getch();
        }
    }
    if (found == 0)
    {
        cout << "\nAll rooms are reserved";
        getch();
    }
}

void HotelManagement::searchGuest(char *guest_name)
{
    int i, found = 0;
    for (i = 0; i < room_count; i++)
    {
        if (accommodations[i].room_status == 1 && stricmp(accommodations[i].guest_info.guest_name, guest_name) == 0)
        {
            cout << "\nGuest Name: " << accommodations[i].guest_info.guest_name;
            cout << "\nRoom Number: " << accommodations[i].room_no;

            cout << "\n\nPress enter for next record";
            found = 1;
            getch();
        }
    }
    if (found == 0)
    {
        cout << "\nPerson not found.";
        getch();
    }
}

void HotelManagement::checkOut(int room_no)
{
    int i, found = 0, days;
    float bill_amount = 0;
    for (i = 0; i < room_count; i++)
    {
        if (accommodations[i].room_status == 1 && accommodations[i].room_no == room_no)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "\nEnter Number of Days:\t";
        cin >> days;
        bill_amount = days * accommodations[i].daily_rate;

        cout << "\n\t######## CheckOut Details ########\n";
        cout << "\nGuest Name : " << accommodations[i].guest_info.guest_name;
        cout << "\nRoom Number : " << accommodations[i].room_no;
        cout << "\nAddress : " << accommodations[i].guest_info.guest_address;
        cout << "\nPhone : " << accommodations[i].guest_info.guest_phone;
        cout << "\nTotal Amount Due : " << bill_amount << " /";
        cout << "\nAdvance Paid: " << accommodations[i].guest_info.advance_payment << " /";
        cout << "\n*** Total Payable: " << bill_amount - accommodations[i].guest_info.advance_payment << "/ only";

        accommodations[i].room_status = 0;
    }
    getch();
}

void manageAccommodations()
{
    class Accommodation accommodation;
    int opt, room_no, i, flag = 0;
    do
    {
        system("cls");
        cout << "\n### Manage Rooms ###";
        cout << "\n1. Add Room";
        cout << "\n2. Search Room";
        cout << "\n3. Back to Main Menu";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "\nEnter Room Number: ";
            cin >> room_no;
            for (i = 0; i < room_count; i++)
            {
                if (accommodations[i].room_no == room_no)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                cout << "\nRoom Number is Present.\nPlease enter unique Number";
                flag = 0;
                getch();
            }
            else
            {
                accommodations[room_count] = accommodation.addAccommodation(room_no);
                room_count++;
            }
            break;
        case 2:
            cout << "\nEnter room number: ";
            cin >> room_no;
            accommodation.findAccommodation(room_no);
            break;
        case 3:
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 3);
}

int main()
{
    class HotelManagement hotel_mgmt;
    int opt, room_no;
    char guest_name[100];

    system("cls");

    do
    {
        system("cls");
        cout << "######## Hotel Management #########\n";
        cout << "\n1. Manage Rooms";
        cout << "\n2. Check-In Room";
        cout << "\n3. Available Rooms";
        cout << "\n4. Search Guest";
        cout << "\n5. Check-Out Room";
        cout << "\n6. Guest Summary Report";
        cout << "\n7. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            manageAccommodations();
            break;
        case 2:
            if (room_count == 0)
            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";
                getch();
            }
            else
                hotel_mgmt.checkIn();
            break;
        case 3:
            if (room_count == 0)
            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";
                getch();
            }
            else
                hotel_mgmt.getAvailableAccommodation();
            break;
        case 4:
            if (room_count == 0)
            {
                cout << "\nRooms are not available.\nPlease add the rooms first.";
                getch();
            }
            else
            {
                cout << "Enter Guest Name: ";
                cin >> guest_name;
                hotel_mgmt.searchGuest(guest_name);
            }
            break;
        case 5:
            if (room_count == 0)
            {
                cout << "\nRooms are not available.\nPlease add the rooms first.";
                getch();
            }
            else
            {
                cout << "Enter Room Number : ";
                cin >> room_no;
                hotel_mgmt.checkOut(room_no);
            }
            break;
        case 6:
            hotel_mgmt.guestReport();
            break;
        case 7:
            cout << "\nTHANK YOU! FOR USING SOFTWARE";
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 7);

    getch();
}
