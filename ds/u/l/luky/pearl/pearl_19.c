// Room: /u/l/luky/room/pearl_19.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠北街"NOR);
set("long", @LONG

＿＿＿＿＿   你正走在寬敞的大街上。西方傳來人  ＿＿＿＿＿＿
"  .   -   群喧嘩的聲音。路面看起來很新，似乎       -     "
:      -   是最近才剛舖設好的。旁邊的圍牆發出       -  "  :
= ."   -   柔柔的光芒，彷彿置身仙境一般。道路       -     =
==-  " -   向兩旁延伸開來。               -         -   -==
￣￣￣￣￣                   ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣

LONG
);
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_18",
"east" : __DIR__"pearl_20",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
