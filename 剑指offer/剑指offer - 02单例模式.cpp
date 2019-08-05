#define _CRT_SECURE_NO_WARNINGS  1

//设计一个类，只能实现这个类的一个实例。

//Signleton是一个能够用短短的几十行代码就可以解决的问题，
//因此它是一个非常重要的面试题。

//不好的解法一：只适用于单线程环境
//由于要求只能生成一个实例，因此必须把构造函数私有化，
//防止他人创建实例，我们可以定义一个静态的实例，需要的时候创建

//public sealed class Singleton1
//{
//	private Singleton1()
//	{}
//
//	private static Singleton1 instance = null;
//	public static Singleton1 Instance
//	{
//		get
//		{
//		if (instance == null)
//			instance = new Singleton1();
//
//		return instance;
//		}
//	}
//};

//不好的解法2：虽然在多线程下工作，但效率不高
//解法一中的代码，在单线程下的时候正常，但是在多线程调用的时候，
//就会出现异常，在判断if(instance = null)的语句中，如果；两个线程
//同时运行到的时候，就会出现两个线程同时创建一个实例，所以需要加上
//一个同步锁。

//但是加锁是一个非常耗时的操作
//public sealed class Singleton2
//{
//	private Singleton2()
//	{}
//
//	private static readonly object syncObj = new object();
//
//
//	private static Singleton2 instance = null;
//	public static Singleton2 Instance
//	{
//		get
//		{
//			lock(syncObj)
//			{
//				if (instance == null)
//					instance = new Singleton2();
//			}
//			return instance;
//		}
//	}
//};

//可行的解法：加同步锁前后两次判断实例是否已经存在
//我们只是在实例还没有创建之前判断加锁的操作，保证只有一个线程
//创建出实例，当实例创建之后就不需要进行加锁的操作了
//public sealed class Singleton3
//{
//	private Singleton3()
//	{}
//
//	private static readonly object syncObj = new object();
//
//
//	private static Singleton3 instance = null;
//	public static Singleton3 Instance
//	{
//		get
//		{
//		if (instance == null)
//		{
//			lock(syncObj)
//			{
//				if (instance == null)
//					instance = new Singleton3();
//			}
//		}
//			
//			return instance;
//		}
//	}
//};

//强烈推荐的解法1：利用静态函数

//在初始化静态变量instance的时候创建出一个实例，在调用静态构造
//函数的时候初始化静态变量。

//但是还有一个问题，调用静态函数的时机不是由程序员来进行操控的
//是当程序运行到第一次使用一个类型的时候自用调用该类型的静态构造函数
//因此不是在调用Instance的时候创建，而是在调用Singleton4的时候创建


//这种操作依旧会过早的创建实例，从而降低内存的使用效率。


//public sealed class Singleton4
//{
//	private Singleton4()
//	{}
//	private static Singleton4 instance = new Singleton4();
//
//	public static Singleton4 Instance
//	{
//		get
//		{
//			return instance;
//		}
//	}
//};

//强烈推荐的解法二：实现按需实例化

//定义一个私有的类型，当第一次调用这个类型的时候，会调用静态成员函数
//创建Singleton5的实例instance，
//类型Nested只有在属性Singleton.Instance的时候会被用到，
//由于其是私有的类型，他人无法使用Nested

//public sealed class Singleton5
//{
//	Singleton5()
//	{}
//
//	public static Singleton5 Instance
//	{
//		get
//		{
//			return Nested.instance;
//		}
//	}
//
//	class Nested()
//	{
//		static Nested()
//		{
//
//		}
//		internal static readonly Singleton5 instance = new Singleton2();
//	}
//};