#include <ansi.h>
inherit NPC;
void create()
{
        set_name("旅人" ,({ "traveler" }) );
        set("level",4);
        set("race","人類");
        set("gender","男性");
        set("age", 35);
        set("long", "他是一個遊遍世界各地的旅人。\n");
        set("evil",-10);
        set("str",6);
        setup();
        add_money("coin",100);
        carry_object(__DIR__"obj/map");
        carry_object(__DIR__"eq/boots1.c")->wear();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
 say("旅人說道：傳說天池後方的瀑布晚上會發出亮光，不知是神怪還是寶物\n");
  say("旅人說道：這位" + RANK_D->query_respect(ob) + "還是事事小心為妙。\n");
                        break;
        }
}

