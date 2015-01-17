#ifdef _WIN32
#define __declspec_dllexport _declspec(dllexport)
#else 
#define __declspec_dllexport 
#endif


#ifdef __cplusplus
#define __extern_c extern "C" 
#else 
#define __extern_c 
#endif