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
		uint32_t baseRearrange();
		uint32_t limitRearrange();






	}__atrribute__((packed));

	private:
		segmentDescriptor codeSegmentSelector;
		segmentDescriptor dataSegmentSelector;
		segmentDescriptor nullSegmentSelector;
		segmentDescriptor unusedSegmentSelector;

	public:
		globalDescriptorTable();
		~globaleDescriptorTable();

		uint16_t codeSegmentSelector();
		uint16_t dataSegmentSelector();










};








#endif
