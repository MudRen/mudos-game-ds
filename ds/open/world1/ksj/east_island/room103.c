#include <room.h>
inherit MOBROOM;

void create()
{
  set("short","山腰");
  set("long",@LONG
來到這裡溫度漸漸降低，濕氣也變重了，濕濕冷冷地感覺很不舒
服，四周的樹木都是攀附在岩石上生長，樹形彎彎曲曲地，岩壁上有
許多被東西磨過的痕跡。
LONG);
  set("exits",([ 
      "east":__DIR__"room104",
      "southwest":__DIR__"room102",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("chance",50);
  set("mob_amount",3); 
  set("mob_object",({    
      __DIR__"npc/warrior-ghost2",
     }) );
  setup();
}            
