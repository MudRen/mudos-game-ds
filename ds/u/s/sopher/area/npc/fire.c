#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIR"【火龍騎團】"HIW"靈劍士"NOR , ({ "spirit man","man" }) );
        set("level", 30);
        set("attitude","peacefull");
        set_skill("parry", 50);
        set_skill("dodge", 80);
        set_skill("sword",100);
        set("long","
眼前這位威武的劍士，正是超龍軍團-火龍騎隊
的主要戰力，身著火紅色鎧甲，拿著一把泛著火炎
的巨劍，任何人看了，都會退避三舍。\n");
        setup();
        carry_object("/u/s/sopher/area/npc/npcwp/fire_sword")->wield();
        carry_object("/u/s/sopher/area/npc/npceq/fire_boots")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/fire_helm")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/fire_plate")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/fire_gloves")->wear();
   
}

