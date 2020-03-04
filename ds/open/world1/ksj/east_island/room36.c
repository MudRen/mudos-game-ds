#include <room.h>
inherit ROOM;

void create()
{
  set("short","村外小路");
  set("long",@LONG
這裡是村莊外圍通往森林的道路，由於少有人經過，路面上長滿
了小草，路旁立了尊佛像，但缺少人維護而顯得斑痕累累。
LONG);
  set("exits",([ 
      "west":__DIR__"room37",
      "south":__DIR__"room20",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"statue":1,
     ]));
  setup();
}            
