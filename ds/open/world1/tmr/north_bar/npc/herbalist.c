inherit NPC;
inherit SELLMAN;

string gflower(object me);

void create()
{
        set_name("藥舖老板",({ "herbalist" }));
        set("long","這是一個經營藥鋪十幾年的藥鋪老板。"
        );
        set("age",50+random(10));
        set("no_fight",1);
        set("chat_chance", 3);
        set("chat_msg", ({
		  (: command,"say 最近有不少外地客，生意倒是好了不少。" :),
		  (: command,"smile" :),
	}) );
        set("sell_list",([
                __DIR__"obj/appill.c": 20,
                __DIR__"obj/breath-pill.c": 20,
		]));
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}
