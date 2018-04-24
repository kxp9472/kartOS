#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

#include"types.h"

class interruptManager{
	interruptManager();
	~interruptManager();
	struct gateDescriptor{
		uint16_t handlerLower;
		uint16_t codeSegment;
		uint8_t reserved;
		uint8_t typeAndDpl;
		uint8_t handlerUpper;




	}__attribute__((packed));
	gateDescriptor intDescTable[256];
	void globalActivate();
	void globalDeactivate();
	void initIntDescTable(uint8_t intNum,void (*handler)(),uint16_t codeSegmentOffset,uint8_t 		descriptorType,uint8_t descriptorPrivilegeLevel);
	};














#endif
