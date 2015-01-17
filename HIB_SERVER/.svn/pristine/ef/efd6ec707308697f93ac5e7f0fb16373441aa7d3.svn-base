# include "uni_test.h" 
# include <stdlib.h> 

int main ( void ) 
{ 
         int n ; 
        SRunner * sr ; 

        sr = srunner_create ( make_add_suite ( ) ) ; //把Suite加入到SRunner里面 


        srunner_run_all ( sr , CK_NORMAL ) ; //运行所有测试用例 


        n = srunner_ntests_failed ( sr ) ; 
        srunner_free ( sr ) ; 

         return (n == 0) ? EXIT_SUCCESS : EXIT_FAILURE ; 
} 