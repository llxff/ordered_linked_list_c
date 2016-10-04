#ifndef TASK_EXPECT_H
#define TASK_EXPECT_H

#define expect_true(caption, condition) _expect_true(caption, condition, __LINE__)

void _expect_true(char caption[], int condition, int line);

extern int tests_failed;

int tests_result_code();

#endif
