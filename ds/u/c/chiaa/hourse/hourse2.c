// Room: /u/c/chiaa/hourse/hourse2.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "大頭狗的食物補給站");
  set("long", @LONG
這裡是販賣大頭狗的食物!裡面有乾狗糧,還有飼料!
還有海洋深層水泡的茶!
LONG
        );
        set("valid_startroom", 1);
        set("no_magic", 1);
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 1 */
"east" : __DIR__"hourse0",

]));

 setup();
  replace_program(ROOM);
}
