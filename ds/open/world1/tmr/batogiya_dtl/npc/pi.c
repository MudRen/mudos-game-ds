#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
    set_name("���p��", ({ "ha hou pi", "pi"}) );
    set_race("human");
    set_attr("int", 30 );
    set_attr("str", 19);
    set_attr("cor", 17);
    set_attr("cps", 15);
    set_attr("dex", 18);
    set("gender", "male");
    set("age", 20);
    set("long",@long
�b�������۷��W���H�A�y�֤Q�����p�A�������ȧO�H������
�����A�۷��ۧڭ��檺�@�ӤH�C
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

