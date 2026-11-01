/*
 * Course: COEN 2220 - Programming 2
 * Name: [Sebastian Ortiz]
 * Lab: Lab 11 - Recursion and Merge Sort
 * Description: Practice building a temporary view of active delivery orders
 * Due date: [11/1/2026]
 */

#include <iostream>
#include <string>
using namespace std;

struct OrderPreview
{
    int orderId;
    string orderType;
    string status;
    string building;
    int priority;
};
// prints the orders
void printorder(const OrderPreview orders[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        cout << "Order ID: " << orders[i].orderId
             << " | Type: " << orders[i].orderType
             << " | Status: " << orders[i].status
             << " | Building: " << orders[i].building
             << " | Priority: " << orders[i].priority << endl;
    }
}
const int SIZE = 4;
int main()
{
    OrderPreview orders[SIZE] = {
        {101, "Delivery", "Pending", "Building A", 1},
        {102, "Pickup", "Completed", "Building B", 2},
        {103, "Delivery", "In Progress", "Building C", 3},
        {104, "Dine_In", "Pending", "Building D", 4}
    };

    OrderPreview *view[SIZE];
    int viewCount = 0;

    cout << "Original orders before building view:" << endl;
    printorder(orders, SIZE);

    int idBefore[SIZE];
    string statusBefore[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        idBefore[i] = orders[i].orderId;
        statusBefore[i] = orders[i].status;
    }
    for (int i = 0; i < SIZE; i++)  
    {
        if (orders[i].orderType == "Delivery" && 
        (orders[i].status == "Pending" || orders[i].status == "In Progress"))
        {
            view[viewCount++] = &orders[i];
        }
    }

    cout << "Active delivery orders in the view:" << viewCount << endl;
    for (int i = 0; i < viewCount; i++)
    {
        cout << "Order ID: " << view[i]->orderId
             << " | Type: " << view[i]->orderType
             << " | Status: " << view[i]->status
             << " | Building: " << view[i]->building
             << " | Priority: " << view[i]->priority << endl;
    }

    cout << "Orders after building view (should be unchanged):" << endl;
    printorder(orders, SIZE);
    cout << "Verifying that the original orders remain unchanged:" << endl;
    bool unchanged = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (orders[i].orderId != idBefore[i] || orders[i].status != statusBefore[i])
        {
            unchanged = false;
        }
    }
    if (unchanged)
    {
        cout << "All original orders remain unchanged." << endl;
    }
    else
    {
        cout << "Some original orders have been modified." << endl;
    }
    return 0;
}
