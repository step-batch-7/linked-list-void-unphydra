#include "test.h"

void show_message(String msg, Status s)
{
  printf("%s => %s\n",msg,s?"pass":"fails");
}

void show_length_failure(int a, int b)
{
  printf("\nactual=> %d\nexpected=>%d\n",a,b);
}

Status compare_list_values(List_ptr list, Array a, int length)
{
  Status s = Success;
  s = list->length == length;
  if (!s)
  {
    show_length_failure(list->length,length);
  }
  
  Node_ptr p_walk = list->first;
  int count = 0;
  while (p_walk!=NULL)
  {
    s = s && *(int *)p_walk->element == a[count];
    count++;
    p_walk = p_walk->next;
  }
  if (!s)
  {
    printf("\nactual=>\n");
    printf("expected=>\n");
    for (int i = 0; i < length ; i++)
    {
      printf("%d\n",a[i]);
    } 
  }
  return s && (count == length);
}
