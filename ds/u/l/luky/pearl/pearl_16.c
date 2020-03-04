// Room: /u/l/luky/room/pearl_16.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠北街"NOR);
set("long", @LONG

  你正位於碧雷爾鎮的珍珠北街。北方是本鎮主要的商店，如果你尚
有多餘的裝[1;33m │       ▃▄▅▆▆▆▅▄▃             │[m 備，不
妨來此中[1;33m   ▲▃▄▅[m│◢◣│◢◣│◢◣│[1;33m▅▄▄▃▃▂▲[m心與其
他冒險者 ▕ │ 田田│田田│田田│田田│ 田 田 │田 ▏▎ 交換
         ▕ │[33m＿▂▃▄▄▅▅▅▅▅▄▄▃▂＿[m  │   ▏▎
￣￣￣￣￣￣￣￣ :╲  ◢◣ ◢◣ ◢◣  ╱: ￣￣￣￣￣￣￣￣￣
:      -         :▕  ︵  ������  ︵  ▏:[1;35m【愛爾裝備中心】[m  :
= ."   -       - :▕  ♁[1;34m   ██[m   ♁  ▏:                  =
==-  " -       - :▕[34m       ██[m       ▏:  -       - .   -==
￣￣￣￣￣￣￣￣￣￣￣￣￣￣  ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣

LONG
);
set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"pearl_29",
"west" : __DIR__"pearl_15",
"east" : __DIR__"pearl_17",
]));
set("no_clean_up", 0);
set("light",1);
setup();
load_object(__DIR__"npc/item/greentea");
}
