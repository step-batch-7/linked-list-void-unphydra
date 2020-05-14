#include "test.h"

void test_add_to_list(void)
{
  printf("\ntest_add_to_list\n");
  List_ptr actual = create_list();
  int ar[] = {5,2};
  Status s = add_to_list(actual,&ar[0]);
  int expected_1[] = {5};
  int expected_1_length = 1;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should add a value if the list head is null", s);

  s = add_to_list(actual,&ar[1]);
  int expected_2[] = {5,2};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should add a value at the end of the list", s);
}

void test_add_to_start(void)
{
  printf("\ntest_add_to_start\n");
  List_ptr actual = create_list();
  int ar[] = {5,2};
  Status s = add_to_start(actual,&ar[0]);
  int expected_1[] = {5};
  int expected_1_length = 1;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should add a value if the list head is null", s);

  s = add_to_start(actual,&ar[1]);
  int expected_2[] = {2,5};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should add a value at the start of the list", s);
}

void test_insert_at(void)
{
  printf("\ntest_insert_at\n");
  List_ptr actual = create_list();
  int ar[] = {1,2,3,4,5,6};
  Status s = insert_at(actual,&ar[1],1);
  int expected_0[] = {};
  int expected_0_length = 0;
  s = (s==Failure) && compare_list_values(actual,expected_0,expected_0_length);
  show_message("should not add a value if the list head is null and position is one", s);

  s = insert_at(actual,&ar[4],0);
  int expected_1[] = {5};
  int expected_1_length = 1;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should add a value if the list head is null", s);

  s = insert_at(actual,&ar[1],1);
  int expected_2[] = {5,2};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should add a value at the first position of the list", s);

  s = insert_at(actual,&ar[0],0);
  int expected_3[] = {1,5,2};
  int expected_3_length = 3;
  s = s && compare_list_values(actual,expected_3,expected_3_length);
  show_message("should add a value at the zero position of the list", s);

  s = insert_at(actual,&ar[3],3);
  int expected_4[] = {1,5,2,4};
  int expected_4_length = 4;
  s = s && compare_list_values(actual,expected_4,expected_4_length);
  show_message("should add a value at the last position of the list", s);

  s = insert_at(actual,&ar[2],2);
  int expected_5[] = {1,5,3,2,4};
  int expected_5_length = 5;
  s = s && compare_list_values(actual,expected_5,expected_5_length);
  show_message("should add a value at the given between position of the list", s);

  s = insert_at(actual,&ar[5],4);
  int expected_6[] = {1,5,3,2,6,4};
  int expected_6_length = 6;
  s = s && compare_list_values(actual,expected_6,expected_6_length);
  show_message("should add a value at the end of the list", s);
}

Status test_matcher(Element a,Element b)
{ 
  return *(int*)a == *(int*)b;
}

void test_add_unique(void)
{
  printf("\ntest_add_unique\n");
  List_ptr actual = create_list();
  int ar[] = {5,2};
  Status s = add_unique(actual,&ar[0],test_matcher);
  int expected_1[] = {5};
  int expected_1_length = 1;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should add a value if the list head is null", s);

  s = add_unique(actual,&ar[1],test_matcher);
  int expected_2[] = {5,2};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should add a unique value at the end of the list", s);

  s = add_unique(actual,&ar[1],test_matcher);
  int expected_3[] = {5,2};
  int expected_3_length = 2;
  s = (s==Failure) && compare_list_values(actual,expected_3,expected_3_length);
  show_message("should not add the not unique value at the end of the list", s);
}

void test_remove_from_start(void)
{
  printf("\ntest_remove_from_start\n");
  List_ptr actual = create_list();
  Element e = remove_from_start(actual);
  int expected_1[] = {};
  int expected_1_length = 0;
  Status s = compare_list_values(actual,expected_1,expected_1_length) && e == NULL;
  show_message("should not remove if the list is empty", s);

  int a = 2;
  s = add_to_start(actual,&a);
  s = s && add_to_start(actual,&a);
  e = remove_from_start(actual);
  int expected_2[] = {2};
  int expected_2_length = 1;
  s = s && compare_list_values(actual,expected_2,expected_2_length) && *(int*)e == 2;
  show_message("should remove a value from the start of the list", s);
}

