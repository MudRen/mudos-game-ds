
#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
          set_name("藥店老板", ({ "herb seller","seller"}) );
        set_race("human");
        set("age", 40);
        set("long",@long
一個方臉大耳的中年人，滿身充滿著藥味。
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

