/*
 *
 *
 *
 */

#if ! defined DECLSPEC_EXPORT
#    define DECLSPEC_EXPORT _declspec(dllexport) 
#else
//#    define DECLSPEC_EXPORT 
#endif;

#if ! defined TK_API
#    if defined DECLSPEC_EXPORT
#        define TK_API DECLSPEC_EXPORT
#    else
#        define TK_API 
#    endif;
#endif;