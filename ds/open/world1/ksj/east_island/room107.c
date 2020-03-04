#include <room.h>
inherit ROOM;

void create()
{
  set("short","山腰");
  set("long",@LONG
來到這裡溫度漸漸降低，濕氣也變重了，濕濕冷冷地感覺很不舒
服，四周的樹木都是攀附在岩石上生長，樹形彎彎曲曲地，岩壁上有
許多被東西磨過的痕跡。
LONG);
  set("exits",([ 
      "southwest":__DIR__"room108",
      "north":__DIR__"room105",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/five-head-snake":1,
     ]) );
  setup();
}            
