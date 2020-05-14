#include "linkedlist.h"

Node_ptr create_node(Element value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->element = value;
  new_node->next = NULL;
  return new_node;
}

List_ptr create_list()
{
  List_ptr new_list =malloc(sizeof(LinkedList));
  new_list->first = NULL;
  new_list->last = NULL;
  new_list->length = 0;
  return new_list;
}

Status add_to_list(List_ptr list, Element value)
{
  Node_ptr new_node = create_node(value);
  Node_ptr * ptr_to_set = &list->first;
  if(list->first!=NULL){
    ptr_to_set = &list->last->next;
  }
  (*ptr_to_set) = new_node;
  list->last = new_node;
  list->length++;
  return Success;
}

Status add_to_start(List_ptr list, Element value)
{
  Node_ptr new_node = create_node(value);
  if (list->first==NULL)
  {
    list->last = new_node;
  }
  Node_ptr temp = list->first;
  list->first = new_node;
  list->first->next = temp;
  list->length++;
  return Success;
}

Status insert_at(List_ptr list, Element value, int position)
{
  if (position > list->length || position < 0)
  {
    return Failure;
  }
  if (position ==0)
  {
    return add_to_start(list,value);
  }
  if (position == list->length)
  {
    return add_to_list(list,value);
  }
  
  Node_ptr new_node = create_node(value);
  int count = 1;
  Node_ptr p_walk = list->first;
  while (1)
  {
    if(count == position){
      Node_ptr temp = p_walk->next;
      p_walk->next = new_node;
      new_node->next = temp;
      list->length++;
      return Success;
    }
    count++;
    p_walk = p_walk->next;
  }
}

Status add_unique(List_ptr list, Element value, Matcher matcher)
{
  Node_ptr p_walk = list->first;
  while (p_walk!=NULL)
  {
    if ((*matcher)(p_walk->element,value)) {
      return Failure;
    }
    p_walk = p_walk->next;
  }
  return add_to_list(list,value);
}

Element remove_from_start(List_ptr list)
{
  if (list->first==NULL)
  {
    return NULL;
  }
  Element element = list->first->element;
  if (list->length==1)
  {
    clear_list(list);
    return element;
  }
  Node_ptr temp = list->first->next;
  free(list->first);
  list->first = temp;
  list->length--;
  return element;
}

Element remove_from_end(List_ptr list)
{
  if (list->first==NULL)
  {
    return NULL;
  }
  Element element = list->first->element;
  if (list->length==1)
  {
    clear_list(list);
    return element;
  }
  
  Node_ptr p_walk = list->first;
  Node_ptr node_to_remove = p_walk->next;
  element = node_to_remove->element;
  while (node_to_remove->next!=NULL)
  {
    p_walk = node_to_remove;
    node_to_remove = node_to_remove->next;
    element = node_to_remove->element;
  }
  p_walk->next = NULL;
  free(node_to_remove);
  list->last = p_walk;
  list->length--;
  return element;
}

Element remove_at(List_ptr list, int position)
{
  if (list->first==NULL || position >= list->length || position < 0)
  {
    return NULL;
  }
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == list->length-1)
  {
    return remove_from_end(list);
  }
  
  Node_ptr p_walk = list->first;
  Node_ptr node_to_remove = p_walk->next;
  Element element = node_to_remove->element;
  int count = 1;
  while (count<position)
  {
    count++;
    p_walk = node_to_remove;
    node_to_remove = node_to_remove->next;
    element = node_to_remove->element;
  }
  p_walk->next = node_to_remove->next;
  free(node_to_remove);
  list->length--;
  return element;
}

Element remove_first_occurrence(List_ptr list, Element value, Matcher matcher)
{
  if (list->first==NULL)
  {
    return NULL;
  }
  Node_ptr p_walk = list->first;
  int pos = 0;
  while (pos < list->length)
  {
    if ((*matcher)(value,p_walk->element))
    {
      return remove_at(list,pos);
    }
    pos++;
    p_walk = p_walk->next;
  }
  return NULL;
}

List_ptr remove_all_occurrences(List_ptr list, Element value, Matcher matcher)
{
  List_ptr remove_list = create_list();
  while (1)
  {
    Element element = remove_first_occurrence(list,value,matcher);
    if (element == NULL)
    {
      return remove_list;
    }
    add_to_list(remove_list,element);
  }
}

Status clear_list(List_ptr list)
{
  if (list->first==NULL)
  {
    return Failure;
  }
  
  Node_ptr p_walk = list->first;
  Node_ptr element_to_free = NULL;

  while (p_walk!=NULL)
  {
    element_to_free = p_walk;
    p_walk = p_walk->next;
    free(element_to_free);
  }
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return Success;
}

List_ptr reverse(List_ptr list)
{
  List_ptr result = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    add_to_start(result,p_walk->element);
    p_walk = p_walk->next;
  }
  return result;
}
