#include <ansi.h>
inherit ROOM;
void create()
{
set("short","山路");
 set("long", @LONG
你走在一條山路上，旁邊的樹木十分高大，茂盛的枝葉幾乎將天空掩蓋
了起來。地上踏著沙沙作響的落葉，似乎有種詭譎的氣氛。
LONG
);
set("item_desc",([
]));

set("exits",([
  "north":__DIR__"m6",]));
setup();
}

