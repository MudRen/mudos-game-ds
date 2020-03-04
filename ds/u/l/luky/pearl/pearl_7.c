// Room: /u/l/luky/room/pearl_7.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠南街"NOR);
set("long", @LONG

＿＿＿＿＿   你正走在熱鬧的大街上。這裡的居民  ＿＿＿＿＿＿
"  .   -   似乎並不在意你的到來，還悠哉的溜著     -  '    "
:      -   狗。咦？這狗怎麼有六隻腳！你仔細一     -    "  :
= ."   -   看才知道，原來他們是在溜"螃蟹"。       -       =
==-  " -       -                          -       - .   -==
￣￣￣￣￣￣￣￣￣￣￣￣￣￣ ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣

LONG
);
set("objects",([
__DIR__"npc/cancer1":2,
]));
set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"pearl_8",
  "east" : __DIR__"pearl_6",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
