// Room: /u/l/luky/room/pearl_15.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠北街"NOR);
set("long", @LONG

＿＿＿＿＿   這裡是珍珠北街，也是本鎮的交易重地  ＿＿＿＿＿
"  .   -   。路旁放了幾個大箱子，或許是店家不要   -  '    "
:      -   而堆放在路旁的吧。你似乎聽到有人在  ＿＿＿  "  :
= ."   -   說話的聲音，可是並沒有人啊？或許是▕[33m◥██◣[m   =
==-  " -   你的錯覺吧。                      ▕  ▏  ▕  ==
￣￣￣￣￣             ￣￣￣￣￣￣￣￣￣￣￣￣╲▏  ▕￣￣
                                                 ￣￣￣
LONG
);
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_14",
"east" : __DIR__"pearl_16",
]));
set("item_desc",([
//  "box":"一個裝東西用的空箱子。\n",
//  "箱子":"一個裝東西用的空箱子。\n",
]));
set("no_clean_up", 0);
set("light",1);
set("objects",([
__DIR__"obj/box1":1,
]));
setup();
}
