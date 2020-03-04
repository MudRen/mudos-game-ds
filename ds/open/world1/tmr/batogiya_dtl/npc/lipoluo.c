#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
    set_name("哈粒剝落", ({ "ha lipoluo", "lipoluo"}) );
    set_race("human");
    set_attr("int", 30 );
    set_attr("str", 19);
    set_attr("cor", 17);
    set_attr("cps", 15);
    set_attr("dex", 18);
    set("gender", "male");
    set("age", 20);
    set("long",@long
哈哈村的魔術師，他會許多的魔術戲法來娛樂村民，閒閒沒事就拿
根棒子揮來揮去，有時還會騎掃把，很難捉摸的一個人。
long
);
    set("merchandise", ([
        __DIR__"obj/sword": 35,
        __DIR__"obj/blade": 35,
        __DIR__"obj/axe": 35,
        __DIR__"obj/dagger": 35,
        __DIR__"obj/whip": 35,
    ]));

    setup();
}

void init()
{
    ::init();
    add_action("do_vendor_list", "list");
}

