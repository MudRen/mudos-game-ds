#include <ansi.h>
inherit NPC;
void create()
{
        set_name("信徒" , ({ "believer" }) );
        set("level",8);
        set("race","人類");
        set("gender","男性");
        set("age",38);
        set_skill("parry", 20);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set("long","他是天梟教的忠實信徒, 他正在對天梟膜拜。\n"
           );
        set("chat_chance", 200);
        set("chat_msg_combat",({
            "信徒喝道：不要小看了我!\n", 
        }) );
        setup();
     
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
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
           case 0:
               say("信徒對你說道：你知道天梟教的由來嗎??\n");
               break;
        }
}
