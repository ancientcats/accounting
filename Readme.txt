TDD personal accounting homework C++ (1st attempt)

test case:
Budget			Query                   Result
2018/11, 30     2018/11/1~11/1          1   ← add budget vector, DaysOfYearMonth, period logic (nEndDay - nStartDay + 1)
2018/8, 31      2018/8/1~8/1            1
2018/7, 31      2018/7/1~7/1            1
2018/4, 30      2018/4/1~4/1            1   ← need refactoring

2018/11, 30     2018/11/1~11/30         30  ← pass
                2018/11/1~12/31         30  ← add period logic (nDays - nStartDay + 1)
                2018/11/1~2019/12/31    30  ← add period logic (Year & Month conditions: start-middle-end)
                2018/10/31~11/1         1   ← add period logic (last month but not start month, using EndDay)
                2018/11/30~12/1         1   ← pass, sufficient by (nDays - nStartDay + 1)

no data         2018/11/1~11/30         0   ← pass

2018/11, 30		
2018/12, 62     2018/11/1~2018/12/31    92  ← pass
                2018/11/30~2018/12/1    3   ← pass
