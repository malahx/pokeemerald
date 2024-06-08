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
    struct Pokemon *pokemon;
    u32 monItem;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        pokemon = &gPlayerParty[i];
        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES, NULL) && !GetMonData(pokemon, MON_DATA_IS_EGG, NULL))
        {
            if (GetMonAilment(pokemon) == AILMENT_FNT)
            {
                monItem = GetMonData(pokemon, MON_DATA_HELD_ITEM, NULL);

                if (monItem != ITEM_NONE)
                {
                    AddBagItem(monItem, 1);
                    SetMonData(pokemon, MON_DATA_HELD_ITEM, ITEM_NONE);
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
