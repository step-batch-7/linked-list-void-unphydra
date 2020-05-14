#include "test.h"

Element test_mapper(Element a)
{
  int * r =malloc(sizeof(int));
  *r = *(int*)a + 1; 
  return r;
}

void test_map_for_empty_list(void)
{ 
  List_ptr input = create_list();
  List_ptr actual = map(input,test_mapper);
  int expected[] = {};
  Status s = compare_list_values(actual,expected,0);
  show_message("  should map an empty list and return an empty list",s);
}

void test_map_for_increment_number_mapper(void)
{
  List_ptr input = create_list();
  int ar[] = {1,2,3,4,5};
  Status s = add_to_list(input,&ar[0]) && add_to_list(input,&ar[1]) && add_to_list(input,&ar[2]) && add_to_list(input,&ar[3]) && add_to_list(input,&ar[4]);
  List_ptr actual = map(input,test_mapper);
  int expected[] = {2,3,4,5,6};
  s = s && compare_list_values(actual,expected,5);
  show_message("  should map a list and return a list with increment elements values",s);
}

void test_map(void)
{
  printf("\ntest map\n");
  test_map_for_empty_list();
  test_map_for_increment_number_mapper();
}

Status test_predicate(Element a)
{
  return (*(int*)a % 2) == 0;
}

void test_filter_for_empty_list(void)
{ 
  List_ptr input = create_list();
  List_ptr actual = filter(input,test_predicate);
  int expected[] = {};
  Status s = compare_list_values(actual,expected,0);
  show_message("  should filter an empty list and return an empty list",s);
}

void test_filter_for_even_filter(void)
{
  List_ptr input = create_list();
  int ar[] = {1,2,3,4,5};
  Status s = add_to_list(input,&ar[0]) && add_to_list(input,&ar[1]) && add_to_list(input,&ar[2]) && add_to_list(input,&ar[3]) && add_to_list(input,&ar[4]);
  List_ptr actual = filter(input,test_predicate);
  int expected[] = {2,4};
  s = s && compare_list_values(actual,expected,2);
  show_message("  should filter a list and return a list of even int elements",s);
}


void test_filter(void)
{
  printf("\ntest filter\n");
  test_filter_for_empty_list();
  test_filter_for_even_filter();
}

void test_array_methods(void)
{
  test_map();
  test_filter();
}