#include "precompiled.h"
#include "ulduar.h"

/*
The Teleporter appears to be active and stable.

- Expedition Base Camp
- Formation Grounds
- Colossal Forge
- Scrapyard
- Antechamber of Ulduar
- Shattered Walkway
- Conservatory of Life
- Spark of Imagination
- Prison of Yogg-Saron
*/

#define BASE_CAMP    200
#define GROUNDS      201
#define FORGE        202
#define SCRAPYARD    203
#define ANTECHAMBER  204
#define WALKWAY      205
#define CONSERVATORY 206
#define SPARK        207
#define PRISON       208

/*######
## go_ulduar_teleporter (194569)
######*/

bool GOHello_go_ulduar_teleporter(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance *pInstance = (ScriptedInstance *) pGo->GetInstanceData();
    if(!pInstance)
        return false;

    pPlayer->ADD_GOSSIP_ITEM(0, "Expedition Base Camp", GOSSIP_SENDER_MAIN, BASE_CAMP);
    if(pInstance->GetData(TYPE_LEVIATHAN))
    {
        pPlayer->ADD_GOSSIP_ITEM(0, "Formation Grounds", GOSSIP_SENDER_MAIN, GROUNDS);
        if(pInstance->GetData(TYPE_LEVIATHAN) == DONE)
        {
            pPlayer->ADD_GOSSIP_ITEM(0, "Colossal Forge", GOSSIP_SENDER_MAIN, FORGE);
            if(pInstance->GetData(TYPE_XT002))
            {
                pPlayer->ADD_GOSSIP_ITEM(0, "Scrapyard", GOSSIP_SENDER_MAIN, SCRAPYARD);
                if(pInstance->GetData(TYPE_XT002) == DONE)
                {
                    pPlayer->ADD_GOSSIP_ITEM(0, "Antechamber of Ulduar", GOSSIP_SENDER_MAIN, ANTECHAMBER);
                    if(pInstance->GetData(TYPE_KOLOGARN) == DONE)
                    {
                        pPlayer->ADD_GOSSIP_ITEM(0, "Shattered Walkway", GOSSIP_SENDER_MAIN, WALKWAY);
                        if(pInstance->GetData(TYPE_AURIAYA) == DONE)
                        {
                            pPlayer->ADD_GOSSIP_ITEM(0, "Conservatory of Life", GOSSIP_SENDER_MAIN, CONSERVATORY);
                            if(pInstance->GetData(TYPE_MIMIRON))
                            {
                                pPlayer->ADD_GOSSIP_ITEM(0, "Spark of Imagination", GOSSIP_SENDER_MAIN, SPARK);
                                if(pInstance->GetData(TYPE_VEZAX) == DONE)
                                    pPlayer->ADD_GOSSIP_ITEM(0, "Prison of Yogg-Saron", GOSSIP_SENDER_MAIN, PRISON);
                            }
                        }
                    }
                }
            }
        }
    }
    pPlayer->SEND_GOSSIP_MENU(14424, pGo->GetGUID());

    return true;
}

bool GOGossipSelect_go_ulduar_teleporter(Player *pPlayer, GameObject *pGo, uint32 sender, uint32 action )
{
    if(sender != GOSSIP_SENDER_MAIN)
        return true;

    if(!pPlayer->getAttackers().empty())
        return true;

    switch(action)
    {
        case BASE_CAMP:
            pPlayer->TeleportTo(603, -706.122f, -92.6024f, 429.876f, 0);
            pPlayer->CLOSE_GOSSIP_MENU(); break;
        case GROUNDS:
            pPlayer->TeleportTo(603, 131.248f, -35.3802f, 409.804f, 0);
            pPlayer->CLOSE_GOSSIP_MENU(); break;
        case FORGE:
            pPlayer->TeleportTo(603, 553.233f, -12.3247f, 409.679f, 0);
            pPlayer->CLOSE_GOSSIP_MENU(); break;
        case SCRAPYARD:
            pPlayer->TeleportTo(603, 926.292f, -11.4635f, 418.595f, 0);
            pPlayer->CLOSE_GOSSIP_MENU(); break;
        case ANTECHAMBER:
            pPlayer->TeleportTo(603, 1498.09f, -24.246f, 420.967f, 0);
            pPlayer->CLOSE_GOSSIP_MENU(); break;
        case WALKWAY:
            pPlayer->TeleportTo(603, 1859.45f, -24.1f, 448.9f, 0); 
            pPlayer->CLOSE_GOSSIP_MENU(); break;
        case CONSERVATORY:
            pPlayer->TeleportTo(603, 2086.27f, -24.3134f, 421.239f, 0);
            pPlayer->CLOSE_GOSSIP_MENU(); break;
        case SPARK:
            pPlayer->TeleportTo(603, 2536.87f, 2569.15f, 412.304f, 0);
            pPlayer->CLOSE_GOSSIP_MENU(); break;
        case PRISON:
            pPlayer->TeleportTo(603, 2536.87f, 2569.15f, 412.304f, 0);
            pPlayer->CLOSE_GOSSIP_MENU(); break;
    }
    return true;
}


void AddSC_ulduar_teleporter()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "go_ulduar_teleporter";
    newscript->pGOHello = &GOHello_go_ulduar_teleporter;
    newscript->pGOGossipSelect = &GOGossipSelect_go_ulduar_teleporter;
    newscript->RegisterSelf();
}