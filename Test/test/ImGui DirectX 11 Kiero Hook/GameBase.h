#include <cstdint>



// Created with ReClass.NET 1.2 by KN4CK3R

// Created with ReClass.NET 1.2 by KN4CK3R

class BasePlayer
{
public:
	char pad_0000[184]; //0x0000
	float Gravity; //0x00B8
	float GravitySpeedRate; //0x00BC
	char pad_00C0[600]; //0x00C0
	float HealthInitial; //0x0318
	float HealthMax; //0x031C
	float HpRecoverRatio; //0x0320
	float HpRecoverDelay; //0x0324
	float HpRecoverInterval; //0x0328
	float HpRecoverAmount; //0x032C
	float StaminaInitial; //0x0330
	float StaminaMax; //0x0334
	float StaminaTired; //0x0338
	float StaminaRecover; //0x033C
	float StaminaRegenRate; //0x0340
	char pad_0344[1116]; //0x0344
	float HRFixedAttackRate; //0x07A0
	float MRFixedAttackRate; //0x07A4
	float CriticalDamage; //0x07A8
	float AntiCriticalDmg; //0x07AC
	char pad_07B0[24]; //0x07B0
	float PhysicalDefense; //0x07C8
	float ElementalDefense; //0x07CC
	float N000004D7; //0x07D0
	char pad_07D4[8]; //0x07D4
	float StunLimit; //0x07DC
	float N0000053F; //0x07E0
	float ExhaustLimit; //0x07E4
	float N00000541; //0x07E8
	char pad_07EC[336]; //0x07EC
	bool N0000059B; //0x093C
	bool N00000618; //0x093D
	char pad_093E[2]; //0x093E
	float WalkMotionSpeed; //0x0940
	char pad_0944[59]; //0x0944
	bool N00000620; //0x097F
	float RunMotionSpeed; //0x0980
	char pad_0984[944]; //0x0984
}; //Size: 0x0D34
static_assert(sizeof(BasePlayer) == 0xD34);

class N000004FB
{
public:
	char pad_0000[32]; //0x0000
	int64_t N00000500; //0x0020
	char pad_0028[96]; //0x0028
}; //Size: 0x0088
static_assert(sizeof(N000004FB) == 0x88);



namespace BaseAddies
{

	class Module
	{
	public:
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle("MonsterHunterWorld.exe");
		//LocalEntity* LocalPlayer = *(LocalEntity**)(LocalPlayerPattern);
		BasePlayer* LocalPlayer = *(BasePlayer**)(moduleBase + 0x5072488);




	private:



	};
}



