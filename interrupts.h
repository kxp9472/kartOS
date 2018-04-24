#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

#include"types.h"
#include"gdt.h"
class interruptManager{
	public:
	interruptManager(globalDescriptorTable * gdtPtr);
	~interruptManager();
	protected:
	struct gateDescriptor{
		uint16_t handlerLower;
		uint16_t codeSegment;
		uint8_t reserved;
		uint8_t typeAndDpl;
		uint8_t handlerUpper;




	}__attribute__((packed));
	static gateDescriptor intDescTable[256];
	public:	
	void globalActivate();
	void globalDeactivate();
	protected:
	void initIntDescTable(uint8_t intNum,void (*handler)(),uint16_t codeSegmentOffset,uint8_t 		descriptorType,uint8_t descriptorPrivilegeLevel,uint8_t present);
	
	};














#endif
