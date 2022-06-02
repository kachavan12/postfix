//Created by Karthik Chavan k1833342 @ 6/28/20 
#include <iomanip>
#include <iostream> 
#include <string.h>  

using namespace std;

//Stack
struct Stack
{
   int top;
   unsigned capacity;
   int* array;
};

//Operations  
struct Stack* createStack(unsigned capacity)
{
   struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

   if (!stack) return NULL;

   stack->top = -1;
   stack->capacity = capacity;
   stack->array = (int*)malloc(stack->capacity * sizeof(int));

   if (!stack->array) return NULL;

   return stack;
}

//push stack
void push(struct Stack* stack, char op)
{
   stack->array[++stack->top] = op;
}

//pop stack
char pop(struct Stack* stack)
{
   if (!isEmpty(stack))
      return stack->array[stack->top--];
   return '$';
}

//if empty
int isEmpty(struct Stack* stack)
{
   return stack->top == -1;
}

//actual calulation part of postfix  
int evaluatePostfix(char* exp)
{
   // make a stack the legnth of the char length 
   struct Stack* pfstack = createStack(strlen(exp));
   int i;

   // stack error check  
   if (!pfstack) return -1;

   // Scan in  the char string
   for (i = 0; exp[i]; ++i)
   {
      // If character is an operand push it to the stack.  
      if (isdigit(exp[i]))
      {
         push(pfstack, exp[i] - '0');// use the - 0 for stich int to char thing
      }

      // If char is op pop 2 elem from stack and apply opperation 
      else
      {
         int num1 = pop(pfstack);
         int num2 = pop(pfstack);
         switch (exp[i])
         {
         case '+':
         {
            push(pfstack, num2 + num1); 
            break;
         }
         case '-': 
         {
            push(pfstack, num2 - num1);
            break;
         }
         case '*':
         {
            push(pfstack, num2 * num1);
            break;
         }
         case '/':
         {
            push(pfstack, num2 / num1);
            break;
         }
         }
      }
   }
   //return the final num
   return pop(pfstack);
}
 
int main()
{
   char s1[] = "257*9-/5*6";
   cout << "postfix calc:  " << evaluatePostfix(s1);
   return 0;
}
