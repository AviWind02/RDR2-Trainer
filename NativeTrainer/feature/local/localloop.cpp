#include "pch.h"
#include "localfeatures.h"


namespace feature {
	namespace self {

		void tick()
		{
			SetAlwaysWanted();
			KeepWantedLevel();
			SetPlayerInvulnerable();
			SetHorseInvincible();
			SetHorseUnlimitedStamina();
			RestorePlayerStamina();
			RestoreSpecialAbility();
			SetSuperJump();
			SetRagdoll();
			NeverWanted();
		}
	}// self
}// feature