#include <room.h>
inherit ROOM;

void create()
{
  set("short","岩石丘");
  set("long",@LONG
這裡是由一些巨大的岩石堆成的小山丘，山丘中有許多岩縫，有
的岩縫外散落一些骨頭，好像有些黑影在岩石間穿梭，往北可以看到
一個較大的岩洞。
LONG);
  set("exits",([ 
      "east":__DIR__"room55",
      "west":__DIR__"room53",
      "south":__DIR__"room49",
      "north":__DIR__"room56",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/ferity-apeman":2,
     ]) );
  setup();
}            
