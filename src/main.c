#include "test_includes/s21_tests.h"

int main(void) {
  run_tests();

  return 0;
}

void run_testcase(Suite *testcase) {
  setlocale(LC_ALL, "");
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_s21_add(),
                         suite_s21_sub(),
                         suite_s21_mul(),
                         suite_s21_div(),

                         suite_is_equal(),
                         suite_is_not_equal(),
                         suite_is_greater(),
                         suite_is_greater_or_equal(),
                         suite_is_less(),
                         suite_is_less_or_equal(),

                         suite_s21_conventors(),

                         lib_suite(),
                         NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
