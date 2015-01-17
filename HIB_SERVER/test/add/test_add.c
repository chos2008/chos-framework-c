# include "check.h" 
# include "uni_test.h" 
START_TEST ( test_add ) 
{ 
 fail_unless ( add ( 2 , 3 ) == 5 , "god, 2+3!=5" ) ; 
} 
END_TEST 

Suite * 
make_add_suite ( void ) 
{ 
        Suite * s = suite_create ( "Add" ) ; //建立测试套件（我不知道，这么翻译对不对？^_^） 

        TCase * tc_add = tcase_create ( "add" ) ; //建立测试用例集 


        suite_add_tcase ( s , tc_add ) ; //把测试用例集加入到套件中 

        tcase_add_test ( tc_add , test_add ) ; //把我们的测试用例加入到测试集中 


         return s ; 
} 