void test_remove_from_end(void)
{
  printf("\ntest_remove_from_end\n");
  List_ptr actual = create_list();
  Element e = remove_from_end(actual);
  int expected_1[] = {};
  int expected_1_length = 0;
  Status s = compare_list_values(actual,expected_1,expected_1_length) && e == NULL;
  show_message("should not remove if the list is empty", s);

  int a = 2;
  s = add_to_start(actual,&a);
  s = s && add_to_start(actual,&a);
  e = remove_from_end(actual);
  int expected_2[] = {2};
  int expected_2_length = 1;
  s = s && compare_list_values(actual,expected_2,expected_2_length) && *(int*)e == 2;
  show_message("should remove a value from the end of the list", s);
}

void test_remove_at(void)
{
  printf("\ntest_remove_at\n");
  List_ptr actual = create_list();
  Element e = remove_at(actual,0);
  int expected_1[] = {};
  int expected_1_length = 0;
  Status s = compare_list_values(actual,expected_1,expected_1_length);
  show_message("should not remove if the list is empty", s);

  int ar[] = {1,2,3,4,5};
  s = add_to_list(actual,&ar[1]);
  s =s && add_to_list(actual,&ar[2]);
  e =remove_at(actual,0);
  int expected_2[] = {3};
  int expected_2_length = 1;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should remove a value at the first position of the list", s);

  s =add_to_list(actual,&ar[3]);
  e = remove_at(actual,0);
  int expected_3[] = {4};
  int expected_3_length = 1;
  s = s && compare_list_values(actual,expected_3,expected_3_length);
  show_message("should not remove a value at the zero position of the list", s);

  e = remove_at(actual,1);
  int expected_4[] = {4};
  int expected_4_length = 1;
  s = compare_list_values(actual,expected_4,expected_4_length);
  show_message("should not remove a value at the position after the end of the list", s);

  s = add_to_list(actual,&ar[4]);
  s =s && add_to_list(actual,&ar[2]);
  e = remove_at(actual,1);
  int expected_5[] = {4,3};
  int expected_5_length = 2;
  s = s && compare_list_values(actual,expected_5,expected_5_length);
  show_message("should remove a value at the given between position of the list", s);

  s = add_to_list(actual,&ar[4]);
  e = remove_at(actual,1);
  int expected_6[] = {4,5};
  int expected_6_length = 2;
  s = s && compare_list_values(actual,expected_6,expected_6_length);
  show_message("should remove a value at the given between position of the list", s);
}

void test_remove_first_occurrence(void)
{
  printf("\ntest_remove_first_occurrence\n");
  List_ptr actual = create_list();
  int ar[] = {2,5};
  Status s = add_to_list(actual,&ar[1]);
  s = s && add_to_list(actual,&ar[0]);
  s = s && add_to_list(actual,&ar[1]);
  s = s && add_to_list(actual,&ar[1]);
  Element e =remove_first_occurrence(actual,&ar[1], test_matcher);
  int expected_1[] = {2,5,5};
  int expected_1_length = 3;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should remove the first occurrence of the given value from the first position", s);

  e = remove_first_occurrence(actual,&ar[1],test_matcher);
  int expected_2[] = {2,5};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should remove the first occurrence of the given value from the in between position", s);
}

void test_remove_all_occurrences(void)
{
  printf("\ntest_remove_all_occurrences\n");
  List_ptr actual = create_list();
  int ar[] = {2,5};
  Status s = add_to_list(actual,&ar[1]);
  s = s && add_to_list(actual,&ar[0]);
  s = s && add_to_list(actual,&ar[1]);
  s = s && add_to_list(actual,&ar[1]);
  List_ptr l =  remove_all_occurrences(actual,&ar[0],test_matcher);
  int expected_1[] = {5,5,5};
  int expected_1_length = 3;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should remove all occurrence of the given value from the list when there is only one occurrence", s);

  l = remove_all_occurrences(actual,&ar[1],test_matcher);
  int expected_2[] = {};
  int expected_2_length = 0;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should remove all occurrence of the given value from the list has only that value", s);

  l = remove_all_occurrences(actual,&ar[1],test_matcher);
  s = s && compare_list_values(actual,expected_2,expected_2_length) && compare_list_values(l,expected_2,expected_2_length);
  show_message("should remove_all_occurrence doest remove and give empty list", s);
}

void test_linked_list(void)
{
  test_add_to_list();
  test_add_to_start();
  test_insert_at();
  test_add_unique();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
}
