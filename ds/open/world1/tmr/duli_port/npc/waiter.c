
#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("旅店服務生", ({ "waiter"}) );
        set_race("human");
        set("age", 20);
        set("long",@long
一個約二十出頭的年輕服務生，正忙進忙出招呼旅客。
long
);

        set("merchandise", ([
                __DIR__"obj/manto": 50,
                "/d/obj/food/manto2": 100,
                __DIR__"obj/dumpling": 50,
                __DIR__"obj/bottle": 20,
                  __DIR__"obj/duck-meat": 2,
                  "/d/obj/bag": 10,
        ]));

        set("chat_chance", 5);
        set("chat_msg", ({
                  "旅店服務生忙著詢問一桌客人所點的酒菜...\n",
                "旅店服務生笑著問你道：「最近有什麼趣聞，可說來聽聽嗎？」\n",
                "旅店服務生聽著一位客人所講的旅行笑話後，咯咯地笑了起來..\n",
         }));
        setup();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

