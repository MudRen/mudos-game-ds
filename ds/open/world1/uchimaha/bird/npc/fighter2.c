#include <ansi.h>
inherit NPC;
void create()
{
        set_name("大徒弟" , ({ "fighter" }) );
        set("level",16);
        set("race","人類");
        set("gender","男性");
        set("age",28);
        set_skill("dagger",35);
        set_skill("parry", 35);
        set_skill("dodge", 70);
        set_skill("sky-dagger", 30);
        set_skill("bird-eight", 60);
        map_skill("dodge","bird-eight");
        set("long","他是天梟教的大徒弟, 看起來輕功絕佳, 而且武功有一定的造旨了。\n"
           );
        set("chat_chance", 200);
        set("chat_msg_combat",({
            "大徒弟對你喝道：我要讓見識見識天梟教的厲害!!\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger4.c")->wield();
        carry_object(__DIR__"eq/surcoat2.c")->wear();
        carry_object(__DIR__"eq/wrists.c")->wear();
}
