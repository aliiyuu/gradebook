#include <stdio.h>
#include <string.h> //to use strcmp function and compare ascii values
#define SIZE 100 //define size of student array

struct student
{
    char name[20];
    int midterm;
    int final;
}; //define the student data type

//function prototypes
int menu(void); //function to display menu
void checkPassWord(void); //function to check password
void addStudent(struct student arr[], int *currentPtr); //function to add students to array
void removeStudent(struct student arr[], int *currentPtr); //function to remove students from array
void display(struct student arr[], int *currentPtr); //function to display student names and scores in tabular format
void sortName(struct student arr[], int *currentPtr); //sort data in alphabetical order
void sortMidterm(struct student arr[], int *currentPtr); //sort data in ascending order based on midterms
void sortFinal(struct student arr[], int *currentPtr); //sort data in ascending order based on finals
void findMedian(struct student arr[], int *currentPtr); //calculate median value of data
void findAvg(struct student arr[], int *currentPtr); //finds average

int main(int argc, const char * argv[]) {
    int choice; //input by user; selects which action is performed
    int done = 0; //flag value that controls  menu loop
    struct student list[SIZE] = {0}; //initialize elements of student array to 0
    
    int currentSize = 0; //initialize current class size to 0
    int *currentPtr = &currentSize; //create pointer to class size variable
    
    checkPassWord(); //prompt user for password
    
    //do-while loop causes menu to be displayed and switch statements to be executed as long as done is equal to 0
    do {
        choice = menu(); //get choice from menu function
        switch (choice)
        {
            case 1:
                checkPassWord(); //check password if user inputs 1
                break;
            
            case 2:
                addStudent(list, currentPtr); //add a student if user inputs 2
                break;
            
            case 3:
                removeStudent(list, currentPtr); //remove a student if user inputs 3
                break;
                
            case 4:
                display(list, currentPtr); //display data in tabular format if user inputs 4
                break;
                
            case 5:
                sortName(list, currentPtr); //sort in alphabetical order if user inputs 5
                break;
                
            case 6:
                sortMidterm(list, currentPtr); //sort in ascending order based on midterm if user inputs 6
                break;
                
            case 7:
                sortFinal(list, currentPtr); //sort in ascending order based on final if user inputs 7
                printf("Successfully sorted by final (type 4 to display)\n"); //alert message is here because this function is called to find the median
                break;
                
            case 8:
                findMedian(list, currentPtr); //find median score on final exam if user inputs 8
                break;
                
            case 9:
                findAvg(list, currentPtr); //find average score on final exam if user inputs 9
                break;
                
            case 10:
                done = 1; //set flag value to 1 to stop loop
                break;
                
            default:
                printf("Please enter a value between 1 and 10.\n"); //input validation
                break;
        }
    } while (done == 0);
    
    return 0;
}

int menu(void)
{
    //display menu
    puts("");
    printf("1 to enter password\n");
    printf("2 to add a student to the array\n");
    printf("3 to remove a student from the array\n");
    printf("4 to display the array in table format\n");
    printf("5 to sort based on names\n");
    printf("6 to sort based on midterms\n");
    printf("7 to sort based on finals\n");
    printf("8 to calculate median\n");
    printf("9 to calculate average\n");
    printf("10 to exit program\n");
    puts("");
    
    //scan to get user input and return an integer value to main
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

void checkPassWord(void)
{
    char actualpw[] = "pass123"; //correct password
    char password[1000]; //string array with 1000 characters to ensure users do not write outside of the array
    
        //ask for password from user
        printf("Enter password: ");
        scanf("%s", password);
      
    //if user input does not equal correct password, keep asking until strings are equal
        while (strcmp(actualpw, password) != 0)
        {
            printf("Incorrect password\n");
            puts("");
            printf("Enter password: ");
            scanf("%s", password);
        }
}

void addStudent(struct student arr[], int *currentPtr)
{
    //ask for name, midterm, and final
        printf("Enter name: ");
        scanf("%s", arr[*currentPtr].name);
        printf("Enter midterm: ");
        scanf("%d", &arr[*currentPtr].midterm);
        printf("Enter final: ");
        scanf("%d", &arr[*currentPtr].final);
        
    //increment class size
    *currentPtr = *currentPtr + 1;
}

void removeStudent(struct student arr[], int *currentPtr)
{
    int number; //assign students numbers (for identification purposes)
    printf("Enter number of student you want to remove (1 to the total number of students in the class) "); //ask for number
    scanf("%d", &number);
    if (number < 0 || number > *currentPtr) //input validation
        printf("Not allowed; enter a valid number between 1 and %d\n", *currentPtr);
    //copy values of the array to the left
    else
    {
        for (int i = number-1; i < *currentPtr-1; i++)
        {
            arr[i] = arr[i+1];
        }
        *currentPtr = *currentPtr - 1; //decrease current class size by 1
        printf("Successfully removed\n");
    }
}

void display(struct student arr[], int *currentPtr)
{
    //print headers (+ student numbers so they are easier to identify and remove)
    printf("%10s%10s%10s%10s\n", "NUMBER", "NAME", "MIDTERM", "FINAL");
    
    //print name, midterm, and final in tabular format
    for(int i = 0; i < *currentPtr; i++)
    {
        printf("%10d%10s%10d%10d\n", i+1, arr[i].name, arr[i].midterm, arr[i].final);
    }
}

void sortName(struct student arr[], int *currentPtr)
{
    //bubble sort by ascii values (alphabetical order)
    for (int pass = 1; pass < *currentPtr; pass++)
    {
        for (size_t i = 0; i < *currentPtr-1; i++)
        {
            if ((strcmp(arr[i].name, arr[i+1].name)) > 0)
            {
                struct student temp = arr[i]; //swaps the values of the array (all members of the structure are swapped simultaneously)
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    printf("Successfully sorted by name (type 4 to display)\n");
}

void sortMidterm(struct student arr[], int *currentPtr)
{
    //bubble sort by midterm scores (ascending order)
    for (int pass = 1; pass < *currentPtr; pass++)
    {
        for (size_t i = 0; i < *currentPtr-1; i++)
        {
            if (arr[i].midterm > arr[i+1].midterm)
            {
                struct student temp = arr[i]; //swaps the values of the array (all members of the structure are swapped simultaneously)
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    printf("Successfully sorted by midterm (type 4 to display)\n");
}

void sortFinal(struct student arr[], int *currentPtr)
{
    //bubble sort by final exam scores (ascending order)
    for (int pass = 1; pass < *currentPtr; pass++)
    {
        for (size_t i = 0; i < *currentPtr-1; i++)
        {
            if (arr[i].final > arr[i+1].final)
            {
                struct student temp = arr[i]; //swaps the values of the array (all members of the structure are swapped simultaneously)
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

void findMedian(struct student arr[], int *currentPtr)
{
    double median; //declare median variable
    
    sortFinal(arr, currentPtr); //sort based on final exams to get data in ascending order
   
    if (*currentPtr % 2 == 1) //odd number of students
    {
        median = arr[*currentPtr/2].final;
    }
    else //even number of students
    {
        median = (double) ((arr[*currentPtr/2].final + arr[*currentPtr/2+1].final)/2);
    }
    printf("The median score on the final exam is %.2f\n", median); //print median value
}

void findAvg(struct student arr[], int *currentPtr)
{
    double sum = 0; //declare sum variable and initialize to 0
    for (int i = 0; i < *currentPtr; i++) //for loop to add final exam scores
    {
        sum = sum + arr[i].final;
    }
    
    double average = (double) sum / *currentPtr; //calculate average
    printf("The average score on the final exam is %.2f\n", average); //print average
}
