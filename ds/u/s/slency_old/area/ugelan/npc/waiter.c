#include <path.h>

inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("旅店服務生", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 24);
        set("long","這位旅店服務生正辛勤地招呼從世界各地來的旅客們。\n");
	set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", "服務生");
	set("sell_list",([
		"/open/world1/tmr/area/npc/obj/manto" : 8,
		"/open/world1/tmr/area/npc/obj/torch" : 5,
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
                        say( "服務生笑咪咪地說道﹕這位" + RANK_D->query_respect(ob) + "﹐進來喝杯茶﹐休息一下吧。\n");
                        break;
                case 1:
                        say( "服務生拿起手邊菜單﹐說道﹕這位" + RANK_D->query_respect(ob) + "﹐請進請進。\n");
                        break;
                case 2:
                        say( "服務生說道﹕歡迎光臨小店﹐請問需要些什麼呢？\n");
                        break;
        }
}
