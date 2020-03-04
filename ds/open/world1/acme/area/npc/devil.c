#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "旱魃" , ({ "fire devil","devil" }) );
        set("level",40);
        set("race","evil");
        set("gender","中性");
        set("age",500 + random(99));
        set("long","他是一隻通體赤紅的怪物，長髮直垂腦後，拖地尺餘\n"
                   "，髮紅若朱砂，難知雌雄，但為人形！\n"
           );
        set("chat_chance", 8);
        set("chat_msg",({
               "旱魃仰頸向天，正吞吐著一粒碗大水珠，珠升百丈，剛化作火球，珠再降落，又恢復碗口大小。\n",
        }) );
        set_skill("mob_bite", 50);
        setup();
        carry_object(__DIR__"obj/firepill");
        if(random(100)<30) 
                carry_object(__DIR__"obj/fire-onion");
}

