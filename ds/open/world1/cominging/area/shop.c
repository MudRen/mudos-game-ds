#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"正字當舖"NOR);
        set("long",@LONG
這是一家當舖，在當舖的裡邊，你看到了許許多多的廢棄物和一些
雜物，似乎都是拿來典當的，旁邊還有一個小小的木門，裡面似乎是放
著一些貴重的物品，在當舖前面的商人在逕自發呆中，往東邊走就是步
靈城的北街。
LONG
        );
        set("objects",([
  __DIR__"npc/shopman.c":1,
]));
        set("exits",([
  "east" :__DIR__"bnorth3.c",
]));
        set("no_clean_up",0);
        set("light",1);
        setup();
}
