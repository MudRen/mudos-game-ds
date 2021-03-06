#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
	set_name("乾貨商西塔", ({"food man","man"}) );
	set("long", @LONG
他是礦村中經營乾貨的人類型機械人，專門處理各類食物批到
礦村並且販賣的工作。
LONG
);
	set("race", "人類");
	set("age", 210);
	set("level", 25);
        set("title","機器人");
        set("attitude", "peaceful");
        set("no_fight",1);
        set("storeroom", __DIR__"shop/shop1.c");
	set("sell_list",([
            __DIR__"obj/food1.c": 6,
            __DIR__"obj/food2.c": 6,
            __DIR__"obj/drink1.c": 6,
]));

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
        add_action("do_bespeak","bespeak");
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "西塔說: 有什麼需要呢？請打list(喀喀...)。 \n");
                        break;
                case 1:
                        say( "西塔說: 玻璃櫃裡是剛從星城運來的乾燥糧食(喀喀...)。\n");
                        break;
        }
}


