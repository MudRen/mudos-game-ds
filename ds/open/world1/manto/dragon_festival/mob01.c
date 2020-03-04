inherit NPC;
inherit SELLMAN;

#include <ansi.h>

void create()
{
        set_name("屈臣示", ({ "qu chen shi","qu","chen","shi" }) );
        set("title",HIY"屈家後人"NOR);
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);



 set("chat_chance",5);
 set("chat_msg", ({"屈臣示很無聊的用腳尖踢了踢地上的石頭。\n",
                "屈臣示小聲地說道﹕每次這個時候就被硬逼出來當小販．．．\n",
 }));
set("inquiry", ([
"屈原":"喔，我那個游泳圈破掉溺死的祖先？\n",
]));
       setup();

        set("attitude", "friendly");

        set("sell_list",([
                __DIR__"obj/item01" : 50,
                __DIR__"obj/item02" : 50,
                __DIR__"obj/item03" : 50,
                __DIR__"obj/item04" : 30,
                __DIR__"obj/item05" : 30,
                __DIR__"obj/item06" : 30,
        ]) );
        setup();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
      switch( random(3) ) {
                case 0:
                        say( "屈臣示懶洋洋地說道﹕這位" + RANK_D->query_respect(ob) + "﹐要不要買點食材包粽子阿？\n");
                        break;
                case 1:
                        say( "屈臣示很無聊的用腳尖踢了踢地上的石頭。\n");
                        break;
                case 2:
                      say( "屈臣示小聲地說道﹕每次這個時候就被硬逼出來當小販．．．\n");
                        break;
        }
}
