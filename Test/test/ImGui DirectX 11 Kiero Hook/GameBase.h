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

// Created with ReClass.NET 1.2 by KN4CK3R

class Player
{
public:
	char pad_0000[128]; //0x0000
	class ClassO1* PointerToStats; //0x0080
	char pad_0088[2040]; //0x0088
}; //Size: 0x0880
static_assert(sizeof(Player) == 0x880);

class ClassO1
{
public:
	char pad_0000[30256]; //0x0000
	class Vitality* Ptr02; //0x7630
	char pad_7638[88]; //0x7638
	class FOVClass* Ptr01; //0x7690
	char pad_7698[24]; //0x7698
	class Stats* Ptr; //0x76B0
	char pad_76B8[1640]; //0x76B8
	class Armor* ArmorPtr; //0x7D20
	char pad_7D28[864]; //0x7D28
}; //Size: 0x8088
static_assert(sizeof(ClassO1) == 0x8088);

class Stats
{
public:
	char pad_0000[7440]; //0x0000
	uint32_t N00001429; //0x1D10
	int32_t Attack; //0x1D14
	int32_t Defense; //0x1D18
	int32_t Affinity; //0x1D1C
	int32_t Element; //0x1D20
	int32_t ElementAttack; //0x1D24
	int32_t Element2; //0x1D28
	int32_t Element2Attack; //0x1D2C
	int32_t HiddenElement; //0x1D30
	int32_t HiddenElementAttack; //0x1D34
	char pad_1D38[8]; //0x1D38
	int32_t Deviation; //0x1D40
	char pad_1D44[4]; //0x1D44
	int32_t CoatingIndex; //0x1D48
	char pad_1D4C[60]; //0x1D4C
}; //Size: 0x1D88
static_assert(sizeof(Stats) == 0x1D88);

class FOVClass
{
public:
	char pad_0000[1520]; //0x0000
	float FOV; //0x05F0
	char pad_05F4[148]; //0x05F4
}; //Size: 0x0688
static_assert(sizeof(FOVClass) == 0x688);

class Vitality
{
public:
	char pad_0000[96]; //0x0000
	float MaxHealth; //0x0060
	float Health; //0x0064
	char pad_0068[208]; //0x0068
	float N000015B3; //0x0138
	float Stamina; //0x013C
	float N000015B4; //0x0140
	float MaxStamina; //0x0144
	float N000015B5; //0x0148
	float EatTimer; //0x014C
	char pad_0150[312]; //0x0150
}; //Size: 0x0288
static_assert(sizeof(Vitality) == 0x288);

class Armor
{
public:
	char pad_0000[56]; //0x0000
	float SelfImprovement; //0x0038
	float AttackUpS; //0x003C
	float AttackUpL; //0x0040
	float HealthUpS; //0x0044
	float HealthUpL; //0x0048
	float StaminaReducedUseS; //0x004C
	float StaminaReducedUseL; //0x0050
	float WindPressureNegateS; //0x0054
	float AllWindPressureNegate; //0x0058
	float DefenseUpS; //0x005C
	float DefenseUpL; //0x0060
	float ToolUseDrainReduceS; //0x0064
	float ToolUseDrainReduceL; //0x0068
	float N0000186A; //0x006C
	float N0000186D; //0x0070
	float N0000171C; //0x0074
	float N00001870; //0x0078
	float N0000171D; //0x007C
	float RecoveryUpS; //0x0080
	float RecoveryUpL; //0x0084
	float EarPlugS; //0x0088
	float EarPlugL; //0x008C
	float DivineProtection; //0x0090
	char pad_0094[1504]; //0x0094
	float N000017E2; //0x0674
	float BonusArmor; //0x0678
	float FireResistance; //0x067C
	float WaterResistance; //0x0680
	float ThunderResistance; //0x0684
	float IceResistance; //0x0688
	float DragonResistance; //0x068C
	char pad_0690[28]; //0x0690
}; //Size: 0x06AC
static_assert(sizeof(Armor) == 0x6AC);




namespace BaseAddies
{

	class Module
	{
	public:
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle("MonsterHunterWorld.exe");
		//LocalEntity* LocalPlayer = *(LocalEntity**)(LocalPlayerPattern);
		BasePlayer* LocalPlayer = *(BasePlayer**)(moduleBase + 0x5072488);
		Player* Pl = *(Player**)(moduleBase + 0x506D270);   // Stats - FOV / Vitality - Armor


	private:



	};
}



