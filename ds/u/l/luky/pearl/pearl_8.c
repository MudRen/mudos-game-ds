// Room: /u/l/luky/room/pearl_8.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠南街"NOR);
set("long", @LONG

＿＿＿＿＿   你正走在熱鬧的大街上。南方是本鎮  ＿＿＿＿＿＿
"  .   -   唯一的一間[1;33m旅館[m，不少人進進出出的，     -  '    "
:      -   生意似乎很好。或許你可以在這裡遇見     -    "  :
= ."   -   你多日不見的戰友也說不定。             -       =
==-  " -       -                          -       - .   -==
￣￣￣￣￣￣￣￣￣￣￣￣￣￣ ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣

LONG
);
set("exits", ([ /* sizeof() == 3 */
"west" : __DIR__"pearl_9",
"south" : __DIR__"pearl_35",
"east" : __DIR__"pearl_7",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
