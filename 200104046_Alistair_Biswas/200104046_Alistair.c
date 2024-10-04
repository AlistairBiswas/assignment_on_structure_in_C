#include<stdio.h>
#include<string.h>

struct user // Creating structure for user input.
{
    char email[100];
    char pass[100];
};

struct student // Creating structure for students information.
{
    struct user;
    char name[100];
    float cgpa;
    int id;
};

struct teacher // Creating structure for teachers information.
{
    struct user;
    char name[100];
    char designation[100];
};

int main ()
{
    int s1, t1;

    printf("How many students : ");
    scanf("%d", &s1); // Entering student number.

    printf("How many teachers : ");
    scanf("%d", &t1); // Entering teacher number.

    struct student student[s1];

    for (int i=0; i<s1; i++) // Entering all students information.
    {
        printf("\nEnter student %d Information : \n", i+1);

        printf("Name : ");
        fflush(stdin);
        gets(student[i].name);

        printf("Email : ");
        fflush(stdin);
        gets(student[i].email);

        printf("Enter password : ");
        fflush(stdin);
        gets(student[i].pass);

        printf("CGPA: ");
        scanf("%f", &student[i].cgpa);

        student[i].id = i+1;
    }

    struct teacher teacher[t1];

    for (int i=0; i<t1; i++) // Entering all teachers information.
    {
        printf("\nEnter teacher %d Information : \n", i+1);

        printf("Name : ");
        fflush(stdin);
        gets(teacher[i].name);

        printf("Email : ");
        fflush(stdin);
        gets(teacher[i].email);

        printf("Pass : ");
        fflush(stdin);
        gets(teacher[i].pass);

        printf("Designation : ");
        fflush(stdin);
        gets(teacher[i].designation);
    }

    while (1) // Creating infinite loop for "user input" as teacher or student until exit.
    {
        int n, flag=0, x;

        printf("\nSelect Option \n 1. Student \n 2. Teacher\n");

        printf("\nLogin as : ");
        scanf("%d", &n); // Selecting option for teacher or student

        struct user studentLogin, teacherLogin;

        if (n == 1) // Entering Login Information for student.
        {
            printf("\nEmail: ");
            fflush(stdin);
            gets(studentLogin.email);

            printf("Pass: ");
            fflush(stdin);
            gets(studentLogin.pass);

            for (int i=0; i<s1; i++)
            {
                int c1 = strcmp(studentLogin.email, student[i].email); // comparing email
                int c2 = strcmp(studentLogin.pass, student[i].pass); // comparing password

                if (c1 == 0 && c2 == 0) // Checking email and password form input
                {
                    flag = 1;
                    x = i; // putting the value of selected student,s index number in "x" variable.
                    break;
                }
            }

            if (flag == 0) // For invalid email or password.
            {
                printf("\nInvalid Password... Try again ! \n");
            }
            else
            {
                printf("\nLogin Successful !\n");

                while (1) // Creating infinite loop for selecting option until logout or exit.
                {
                    printf("\nOptions: \n 1. See Details\n 2. Edit Name\n 3. Edit Password\n 4. Logout\n 5. Exit\n");

                    int op_s;

                    printf("\nSelect Option : ");
                    scanf("%d", &op_s); // Selecting option for student after successfully Login.

                    if (op_s == 1) // Showing student's Information.
                    {
                        printf("\nID : %d\n", student[x].id);
                        printf("Name : %s\n", student[x].name);
                        printf("Email : %s\n", student[x].email);
                        printf("Pass : %s\n", student[x].pass);
                        printf("CGPA : %f\n", student[x].cgpa);
                    }
                    else if (op_s == 2) // Editing student's name.
                    {
                        printf("\nEnter new Name : ");
                        fflush(stdin);
                        gets(student[x].name);
                    }
                    else if (op_s == 3) // Editing student's password.
                    {
                        printf("\nEnter new Pass : ");
                        fflush(stdin);
                        gets(student[x].pass);
                    }
                    else if (op_s == 4) // Logout and end the infinite loop.
                    {
                        printf("\nLogout successfully !\n");
                        break;
                    }
                    else if (op_s == 5) // Exit and end the program.
                    {
                        return 0;
                    }
                    else // For invalid case.
                    {
                        printf("\nInvalid !!!\n");
                    }
                }
            }
        }
        else if (n == 2) // Entering Login Information for teacher.
        {
            int temp = 0;

            printf("\nEmail: ");
            fflush(stdin);
            gets(teacherLogin.email);

            printf("Pass: ");
            fflush(stdin);
            gets(teacherLogin.pass);

            for (int i=0; i<t1; i++)
            {
                int c3 = strcmp(teacherLogin.email, teacher[i].email); // Comparing email
                int c4 = strcmp(teacherLogin.pass, teacher[i].pass); // Comparing password

                if (c3 == 0 && c4 == 0) // Checking email and password from input.
                {
                    temp = 1;
                    break;
                }
            }

            if (temp == 0) // for invalid email or password
            {
                printf("\nInvalid Password... Try again ! \n");
            }
            else
            {
                printf("\nLogin Successful !\n");

                while (1) // Creating infinite loop for selecting option until logout or exit.
                {
                    printf("\nOptions: \n 1. See All Students\n 2. See All Teacher\n 3. Logout\n 4. Exit\n");

                    int op_t;

                    printf("\nSelect Option : ");
                    scanf("%d", &op_t); // Selecting options after login successfully.

                    if (op_t == 1) // Showing all Students Information
                    {
                        printf("\nAll Students Info : ");

                        for (int i=0; i<s1; i++)
                        {
                            printf("\nID : %d\n", student[i].id);
                            printf("Name : %s\n", student[i].name);
                            printf("Email : %s\n", student[i].email);
                            printf("CGPA : %f\n", student[i].cgpa);
                        }
                    }
                    else if (op_t == 2) // Showing all teachers information
                    {
                        printf("\nAll Teachers Info : ");

                        for (int i=0; i<t1; i++)
                        {
                            printf("\nName : %s\n", teacher[i].name);
                            printf("Email : %s\n", teacher[i].email);
                            printf("Designation : %s\n", teacher[i].designation);
                        }
                    }
                    else if (op_t == 3) // Logout and end the infinite loop.
                    {
                        printf("\nLogout Successfully !\n");
                        break;
                    }
                    else if (op_t == 4) // Exit and end the program.
                    {
                        return 0;
                    }
                    else // For invalid case.
                    {
                        printf("\nInvalid !!!\n");
                    }
                }
            }
        }
    }
}

