#include "pch.h"
#include "feature/local/localfeatures.h"

namespace base {
	namespace view {
		using namespace GUI;

		static int wantedLevelEdit;
		static int wantedPriceEdit;
		static float rechargeHealMultiplier;
		static float wantedMultiplier;

		void SelfView()
		{
			button::Toggle("Invulnerable", &feature::self::setPlayerInvulnerable);
			button::Toggle("Never Wanted", &feature::self::neverWanted);
			button::Option("Clear Wanted Level", &feature::self::ClearWantedLevel);
			button::Int("Edit Wanted Level", &wantedLevelEdit, 0, 5, 1, []() {
				feature::self::EditWantedLevel(wantedLevelEdit, 1.f);
			});
			button::Toggle("Keep Current Wanted Level", &feature::self::KeepWantedCurrentLevel);
			button::Toggle("Always Wanted", &feature::self::alwaysWanted);
			button::Toggle("Invincible Horse", &feature::self::horseInvincible);
			button::Toggle("Restore Horse Stamina (Looped)", &feature::self::restoreHorseStaminaLooped);
			button::Option("Restore Horse Stamina", &feature::self::restoreHorseStamina);
			button::Toggle("Super Jump", &feature::self::setSuperJump);
			button::Int("Edit Wanted Bounty", &wantedPriceEdit, 0, 5000, 50, []() {
				feature::self::SetWantedPriceOnHead(wantedPriceEdit);
			});
			button::Toggle("Restore Player Stamina (Looped)", &feature::self::restorePlayerStaminaLooped);
			button::Option("Restore Player Stamina", &feature::self::restorePlayerStamina);
			button::Float("Recharge Heal Multiplier", &rechargeHealMultiplier, 1.f, 10.f, .5f, []() {
				feature::self::SetWantedPriceOnHead(rechargeHealMultiplier);
			});
			button::Float("Wanted Level Multiplier", &wantedMultiplier, 1.f, 12.f, .5f, []() {
				feature::self::SetWantedPriceOnHead(wantedMultiplier);
			});
			button::Toggle("Restore Special Ability (Looped)", &feature::self::restoreSpecialAbilityLooped);
			button::Option("Restore Special Ability", &feature::self::restoreSpecialAbility);
			button::Option("Clone Self", &feature::self::ClonePlayer);


	

		}

	}
}