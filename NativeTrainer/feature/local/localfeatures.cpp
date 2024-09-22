#include <natives.h>
#include "feature/global/player/player.h"
namespace feature {
	namespace self {

        bool setPlayerInvulnerable, setPlayerInvulnerableReset;
        void SetPlayerInvulnerable() {
            if (setPlayerInvulnerable && !setPlayerInvulnerableReset) {
                ENTITY::SET_ENTITY_INVINCIBLE(feature::g_player::GetPlayerPed(), true);
                setPlayerInvulnerableReset = true;
            }
            else if (!setPlayerInvulnerable && setPlayerInvulnerableReset) {//Reset just in case the engine does not set it to false.
                ENTITY::SET_ENTITY_INVINCIBLE(feature::g_player::GetPlayerPed(), false);
                setPlayerInvulnerableReset = false;
            }
        }
        bool horseInvincible, horseInvincibleReset;
        void SetHorseInvincible() {
            if (horseInvincible) {
                if (PED::IS_PED_ON_MOUNT(feature::g_player::GetPlayerPed())) {
                    ENTITY::SET_ENTITY_INVINCIBLE(feature::g_player::GetMount(), true);
                    setPlayerInvulnerableReset = true;
                }
            }
            else if (!horseInvincible && horseInvincibleReset) {
                if (PED::IS_PED_ON_MOUNT(feature::g_player::GetPlayerPed())) {
                    ENTITY::SET_ENTITY_INVINCIBLE(feature::g_player::GetMount(), false);
                    setPlayerInvulnerableReset = false;
                }
            }
        }

        bool restoreHorseStamina, restoreHorseStaminaLooped;
        void SetHorseUnlimitedStamina() {
            if (restoreHorseStamina || restoreHorseStaminaLooped) {
                if (PED::IS_PED_ON_MOUNT(feature::g_player::GetPlayerPed())) {
                    PED::SET_PED_STAMINA(feature::g_player::GetMount(), 100.0);
                    restoreHorseStamina = false;
                }
            }
        }
        
        bool restorePlayerStamina, restorePlayerStaminaLooped;
        void RestorePlayerStamina() {
            if (restorePlayerStamina || restorePlayerStaminaLooped) {
                PLAYER::RESTORE_PLAYER_STAMINA(feature::g_player::GetPlayerPed(), 100.0);
                restorePlayerStamina = false;
            }
        }
        
        bool restoreSpecialAbility, restoreSpecialAbilityLooped;
        void RestoreSpecialAbility() {
            if (restoreSpecialAbility || restoreSpecialAbilityLooped) {
                PLAYER::RESTORE_SPECIAL_ABILITY(feature::g_player::GetPlayerPed(), -1, false);
                restoreSpecialAbility = false;
            }
        }
        
        bool setSuperJump;
        void SetSuperJump() {
            if (setSuperJump) {
                GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(feature::g_player::GetPlayerPed());
            }
        }

        bool setNoRagdoll;
        void SetRagdoll() {
            if (setNoRagdoll)
            {
                PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(feature::g_player::GetPlayerPed(), false);
                PED::SET_PED_CAN_RAGDOLL(feature::g_player::GetPlayerPed(), false);
            }
        }

        bool setPlayerInvincible, setPlayerInvincibleReset;
        void SetPlayerInvincible() {
            if (setPlayerInvincible)
            {
                ENTITY::SET_ENTITY_INVINCIBLE(feature::g_player::GetPlayerPed(), true);
                setPlayerInvincibleReset = true;
            }
            else if (setPlayerInvincibleReset)
            {
                ENTITY::SET_ENTITY_INVINCIBLE(feature::g_player::GetPlayerPed(), false);
                setPlayerInvincibleReset = false;
            }
        }

        void ClonePlayer() {
            PED::CLONE_PED(feature::g_player::GetPlayerPed(), ENTITY::GET_ENTITY_HEADING(feature::g_player::GetPlayerPed()), 0, 1);
        }

        void SetRechargeHealMultiplierPlayer(float Multiplier) {
            PLAYER::SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(feature::g_player::GetPlayerPed(), Multiplier);
        }
	}
}