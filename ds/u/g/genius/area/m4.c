#include <ansi.h>
inherit ROOM;
void create()
{
set("short","山路");
 set("long", @LONG
你走在一條山路上，在你前面的是兩塊巨石，中間有一個窄道可以讓人
順著階梯爬上去。灰色的巨石上攀附著幾條爬牆植物，可以見到一些大螞蟻
在上面爬著，似乎在找尋食物。
LONG
);
set("item_desc",([
]));

set("exits",([
  "north":__DIR__"m3",
  "southup":__DIR__"m5",]));
 set("objects",([
 ]));
setup();
}
