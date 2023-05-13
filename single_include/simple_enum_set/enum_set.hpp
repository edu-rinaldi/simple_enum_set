#pragma once
#include <stddef.h>

namespace es
{
	using Byte = unsigned char;
	using BitSet = unsigned long;

#define ES_CREATE_INDEXED_ENUM(EnumName, first, ...) struct EnumName##Wrapper \
{	\
enum Internal : es::Byte { first = 0, ##__VA_ARGS__, Count};	\
}; \
using EnumName = EnumName##Wrapper::Internal \

	constexpr size_t BitSetSize() { return sizeof(BitSet) * 8; }

	template<typename EnumType>
	class EnumSet
	{
	public:
		bool Contains(const EnumType value) const { return mBuffer[value]; }
		void Insert(const EnumType value) { mBuffer[value] = true; }
		void Remove(const EnumType value) { mBuffer[value] = false; }

	private:
		bool mBuffer[EnumType::Count];
	};

	template<typename EnumType>
	class BitEnumSet
	{
		static_assert(EnumType::Count <= BitSetSize(), "BitEnumSet does not support the size of this enum, check es::BitSetSize()");
	public:
		BitEnumSet() : mBitSet(0) {}

		bool Contains(const EnumType value) const { return (mBitSet >> value) & BitSet(1); }
		void Insert(const EnumType value) { mBitSet |= BitSet(1) << value; }
		void Remove(const EnumType value) { mBitSet &= ~(BitSet(1) << value); }
	private:
		BitSet mBitSet;
	};

}