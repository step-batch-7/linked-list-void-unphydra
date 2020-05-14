#include "linkedlist.h"

List_ptr map(List_ptr src, Mapper mapper)
{
  List_ptr result = create_list();
  Node_ptr p_walk = src->first;
  while (p_walk!=NULL)
  {
    add_to_list(result,(*mapper)(p_walk->element));
    p_walk = p_walk->next;
  }
  return result;
}

List_ptr filter(List_ptr src, Predicate predicate)
{
  List_ptr result = create_list();
  Node_ptr p_walk = src->first;
  while (p_walk!=NULL)
  {
    if((*predicate)(p_walk->element)){
    add_to_list(result,p_walk->element);
    }
    p_walk = p_walk->next;
  }
  return result;
}

Element reduce(List_ptr src, Element init, Reducer reducer)
{
  Element result = init;
  Node_ptr p_walk = src->first;
  while (p_walk!=NULL)
  {
    result = (*reducer)(result,p_walk->element);
  }
  return result;
}

void forEach(List_ptr src, ElementProcessor processor)
{
  Node_ptr p_walk = src->first;
  while (p_walk!=NULL)
  {
    (*processor)(p_walk->element);
    p_walk = p_walk->next;
  }
}
