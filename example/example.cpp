#include <simple_enum_set/enum_set.hpp>
#include <iostream>

// Undefine this for using EnumSet based on array
//#define USE_BIT_SET

ES_CREATE_INDEXED_ENUM(TestEnum, First, Second, Third, Fourth, Fifth, Sixth);

int main(int argc, const char** argv)
{
	using namespace es;
#ifdef USE_BIT_SET
	BitEnumSet<TestEnum> testEnum;
	TestEnum::First;
	testEnum.Insert(TestEnum::Second);
	testEnum.Insert(TestEnum::Fourth);
	testEnum.Insert(TestEnum::Fifth);
	std::cout << "Contains first: " << testEnum.Contains(TestEnum::First) << std::endl;
	std::cout << "Contains second: " << testEnum.Contains(TestEnum::Second) << std::endl;
	std::cout << "Contains third: " << testEnum.Contains(TestEnum::Third) << std::endl;
	std::cout << "Contains fourth: " << testEnum.Contains(TestEnum::Fourth) << std::endl;
	std::cout << "Contains fifth: " << testEnum.Contains(TestEnum::Fifth) << std::endl;
	std::cout << "Contains sixth: " << testEnum.Contains(TestEnum::Sixth) << std::endl;
	std::cout << std::endl;
	testEnum.Remove(TestEnum::Third);
	testEnum.Remove(TestEnum::Fourth);
	std::cout << "Contains first: " << testEnum.Contains(TestEnum::First) << std::endl;
	std::cout << "Contains second: " << testEnum.Contains(TestEnum::Second) << std::endl;
	std::cout << "Contains third: " << testEnum.Contains(TestEnum::Third) << std::endl;
	std::cout << "Contains fourth: " << testEnum.Contains(TestEnum::Fourth) << std::endl;
	std::cout << "Contains fifth: " << testEnum.Contains(TestEnum::Fifth) << std::endl;
	std::cout << "Contains sixth: " << testEnum.Contains(TestEnum::Sixth) << std::endl;
#else
	EnumSet<TestEnum> testEnum;
	
	testEnum.Insert(TestEnum::Second);
	testEnum.Insert(TestEnum::Fourth);
	testEnum.Insert(TestEnum::Fifth);
	std::cout << "Contains first: " << testEnum.Contains(TestEnum::First) << std::endl;
	std::cout << "Contains second: " << testEnum.Contains(TestEnum::Second) << std::endl;
	std::cout << "Contains third: " << testEnum.Contains(TestEnum::Third) << std::endl;
	std::cout << "Contains fourth: " << testEnum.Contains(TestEnum::Fourth) << std::endl;
	std::cout << "Contains fifth: " << testEnum.Contains(TestEnum::Fifth) << std::endl;
	std::cout << "Contains sixth: " << testEnum.Contains(TestEnum::Sixth) << std::endl;
	std::cout << std::endl;
	testEnum.Remove(TestEnum::Third);
	testEnum.Remove(TestEnum::Fourth);
	std::cout << "Contains first: " << testEnum.Contains(TestEnum::First) << std::endl;
	std::cout << "Contains second: " << testEnum.Contains(TestEnum::Second) << std::endl;
	std::cout << "Contains third: " << testEnum.Contains(TestEnum::Third) << std::endl;
	std::cout << "Contains fourth: " << testEnum.Contains(TestEnum::Fourth) << std::endl;
	std::cout << "Contains fifth: " << testEnum.Contains(TestEnum::Fifth) << std::endl;
	std::cout << "Contains sixth: " << testEnum.Contains(TestEnum::Sixth) << std::endl;
#endif
	std::cout << "Size on stack: " << sizeof(testEnum) << " bytes" << std::endl;


	return 0;
}