/*
 *
 *
 * @author ada
 * @version 1.0
 */
#include "Module.hpp"

#if ! defined __OBJECT_MODULE
#define __OBJECT_MODULE 

#define INVOKE()

/**
 * 将对象调用封装成模块，实际是将对象方法封装成模块。
 *
 * 通过指定一个对象实例以及该对象的某个方法以模块的形式进行加载
 * 运行。
 *
 * 构造方法中需要指定一个对象实例<code>target</code>，以及该对
 * 象下的某个方法<code>handle</code>.
 *
 * 注：目前构造函数中<code>target</code>暂时无用。
 */
class ObjectModule : public Module
{
private: 
	void *target;

public:
	ObjectModule(char *name, void *target, void *handle);

	void start();
};

#endif;
