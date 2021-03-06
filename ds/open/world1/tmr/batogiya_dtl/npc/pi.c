#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
    set_name("哈厚皮", ({ "ha hou pi", "pi"}) );
    set_race("human");
    set_attr("int", 30 );
    set_attr("str", 19);
    set_attr("cor", 17);
    set_attr("cps", 15);
    set_attr("dex", 18);
    set("gender", "male");
    set("age", 20);
    set("long",@long
在哈哈村相當有名的人，臉皮十分的厚，完全不怕別人的閒言
閒言，相當有自我風格的一個人。
long
);
    set("merchandise", ([
        __DIR__"obj/armor": 35,
        __DIR__"obj/belt": 35,
        __DIR__"obj/boots": 35,
        __DIR__"obj/cloth": 35,
        __DIR__"obj/gloves": 35,
    ]));

    setup();
}

void init()
{
    ::init();
    add_action("do_vendor_list", "list");
}

