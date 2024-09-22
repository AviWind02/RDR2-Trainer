#pragma once

namespace feature {
	namespace self {

		extern bool setPlayerInvulnerable;
		extern bool horseInvincible;
		extern bool restoreHorseStamina, restoreHorseStaminaLooped;
		extern bool restorePlayerStamina, restorePlayerStaminaLooped;
		extern bool restoreSpecialAbility, restoreSpecialAbilityLooped;
		extern bool setSuperJump;
		extern bool setNoRagdoll;

		extern int storedWantedLevel;
		extern bool KeepWantedCurrentLevel;
		extern bool alwaysWanted;
		extern bool neverWanted;

		void SetWantedLevelMultiplier(float Multiplier);
		void EditWantedLevel(int level, float Multiplier);
		void SetWantedPriceOnHead(float price);
		void ClearWantedLevel();
		void ClonePlayer();
		void SetRechargeHealMultiplierPlayer(float Multiplier);

		//Loops
		void SetAlwaysWanted();
		void KeepWantedLevel();
		void SetPlayerInvulnerable();
		void SetHorseInvincible();
		void SetHorseUnlimitedStamina();
		void RestorePlayerStamina();
		void RestoreSpecialAbility();
		void SetSuperJump();
		void SetRagdoll();
		void NeverWanted();

		void tick();
	}
}
