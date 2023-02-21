

BaseAddies::Module Hack;

typedef int(__stdcall SetMaxSharpness(int sharpness));
SetMaxSharpness* MaxSharpness = *(SetMaxSharpness*)(Hack.moduleBase + 0x021417AF);


