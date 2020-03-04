#include <room.h>
inherit ROOM;

void create()
{
  set("short","山坳");
  set("long",@LONG
這裡是一處不深的山坳，山坳上是陡峭的岩壁，不時有石塊跟雪
球滾到山坳前，四周的岩壁上長了一些雜草跟小樹，生命力旺盛的根
部四處攀抓，堅硬的岩石也被撐開了裂縫。
LONG);
  set("exits",([ 
      "north":__DIR__"room98",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"warrior-ice-statue":1,
     ]) );
  setup();
}            
