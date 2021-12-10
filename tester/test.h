#define NULLSTR ((char *)0)

#define TEST_1 "1. %+9d \n", 85
#define TEST_2 "2. % 9d \n", 85
#define TEST_3 "3. %0+9d \n", 85
#define TEST_4 "4. %0 9d \n", 85
#define TEST_5 "5. %-9d \n", 85
#define TEST_6 "6. %09u \n", 85
#define TEST_7 "7. %-.9u \n", 8
#define TEST_8 "8. %.9u \n", 8
#define TEST_9 "9. %10.10s\n", "grosse canaille de fou"
#define TEST_10 "10. %20.10x\n", 42
#define TEST_11 "11. cannaaillle\n"
#define TEST_12 "12. %#-150.19X\n", 25500
#define TEST_13 "13. %50.5s\n", "bonjour"
#define TEST_14 "14. %020d\n", 2021
#define TEST_15 "15. %#015x\n", 21
#define TEST_16 "16. %+016d\n", 34293
#define TEST_17 "17. %-+10.10d\n", 12
#define TEST_18 "18. %s\n", "okok"
#define TEST_19 "19. ca marche mon pote\n"
#define TEST_20 "20. %.8s\n", "okok"
#define TEST_21 "21. %20.3s\n", NULLSTR
#define TEST_22 "22. %-10s\n", NULLSTR
#define TEST_23 "23. %10s\n", NULLSTR
#define TEST_24 "24. %10.s\n", NULLSTR
#define TEST_25 "25. %.s\n", NULLSTR
#define TEST_26 "26. %4.6s\n", NULLSTR
#define TEST_27 ""
#define TEST_28 ""
#define TEST_29 ""
#define TEST_30 ""
