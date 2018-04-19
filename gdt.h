#ifndef GDT_H
#define GDT_H


#include"types.h"

class globalDescriptorTable{

	public:
	class segmentDescriptor{
		private:
		uint16_t segmentLimitLow;
		uint16_t baseAddressLow;
		uint8_t  baseAddressHigh;
		uint8_t  type;
		uint8_t segmentLimitHigh;
		uint8_t baseAddressMSB;
		public:
		segmentDescriptor(uint32_t base,uint32_t limit,uint8_t type);
		uint32_t getBase();
		uint32_t getLimit();






	}__attribute__((__packed__));

	private:
		segmentDescriptor CodeSegmentSelector;
		segmentDescriptor DataSegmentSelector;
		segmentDescriptor nullSegmentSelector;
		segmentDescriptor unusedSegmentSelector;

	public:
		globalDescriptorTable();
		~globalDescriptorTable();

		uint16_t codeSegmentSelector();
		uint16_t dataSegmentSelector();










};








#endif
