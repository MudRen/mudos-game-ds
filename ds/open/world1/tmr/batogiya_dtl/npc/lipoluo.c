#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
    set_name("���ɭ鸨", ({ "ha lipoluo", "lipoluo"}) );
    set_race("human");
    set_attr("int", 30 );
    set_attr("str", 19);
    set_attr("cor", 17);
    set_attr("cps", 15);
    set_attr("dex", 18);
    set("gender", "male");
    set("age", 20);
    set("long",@long
���������]�N�v�A�L�|�\�h���]�N���k�ӮT�֧����A�����S�ƴN��
�ڴΤl���Ӵ��h�A�����ٷ|�M����A�������N���@�ӤH�C
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

