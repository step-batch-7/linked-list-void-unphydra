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

void test_map(void)
{
  printf("\ntest map\n");
  test_map_for_empty_list();
}

void test_array_methods(void)
{
  test_map();
}