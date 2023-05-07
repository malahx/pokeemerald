#include "global.h"
#include "battle.h"
#include "item.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "save.h"
#include "constants/items.h"
#include "constants/party_menu.h"

void ShinyLockDeletePartyMon(u8 position)
{
    PurgeMonOrBoxMon(TOTAL_BOXES_COUNT, position);
}
void ShinyLockDeleteFaintedPartyPokemon(void) // @Kurausukun
{
    u8 i, monTeam = 0;
    struct Pokemon *mon;
    u32 monItem;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES, NULL) && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
        {
            if (GetMonAilment(mon) == AILMENT_FNT)
            {
                monItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);

                if (monItem != ITEM_NONE)
                {
                    AddBagItem(monItem, 1);
                    SetMonData(mon, MON_DATA_HELD_ITEM, ITEM_NONE);
                }
                ShinyLockDeletePartyMon(i);
            }
            else 
            {
                monTeam++;
            }
        }
    }
    CompactPartySlots();
    if (monTeam == 0)
    {
        ClearSaveData();
        DoSoftReset();
    }
}
f32 ExpFactor(u8 enemyLevel, u8 monLevel)
{
    return max(1.0 / max(monLevel - enemyLevel, 1.0) - 0.1, 0.0);
}