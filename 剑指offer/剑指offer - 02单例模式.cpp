#define _CRT_SECURE_NO_WARNINGS  1

//���һ���ֻ࣬��ʵ��������һ��ʵ����

//Signleton��һ���ܹ��ö̶̵ļ�ʮ�д���Ϳ��Խ�������⣬
//�������һ���ǳ���Ҫ�������⡣

//���õĽⷨһ��ֻ�����ڵ��̻߳���
//����Ҫ��ֻ������һ��ʵ������˱���ѹ��캯��˽�л���
//��ֹ���˴���ʵ�������ǿ��Զ���һ����̬��ʵ������Ҫ��ʱ�򴴽�

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

//���õĽⷨ2����Ȼ�ڶ��߳��¹�������Ч�ʲ���
//�ⷨһ�еĴ��룬�ڵ��߳��µ�ʱ�������������ڶ��̵߳��õ�ʱ��
//�ͻ�����쳣�����ж�if(instance = null)������У�����������߳�
//ͬʱ���е���ʱ�򣬾ͻ���������߳�ͬʱ����һ��ʵ����������Ҫ����
//һ��ͬ������

//���Ǽ�����һ���ǳ���ʱ�Ĳ���
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

//���еĽⷨ����ͬ����ǰ�������ж�ʵ���Ƿ��Ѿ�����
//����ֻ����ʵ����û�д���֮ǰ�жϼ����Ĳ�������ֻ֤��һ���߳�
//������ʵ������ʵ������֮��Ͳ���Ҫ���м����Ĳ�����
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

//ǿ���Ƽ��Ľⷨ1�����þ�̬����

//�ڳ�ʼ����̬����instance��ʱ�򴴽���һ��ʵ�����ڵ��þ�̬����
//������ʱ���ʼ����̬������

//���ǻ���һ�����⣬���þ�̬������ʱ�������ɳ���Ա�����вٿص�
//�ǵ��������е���һ��ʹ��һ�����͵�ʱ�����õ��ø����͵ľ�̬���캯��
//��˲����ڵ���Instance��ʱ�򴴽��������ڵ���Singleton4��ʱ�򴴽�


//���ֲ������ɻ����Ĵ���ʵ�����Ӷ������ڴ��ʹ��Ч�ʡ�


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

//ǿ���Ƽ��Ľⷨ����ʵ�ְ���ʵ����

//����һ��˽�е����ͣ�����һ�ε���������͵�ʱ�򣬻���þ�̬��Ա����
//����Singleton5��ʵ��instance��
//����Nestedֻ��������Singleton.Instance��ʱ��ᱻ�õ���
//��������˽�е����ͣ������޷�ʹ��Nested

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