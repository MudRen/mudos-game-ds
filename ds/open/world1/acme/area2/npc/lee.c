#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李文成",({"wen chen lee","lee"}) );
        set("long","他是八極門護法之一，從他臉上可看得出似乎有些不耐煩。\n");
        set("age",33);
        set("race","人類");
        set("level",25);
        set("title","〈八極門〉護法");
        set("gender", "男性" );
        set("chat_chance",5);
        set("chat_msg",({
            "李文成說道：你還是不承認，別怪我們不客氣了！\n",
            "李文成說道：他奶奶的！我性子可不是很好的！你說不說！\n",
        }) );
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set_skill("parry",40);
        set_skill("bagi_fist",60);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert bagi_fist"):),
        }) );
        setup();
}
