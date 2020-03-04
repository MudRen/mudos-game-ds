#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小徒弟" , ({ "little fighter", "fighter" }) );
        set("level",12);
        set("race","人類");
        set("gender","男性");
        set("age",20);
        set_skill("dagger",25);
        set_skill("parry", 25);
        set_skill("dodge", 45);
        set_skill("bird-eight", 20);
        map_skill("dodge","bird-eight");
        set("long","他是天梟教的小徒弟, 看起來輕功不錯, 但是武功卻不怎麼樣。\n"
           );
        set("chat_chance", 200);
        set("chat_msg_combat",({
            "小弟喝道：我要讓你知道小徒弟也是不好惹的!!\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger2.c")->wield();
}
void init()
{
object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
           case 0:
               say("小徒弟對你說道：你是邢獨風老師的徒弟嗎??\n");
               break;
        }
}
