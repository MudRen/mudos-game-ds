#include <room.h>
inherit ROOM;

void create()
{
  set("short","山腰");
  set("long",@LONG
來到這裡溫度漸漸降低，濕氣也變重了，濕濕冷冷地感覺很不舒
服，四周的樹木都是攀附在岩石上生長，從這裡往上攀爬就可以通往
山頂了。
LONG);
  set("exits",([ 
      "east":__DIR__"room108",
      "northup":__DIR__"room110",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            

int valid_leave(object me, string dir)
{
  if( me->query("orochi_beast_2") )
  {
    if( dir == "northup")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}         
