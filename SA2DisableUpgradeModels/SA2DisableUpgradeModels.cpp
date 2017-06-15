// SA2DisableUpgradeModels.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "..\sa2-mod-loader\SA2ModLoader\include\SA2ModLoader.h"
#include "..\mod-loader-common\ModLoaderCommon\IniFile.hpp"

#define upgradecheck(name) bool Disable##name = settings->getBool("", "Disable"#name, true)

extern "C"
{
	__declspec(dllexport) void Init(const char *path, const HelperFunctions &helperFunctions)
	{
		const IniFile *settings = new IniFile(std::string(path) + "\\config.ini");
		upgradecheck(SonicLightShoes);
		upgradecheck(SonicMagicGloves);
		upgradecheck(SonicFlameRing);
		upgradecheck(SonicBounceBracelet);
		upgradecheck(TailsBooster);
		upgradecheck(TailsBazooka);
		upgradecheck(TailsLaserBlaster);
		upgradecheck(KnucklesShovelClaw);
		upgradecheck(KnucklesSunglasses);
		upgradecheck(KnucklesHammerGloves);
		upgradecheck(KnucklesAirNecklace);
		upgradecheck(ShadowAirShoes);
		upgradecheck(ShadowFlameRing);
		upgradecheck(EggmanJetEngine);
		upgradecheck(EggmanLargeCannon);
		upgradecheck(EggmanLaserBlaster);
		upgradecheck(EggmanProtectiveArmor);
		upgradecheck(RougePickNails);
		upgradecheck(RougeTreasureScope);
		upgradecheck(RougeIronBoots);
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
		if (DisableRougePickNails && DisableRougeTreasureScope && DisableRougeIronBoots)
			WriteJump((void*)0x730FEF, (void*)0x73112A);
		else
		{
			if (DisableRougeTreasureScope)
				WriteJump((void*)0x730FEF, (void*)0x73104B);
			if (DisableRougeIronBoots)
				WriteJump((void*)0x73104B, (void*)0x73109C);
			if (DisableRougePickNails)
				WriteJump((void*)0x73109C, (void*)0x73112A);
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
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}