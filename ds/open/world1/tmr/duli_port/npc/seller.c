
#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
          set_name("�ĩ��ѪO", ({ "herb seller","seller"}) );
        set_race("human");
        set("age", 40);
        set("long",@long
�@�Ӥ��y�j�ժ����~�H�A�����R�����Ĩ��C
long
);

        set("merchandise", ([
                __DIR__"obj/pellet": 20,
                  __DIR__"obj/combest_pill": 60,
        ]));
        setup();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

