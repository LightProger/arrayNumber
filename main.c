#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
 * Дан массив из 6 значений. (1, 2, 3... 6). Пользователь хочет увидеть какое-то число ячеек массива (от 0 до 6)
 * и вводит с клавиатуры это число.
 * Если он ввел 0, то мы должны скрыть все ячейки массива символами *.
 * Если он ввел 6, то мы должны показать все ячейки массива, т.е. напечатать: 1 2 3 4 5 6.
 * Если пользователь ввел 1, мы должны показать 1 СЛУЧАЙНУЮ ячейку массива... Если ввел 2 - две случайные ячейки...
 * а все остальные ячейки скрыть символами *.
 */

#define SIZE 6

int main ()
{
  // Переменные
  int arrayNumber[SIZE] = { 1, 2, 3, 4, 5, 6 };
  int i, j, number = 0;
  bool flag;

  srand(time(NULL));

  // Ввод числа
  do{
      printf("Введите число ячеек, которое хотите увидеть от 0 до %i:\n", SIZE);
      scanf("%i", &number);
      getchar();
    }while(number < 0 || number > SIZE);

  // Сравнение введенных чисел с массивом
  if(number == 6)
    {
      for(i = 0; i < SIZE; i++) { printf("%i ", arrayNumber[i]); }
    }
  else if(number == 0)
    {
      for(i = 0; i < SIZE; i++)
        {
          printf("* ");
        }
    }
  else if(number == 1)
    {
      int n = rand() % SIZE;
      for (i = 0; i < SIZE; i++)
        {
          if(i == n) printf("%i ", arrayNumber[i]);
          else printf("* ");
        }
    }
  else
    {
      /*задаём динамический массив, с количеством элементов которые необходимо вывести*/
      int* a=(int*)malloc(number*sizeof(int));

      //заполняем массив случайными номерами ячеек массива arrayNumber и проверяем на повторы
      for(i = 0; i < number; i++)
        {
          a[i] = 0 + rand() % SIZE;
          for(j = 0; j < number; j++)
             if(i != j && a[i] == a[j])
               {
                 while(a[i] == a[j]) { a[i] = 0 + rand() % SIZE; }
                 j = -1;
               }
        }
      /* Сравнение и вывод на печать */
      for(j = 0; j < SIZE; j++)
        {
          flag = true;
          for(i = 0; i < number; i++)
            {
              if(j == a[i])
                { /*если номер есть в массиве со случайными числами, выводит элемент массива arrayNumber,
                  соответствующий этому номеру и выходит из цикла*/
                  printf("%d ",arrayNumber[j]);
                  flag = false;
                }
            }

          if(flag == true) printf("* ");//проверяет, не было ли соответствия и, в случае выполнения, выводит *
        }
      free(a);//освобождение памяти

    }
  printf("\n");
  return 0;
}