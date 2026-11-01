# Lab 11 - Project Application

## E1 - Original collection and borrowed pointers
Describe orders, view, and which array stores the actual records.
Orders is an array of OrderPreview objects. It stores the actual orders(ID, type,status,building and priority), and it owns them.
View is an array of Order Preview *. It stores only the addreesses of the selected orders in orders. It does not copy the objects.
## E2 - Implemented view and test
Describe the four dummy cases, the expected selected IDs, and the observed IDs.
Explain how you checked that original data and storage order were preserved.
The four dummy orders cover these cases:
- Order101 (DELIVERY,PENDING): expected in the view, because its an active delivery.
- Order102 (DELIVERY,COMPLETED): expected to not be in the view, because its an completed delivery.
- Order103 (DELIVERY,IN-PROGRESS): expected in the view, because its an active delivery.
- Order102 (DINE IN,PENDING): expected to not be in the view, because its not a delivery.
The expected selcted IDs are: 101 and 103.

To check the original data sorage order were preserved, the program saves the IDs and their status in orders in two helper arrays before the view. After the view is built, it prints Orders again and compares every position against the saved values.

## E3 - Sorting criterion and next integration step
State the three comparison rules and give a small example of their expected order.
Identify the remaining integration work, if any.
The comparatofor the tamporary report will use threee rules, in this order:
1. Building:Alphabetical order.
2. Priority: Decending with the higher priority first within the same building.
3. Order ID: ascending when building and priority are tied.
Example:
- Order 201: building A, priority 2
- Order 202: Building B, priority 5
- Order 203: Building A, priority 5
- Order 204: Building A, priority 2
Expected report order: 
1. 203
2. 201
3. 204
4. 202
Remaining integration work: 
The sort will connect to view right after the selection loop, once view and viewCount are filled and before the report is printed. The merge sort will receive view and viewCount and will reorder only the pointers. The orders array will not be touched. What remains to do its compare OrderPreview* values with these three rules, and then testing it.

## E4 - Lab evidence
Source file: delivery_view_practice.cpp
Test output: delivery_view_output.txt
Explain how this practice prepares the project's temporary report.
This is a good practice to see how the we can intregreted  merge sort in the final project. 

This is because:
- It separates the two needs of the cafeteria.
- The operational collection keeps the orders in their original sequence, so the FIFO order is never affected.
- The report works on a separate array of borrowed pointers that contains only active DELIVERY orders, so it can be filtered and, in the next step, sorted by building, priority and ID without changing the original collection.