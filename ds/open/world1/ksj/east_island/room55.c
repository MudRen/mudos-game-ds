#include <room.h>
inherit ROOM;

void create()
{
  set("short","岩石丘");
  set("long",@LONG
這裡是由一些巨大的岩石堆成的小山丘，山丘中有許多岩縫，有
的岩縫外散落一些骨頭，地面上雜亂散佈大小不一的腳印，說是人的
腳印，形狀比例卻又有些不對。
LONG);
  set("exits",([ 
      "west":__DIR__"room54",
      "south":__DIR__"room50",
      "northwest":__DIR__"room56",
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
