#include <room.h>
inherit ROOM;

void create()
{
  set("short","出雲山頂");
  set("long",@LONG
這裡是出雲山的山頂，四處岩石嶙嶇，佈滿斑斑白雪，強勁的冷
風挾帶雪花旋繞在岩石之間，你注意到有部份的岩壁好像被什麼東西
磨過似的，顯得比較光滑，四周傳來巨物移動的聲音，你不由得緊張
起來。
LONG);
  set("exits",([ 
      "east":__DIR__"room116",
      "west":__DIR__"room112",
      "south":__DIR__"room117",
      "north":__DIR__"room114",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","snow");
  setup();
}            
