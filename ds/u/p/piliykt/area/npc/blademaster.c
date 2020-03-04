#include <ansi.h>
inherit NPC;
void create()
{
        set_name("上官樂", ({ "blade-master-guard","guard" }) );
        set("title",HIG "刀將" NOR);
        set("level", 35);
        set("race","人類");
        set("gender","男性");
        set("age",35);
        set("dex", 60);
        set("con", 70);
        add("addition_armor",70);        
        add("addition_damage",60);                
        set_skill("blade", 100);
        set_skill("parry", 60);
        set_skill("unarmed", 70);
        set_skill("dodge", 80);
        set("long",
   "一位王爺的護衛，身手非凡武藝高強，刀術更是出神入化。\n");
        setup();
        carry_object(__DIR__"wp/blade_1.c")->wield();
        carry_object(__DIR__"eq/shield_1.c")->wear();
}


        
        
        
 


