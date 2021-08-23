#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int marks_summation(int* marks, int number_of_students, char gender) {
    int sum=0;
    if(gender=='b'){
        for(int i=0; i<=number_of_students; i+=2){
            sum+=marks[i];
        }
        return sum;
    }
    else if(gender=='g'){
        for(int j=1; j<=number_of_students; j+=2){
            sum+=marks[j];
        }
        return sum;
    }
    else{
        return 0;
    }
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}
