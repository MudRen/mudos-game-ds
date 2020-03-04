#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"超龍禁衛騎士"NOR , ({ "dragon knight","knight" }) );
        set("level", 30);
        set_skill("parry", 20);
        set_skill("unarmed", 40);
        set_skill("dodge", 30);
        set_skill("sword",50);
        set("long","
你看他身穿精良鎧甲和裝備，從頭盔中漏出一絲
兇惡的眼神，令你直打哆嗦。禁衛騎士是超龍軍團中
的主要戰力，只要是破壞和平的人，他都會義不容辭
的殲滅他們。\n");
        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
        "禁衛騎士打了打哈欠。\n" }) );
        setup();
        carry_object("/u/s/sopher/area/npc/npcwp/knight_stab")->wield();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_ring")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_necklace")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_boots")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/black_helm")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_plate")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/silver_gloves")->wear();
   
}

