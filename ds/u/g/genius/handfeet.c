#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
set("short",HIM"�C��K�}��s��"NOR);
set("long", HIB"\n�I�u��......\n\n"NOR);


      set("exits", ([
      "east": "/u/g/genius/roomenter.c",
      ]));
      set("light",1);
set("objects",([
      "/u/g/genius/npc/jojo" : 1,
      ]));
      setup();
}

