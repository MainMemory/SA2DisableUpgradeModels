// SA2DisableUpgradeModels.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "..\sa2-mod-loader\SA2ModLoader\include\SA2ModLoader.h"
#include "..\mod-loader-common\ModLoaderCommon\IniFile.hpp"

#define upgradecheck(chara,name) bool Disable##chara##name = settings->getBool(#chara, "Disable"#name, true)

extern "C"
{
	__declspec(dllexport) void Init(const char *path, const HelperFunctions &helperFunctions)
	{
		const IniFile *settings = new IniFile(std::string(path) + "\\config.ini");
		upgradecheck(Sonic,LightShoes);
		upgradecheck(Sonic,MagicGloves);
		upgradecheck(Sonic,FlameRing);
		upgradecheck(Sonic,BounceBracelet);
		upgradecheck(Tails,Booster);
		upgradecheck(Tails,Bazooka);
		upgradecheck(Tails,LaserBlaster);
		upgradecheck(Knuckles,ShovelClaw);
		upgradecheck(Knuckles,Sunglasses);
		upgradecheck(Knuckles,HammerGloves);
		upgradecheck(Knuckles,AirNecklace);
		upgradecheck(Shadow,AirShoes);
		upgradecheck(Shadow,FlameRing);
		upgradecheck(Eggman,JetEngine);
		upgradecheck(Eggman,LargeCannon);
		upgradecheck(Eggman,LaserBlaster);
		upgradecheck(Eggman,ProtectiveArmor);
		upgradecheck(Rouge,PickNails);
		upgradecheck(Rouge,TreasureScope);
		upgradecheck(Rouge,IronBoots);
		delete settings;
		if (DisableSonicLightShoes && DisableSonicMagicGloves && DisableSonicFlameRing && DisableSonicBounceBracelet && DisableShadowAirShoes && DisableShadowFlameRing)
			WriteJump((void*)0x7207CC, (void*)0x720A82);
		else
		{
			if (DisableSonicFlameRing && DisableShadowFlameRing)
				WriteJump((void*)0x7207CC, (void*)0x7208C1);
			else if (DisableSonicFlameRing)
				WriteData((int*)0x7207D0, (int)Upgrades_ShadowFlameRing);
			else if (DisableShadowFlameRing)
				WriteData((int*)0x7207D0, (int)Upgrades_SonicFlameRing);
			if (DisableSonicBounceBracelet)
				WriteJump((void*)0x7208C1, (void*)0x7209C0);
			if (DisableSonicMagicGloves)
				WriteJump((void*)0x7209C0, (void*)0x7209EA);
			if (DisableSonicLightShoes)
				WriteJump((void*)0x7209EA, (void*)0x720A34);
			if (DisableShadowAirShoes)
				WriteJump((void*)0x720A34, (void*)0x720A82);
		}
		if (DisableKnucklesShovelClaw && DisableKnucklesSunglasses && DisableKnucklesHammerGloves && DisableKnucklesAirNecklace)
			WriteJump((void*)0x72F4CD, (void*)0x72F601);
		else
		{
			if (DisableKnucklesSunglasses)
				WriteJump((void*)0x72F4CD, (void*)0x72F528);
			if (DisableKnucklesAirNecklace)
				WriteJump((void*)0x72F528, (void*)0x72F564);
			if (DisableKnucklesShovelClaw && DisableKnucklesHammerGloves)
				WriteJump((void*)0x72F564, (void*)0x72F601);
			else if (DisableKnucklesShovelClaw)
			{
				WriteJump((void*)0x72F583, (void*)0x72F59E);
				WriteJump((void*)0x72F5CB, (void*)0x72F5E6);
			}
			else if (DisableKnucklesHammerGloves)
			{
				WriteJump((void*)0x72F59E, (void*)0x72F5B9);
				WriteJump((void*)0x72F5E6, (void*)0x72F601);
			}
		}
		if (DisableRougeTreasureScope && DisableRougeIronBoots)
			WriteJump((void*)0x730FEF, (void*)0x73109C);
		else
		{
			if (DisableRougeTreasureScope)
				WriteJump((void*)0x730FEF, (void*)0x73104B);
			if (DisableRougeIronBoots)
				WriteJump((void*)0x73104B, (void*)0x73109C);
		}
		if (DisableRougePickNails)
		{
			WriteJump((void*)0x7310BF, (void*)0x7310D0);
			WriteJump((void*)0x731106, (void*)0x731117);
		}
		if (DisableEggmanLaserBlaster)
			WriteJump((void*)0x74490B, (void*)0x74496B);
		if (DisableEggmanLargeCannon)
			WriteJump((void*)0x744DF3, (void*)0x744E59);
		if (DisableEggmanJetEngine)
			WriteJump((void*)0x744FD1, (void*)0x745064);
		if (DisableEggmanProtectiveArmor)
			WriteJump((void*)0x745112, (void*)0x74515D);
		if (DisableTailsLaserBlaster)
			WriteJump((void*)0x74815F, (void*)0x7481C3);
		if (DisableTailsBazooka)
			WriteJump((void*)0x74860E, (void*)0x748717);
		if (DisableTailsBooster)
			WriteJump((void*)0x7488CF, (void*)0x748948);
		for (int *i = (int*)0x104CEA0; i < (int*)0x104CEE8; ++i)
			switch (*i)
			{
			case UpgradeBits_SonicLightShoes:
				if (DisableSonicLightShoes)
					*i = -1;
				break;
			case UpgradeBits_SonicMagicGloves:
				if (DisableSonicMagicGloves)
					*i = -1;
				break;
			case UpgradeBits_SonicFlameRing:
				if (DisableSonicFlameRing)
					*i = -1;
				break;
			case UpgradeBits_SonicBounceBracelet:
				if (DisableSonicBounceBracelet)
					*i = -1;
				break;
			case UpgradeBits_KnucklesShovelClaw:
				if (DisableKnucklesShovelClaw)
					*i = -1;
				break;
			case UpgradeBits_KnucklesSunglasses:
				if (DisableSonicLightShoes)
					*i = -1;
				break;
			case UpgradeBits_KnucklesHammerGloves:
				if (DisableKnucklesHammerGloves)
					*i = -1;
				break;
			case UpgradeBits_KnucklesAirNecklace:
				if (DisableKnucklesAirNecklace)
					*i = -1;
				break;
			case UpgradeBits_ShadowAirShoes:
				if (DisableShadowAirShoes)
					*i = -1;
				break;
			case UpgradeBits_ShadowFlameRing:
				if (DisableShadowFlameRing)
					*i = -1;
				break;
			case UpgradeBits_RougePickNails:
				if (DisableRougePickNails)
					*i = -1;
				break;
			case UpgradeBits_RougeTreasureScope:
				if (DisableRougeTreasureScope)
					*i = -1;
				break;
			case UpgradeBits_RougeIronBoots:
				if (DisableRougeIronBoots)
					*i = -1;
				break;
			}
		for (int *i = (int*)0x104CE18; i < (int*)0x104CE94; ++i)
			switch (*i)
			{
			case UpgradeBits_SonicLightShoes:
				if (DisableSonicLightShoes)
					*i = -1;
				break;
			case UpgradeBits_SonicMagicGloves:
				if (DisableSonicMagicGloves)
					*i = -1;
				break;
			case UpgradeBits_SonicFlameRing:
				if (DisableSonicFlameRing)
					*i = -1;
				break;
			case UpgradeBits_SonicBounceBracelet:
				if (DisableSonicBounceBracelet)
					*i = -1;
				break;
			case UpgradeBits_TailsBooster:
				if (DisableTailsBooster)
					*i = -1;
				break;
			case UpgradeBits_TailsBazooka:
				if (DisableTailsBazooka)
					*i = -1;
				break;
			case UpgradeBits_TailsLaserBlaster:
				if (DisableTailsLaserBlaster)
					*i = -1;
				break;
			case UpgradeBits_KnucklesShovelClaw:
				if (DisableKnucklesShovelClaw)
					*i = -1;
				break;
			case UpgradeBits_KnucklesSunglasses:
				if (DisableSonicLightShoes)
					*i = -1;
				break;
			case UpgradeBits_KnucklesHammerGloves:
				if (DisableKnucklesHammerGloves)
					*i = -1;
				break;
			case UpgradeBits_KnucklesAirNecklace:
				if (DisableKnucklesAirNecklace)
					*i = -1;
				break;
			case UpgradeBits_ShadowAirShoes:
				if (DisableShadowAirShoes)
					*i = -1;
				break;
			case UpgradeBits_ShadowFlameRing:
				if (DisableShadowFlameRing)
					*i = -1;
				break;
			case UpgradeBits_EggmanJetEngine:
				if (DisableEggmanJetEngine)
					*i = -1;
				break;
			case UpgradeBits_EggmanLargeCannon:
				if (DisableEggmanLargeCannon)
					*i = -1;
				break;
			case UpgradeBits_EggmanLaserBlaster:
				if (DisableEggmanLaserBlaster)
					*i = -1;
				break;
			case UpgradeBits_EggmanProtectiveArmor:
				if (DisableEggmanProtectiveArmor)
					*i = -1;
				break;
			case UpgradeBits_RougePickNails:
				if (DisableRougePickNails)
					*i = -1;
				break;
			case UpgradeBits_RougeTreasureScope:
				if (DisableRougeTreasureScope)
					*i = -1;
				break;
			case UpgradeBits_RougeIronBoots:
				if (DisableRougeIronBoots)
					*i = -1;
				break;
			}
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}