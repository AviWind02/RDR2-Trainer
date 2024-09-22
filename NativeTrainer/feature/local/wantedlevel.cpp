#include <natives.h>
#include "feature/global/player/player.h"
namespace feature {
	namespace self {

        int storedWantedLevel;
        bool KeepWantedCurrentLevel;
        bool alwaysWanted, alwaysWantedReset;
        bool neverWanted;

        void SetWantedLevelMultiplier(float Multiplier) {
            PLAYER::SET_WANTED_LEVEL_MULTIPLIER(Multiplier);
        }

        void EditWantedLevel(int level, float Multiplier) {
            PURSUIT::SET_PLAYER_WANTED_INTENSITY(feature::g_player::GetPlayerPed(), level);
            SetWantedLevelMultiplier(Multiplier);
        }

        void SetWantedPriceOnHead(float price) {
            PURSUIT::SET_PLAYER_PRICE_ON_A_HEAD(feature::g_player::GetPlayerPed(), price);
        }

        void ClearWantedLevel() {
            PURSUIT::CLEAR_CURRENT_PURSUIT();
            PURSUIT::SET_PLAYER_PRICE_ON_A_HEAD(feature::g_player::GetPlayerPed(), 0);
            EditWantedLevel(0, 0.f);
        }

        void NeverWanted()
        {
            if (neverWanted){
                ClearWantedLevel();
            }
        }

        void SetAlwaysWanted() {
            if (alwaysWanted) {
                EditWantedLevel(5, 1.f);
                alwaysWantedReset = true;
            }
            else {//Reset wanted level if false
                if (alwaysWantedReset)
                    ClearWantedLevel();
                alwaysWantedReset = false;
            }
        }


        void KeepWantedLevel() {
            if (KeepWantedCurrentLevel)
            {
                storedWantedLevel = PLAYER::GET_PLAYER_WANTED_LEVEL(feature::g_player::GetPlayerPed());
                EditWantedLevel(storedWantedLevel, 1.f);
            }
        }

	}
}