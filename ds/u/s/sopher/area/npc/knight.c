#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"�W�s�T���M�h"NOR , ({ "dragon knight","knight" }) );
        set("level", 30);
        set_skill("parry", 20);
        set_skill("unarmed", 40);
        set_skill("dodge", 30);
        set_skill("sword",50);
        set("long","
�A�ݥL�����}�Z�ҩM�˳ơA�q�Y�����|�X�@��
���c�������A�O�A�����G�ۡC�T���M�h�O�W�s�x�Τ�
���D�n�ԤO�A�u�n�O�}�a�M�����H�A�L���|�q���e��
������L�̡C\n");
        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
        "�T���M�h���F������C\n" }) );
        setup();
        carry_object("/u/s/sopher/area/npc/npcwp/knight_stab")->wield();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_ring")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_necklace")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_boots")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/black_helm")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_plate")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/silver_gloves")->wear();
   
}

