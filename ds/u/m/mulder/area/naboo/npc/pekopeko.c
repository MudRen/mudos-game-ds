#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIB"比哥比哥"NOR, ({"peko peko","peko"}) );
        set("race", "野獸");
        set("age",20);
        set("level",16);
        set("attitude","peaceful");
        set("dex",30);
      set("str",20);
      set_temp("fly",1);		        
        set("long",HIB"比哥比哥是一隻身形巨大和十分敏捷的鳥類。\n"NOR);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}

 