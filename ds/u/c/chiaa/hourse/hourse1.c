// Room: /u/c/chiaa/hourse/hourse1.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "大頭狗的發呆室");
  set("long", @LONG
有時候在大頭狗的讀書室用腦過度!就會想到這裡來發發呆!
讓大腦休息一下下,也整理一下思緒!再繼續努力!
LONG
        );
        set("valid_startroom", 1);
        set("no_magic", 1);
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 1 */
"out" : __DIR__"hourse0",

]));


 setup();
  replace_program(ROOM);
}
