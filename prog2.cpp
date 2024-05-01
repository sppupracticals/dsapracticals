/*
Subject : DSA Laboratory
Class : SE Computer Engineering
Practical No: 02 - "A C++ Program to implement Set an ADT using Hash Table"
 a) Insert Elements in Set
 b) Search Elements in Set
 c) Delete Elements from Set
 d) Union of two Sets
 e) Intersection of two Sets
 f) Difference of two Sets
*/


#include <iostream>
using namespace std;
 
int HT1[10]; 
int HT2[10];
int size = 10;
 
void init ()
{
 for (int i = 0; i < size; i++)
 {
 HT1[i] = 0;
 HT2[i] = 0;
 }
}
void display ()
{
 int i;
 cout << "\n\t ------Hash Table - 01 ------";
 cout << "\n\t Index - Key";
 for (int i = 0; i < size; i++)
 {
 cout << "\n\t " << i << "\t " << HT1[i];
 }
 cout << "\n\t ------Hash Table - 02 ------";
 cout << "\n\t Index - Key";
 for (int i = 0; i < size; i++)
 {
    cout << "\n\t " << i << "\t " << HT2[i];
 }
}
void insert_SetA (int key)
{
 int index;
 index = key % size; 
 HT1[index] = key;
}
void insert_SetB(int key)
{
 int index;

 index = key % size; 

 HT2[index] = key;
}
void search_SetA(int key)
{
 int index;

 cout<<"\n\n Searching "<<key<<" in Set A";
 index = key % size; 

 if(HT1[index] == key)
 cout<<"\n\t Key"<<key<<" Found at "<<index;
 else
 cout<<"\n\t Key"<<key<<" Not Found....!!!";
}
void search_SetB(int key)
{
 int index;

 cout<<"\n\n Searching "<<key<<" in Set B";
 index = key % size; 

 if(HT2[index] == key)
 cout<<"\n\t Key"<<key<<" Found at "<<index;
 else
 cout<<"\n\t Key"<<key<<" Not Found....!!!";
}
void delete_SetA(int key)
{
 int index;

 cout<<"\n\n Deleting "<<key<<" from Set A";
 index = key % size; //....Hash Function: Division Method

 if(HT1[index] == key)
 {
 HT1[index] = 0;
 cout<<"\n\t Key"<<key<<" Found at "<<index<<" and Deleted.";
 }

 else
 cout<<"\n\t Key"<<key<<" Not Found....!!!";
}
void delete_SetB(int key)
{
 int index;

 cout<<"\n\n Deleting "<<key<<" from Set B";
 index = key % size; 

 if(HT2[index] == key)
 {
 HT2[index] = 0;
 cout<<"\n\t Key"<<key<<" Found at "<<index<<" and Deleted.";
 }

 else
 cout<<"\n\t Key"<<key<<" Not Found....!!!";
}
int dup(int val)
{
 int i, dupl = 0;

 for(i = 0; i < size; i++)
 {
 if(val == HT1[i])
 dupl = 1;
 }
 return dupl;
}
void unionAB()
{
 int i, j;
 int C[10];

 j = 0;

 for(i = 0; i < size; i++)
 {
 if(HT1[i] != 0) 
 {
 C[j] = HT1[i];
 j++;
 }
 }
 for(i = 0; i < size; i++)
 {
 if(HT2[i] != 0) 
 {
 if(dup(HT2[i]) == 0)
 {
 C[j] = HT2[i];
 j++;
 }
 }
 }

 cout<<"\n\t Union of SET-A,B = ";
 for(i = 0; i < j; i++)
 cout<<C[i]<<", ";

}
int main ()
{
 cout << "--- A C++ Program to implement Set an ADT using Hash Table --- ";
 init ();
 display ();

 insert_SetA(11);
 insert_SetA(13);
 insert_SetA(15);
 insert_SetA(17);
 insert_SetA(19);

 insert_SetB(12);
 insert_SetB(14);
 insert_SetB(16);
 insert_SetB(18);
  insert_SetB(20);

 display ();

 search_SetA(13);
 search_SetA(20);
 search_SetB(14);
 search_SetB(17);

 delete_SetA(11);
 delete_SetA(20);

 delete_SetB(14);
 delete_SetB(19);

 display ();

 insert_SetA(20);
 display ();
 unionAB();

 return 0;
}
