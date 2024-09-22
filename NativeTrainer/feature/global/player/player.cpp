#include "pch.h"

namespace feature {
	namespace g_player {
        Player GetPlayerID() {
            return PLAYER::PLAYER_ID();
        }

        Ped GetPlayerPed() {
            return PLAYER::PLAYER_PED_ID();
        }
        Ped GetMount()
        {
            return PED::GET_MOUNT(GetPlayerPed());
        }
        Player GetPlayerPed(int player) {
            return PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
        }

        Player GetPlayerScriptIndex() {
            return PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX());
        }

        Vehicle GetPlayerVehicle() {
            return PED::GET_VEHICLE_PED_IS_IN(GetPlayerPed(), false);
        }

        Vehicle GetPlayerVehicle(int player) {
            return PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player));
        }

        Vector3 GetPlayerCoords() {
            return ENTITY::GET_ENTITY_COORDS(GetPlayerPed(), true, NULL);
        }
        Vector3 GetGamePlayCamRotation() {
            return CAM::GET_GAMEPLAY_CAM_ROT(0);
        }

        float GetPlayerHealth() {
            return ENTITY::GET_ENTITY_HEALTH(GetPlayerPed());
        }

        float GetPlayerMaxHealth() {
            return ENTITY::GET_ENTITY_MAX_HEALTH(GetPlayerPed(), NULL);
        }

        bool IsPlayerInVehicle() {
            return PED::IS_PED_IN_ANY_VEHICLE(GetPlayerPed(), false);
        }

        bool IsPlayerOnFoot() {
            return PED::IS_PED_ON_FOOT(GetPlayerPed());
        }

        bool IsPlayerInCombat() {
            return PED::IS_PED_IN_COMBAT(GetPlayerPed(), 0);
        }

        bool IsPedInjured(Ped ped) {
            return PED::IS_PED_INJURED(ped);
        }


        bool IsPedFatallyInjured(Ped ped) {
            return PED::IS_PED_FATALLY_INJURED(ped);
        }

        bool IsPedDeadOrDying(Ped ped) {
            return PED::IS_PED_DEAD_OR_DYING(ped, NULL);
        }

        bool IsPedAimingFromCover(Ped ped) {
            return PED::IS_PED_AIMING_FROM_COVER(ped);
        }

        bool IsPedReloading(Ped ped) {
            return PED::IS_PED_RELOADING(ped);
        }

        bool IsPedAPlayer(Ped ped) {
            return PED::IS_PED_A_PLAYER(ped);
        }
	}
}