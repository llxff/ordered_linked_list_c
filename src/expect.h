#ifndef TASK_EXPECT_H
#define TASK_EXPECT_H

#define expect_to_be_true(caption, condition) _expect_to_be_true(caption, condition, __LINE__)

void _expect_to_be_true(char caption[], int condition, int line);

#endif
