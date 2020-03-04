#include <room.h>
inherit ROOM;

void create()
{
  set("short","村外小路");
  set("long",@LONG
這裡是村莊外圍通往森林的道路，整條道路已被齊膝的雜草所掩
沒，你的雙腳被雜草所絆，搖搖晃晃走得很狼狽，北方可以看見一大
片的森林，在這邊就能感受得到從森林散發不尋常的詭異氣氛。
LONG);
  set("exits",([ 
      "east":__DIR__"room36",
      "north":__DIR__"room39",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            
