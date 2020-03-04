#include <ansi.h>

inherit ROOM;

void create()
{
set("short","山口");
 set("long", @LONG
這裡是愛門村通往西邊丘陵小路的路口，在此偶而可以聽到一段一段的
鳥鳴聲。你看到旁邊有一棵大樹，樹幹上釘了張皮革，上面寫了一些紅字。
似乎是一個警告的標示(sign)。
LONG
);
set("item_desc",([
"sign":HIR"\n警告：此處山區有異種生物出沒，村民及旅客注意，三人以下隊伍請勿入山！\n\n"NOR,
]));

set("exits",([
  "southeast":__DIR__"al10",
  "westup":__DIR__"m2",]));
 set("objects",([
 ]));
setup();
}
