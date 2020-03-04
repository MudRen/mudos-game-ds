#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", "衛星戰略基地中央控制室");
  set("long", @LONG

    這裡是攻擊用衛星CHU-52的中央控制室，營幕上的電達正搜尋著每一
個座標。從這裡可以通到衛星基地的各個地方。進到這來，就像進到了大
型的冰庫一般，溫度驟減。房裡所有的東西都被附上了一層薄霜，地上更
是結了厚厚的一層冰。

LONG
);
  set("exits", ([
  "wiz" : "/d/wiz/hall1",
]));
  set("objects",([
  __DIR__"candy" : 1,
]) );

  set("no_clean_up", 1);
  set("light",1);
  setup();
  call_other("/obj/board/kula_b.c","???");
}


