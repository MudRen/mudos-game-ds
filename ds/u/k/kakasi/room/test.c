#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIR"���թж�"NOR);
  set ("long", @LONG
               <KAKASI����MOB�ж�>
LONG
);
  set("exits", ([
  "out" : "/u/k/kakasi/workroom",
  
]));
  set("objects",([
  __DIR__"npc/ka.c" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
