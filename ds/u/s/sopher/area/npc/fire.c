#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIR"�i���s�M�Ρj"HIW"�F�C�h"NOR , ({ "spirit man","man" }) );
        set("level", 30);
        set("attitude","peacefull");
        set_skill("parry", 50);
        set_skill("dodge", 80);
        set_skill("sword",100);
        set("long","
���e�o��ªZ���C�h�A���O�W�s�x��-���s�M��
���D�n�ԤO�A���ۤ������Z�ҡA���ۤ@��x�ۤ���
�����C�A����H�ݤF�A���|�h�פT�١C\n");
        setup();
        carry_object("/u/s/sopher/area/npc/npcwp/fire_sword")->wield();
        carry_object("/u/s/sopher/area/npc/npceq/fire_boots")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/fire_helm")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/fire_plate")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/fire_gloves")->wear();
   
}

