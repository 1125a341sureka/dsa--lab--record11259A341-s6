#include<stdio.h>
#define MAX 100
void traverse( int arr[], int n) {
printf("Array elements: ");
    for (int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}
int insert(int arr[], int n, int pos, int value) {
if (n >= MAX){
printf("Array isfull. Cannot insert.\n");
return n;
}
    if (pos < 0 || pos > n) {
printf("Invalid position.\n");
return n;
}
    for (int i = n; i > pos; i-- )
arr[i] = arr[i- 1];
arr[ pos] = value;
return n+ 1;
}
int delete(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
printf("Invalid position.\n");
return n;
}
    for (int i = pos; i < n- 1; i++)
arr[i] = arr[i + 1];
return n- 1;
}
int main() {
int arr[MAX], n, choice, pos, value;printf("Enter number ofelements: ");
scanf("%d", &n);
printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
scanf("%d", & arr[i]);
do{
printf("\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
                printf("Enterposition(0to%d)andvalue:",n);
                    scanf("%d %d", & pos,&value);
                n = insert(arr, n, pos,value);
                traverse(arr,n);
break;
case 2:
                printf("Enterpositiontodelete(0to%d):",n-1);
                scanf("%d", & pos);
                n = delete(arr, n, pos);
                traverse(arr,n);
break;
case  3:
                traverse(arr,n);
break;
case 4:
                printf("Exiting...\n");
break;
default:
                printf("Invalidchoice.\n");
}
}while(choice!=4);
return 0;
}
