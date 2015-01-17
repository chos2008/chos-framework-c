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
        Suite * s = suite_create ( "Add" ) ; //���������׼����Ҳ�֪������ô����Բ��ԣ�^_^�� 

        TCase * tc_add = tcase_create ( "add" ) ; //�������������� 


        suite_add_tcase ( s , tc_add ) ; //�Ѳ������������뵽�׼��� 

        tcase_add_test ( tc_add , test_add ) ; //�����ǵĲ����������뵽���Լ��� 


         return s ; 
} 