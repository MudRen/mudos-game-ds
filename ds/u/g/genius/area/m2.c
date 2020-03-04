#include <ansi.h>
inherit ROOM;
void create()
{
set("short","山路");
 set("long", @LONG
你走在一條山路上，路旁不時可以看到各種奇花異草，令人感到無限的
驚奇。不時可見一些松鼠之類的小型哺乳動物跑過，一片自然的氣氛，讓人
覺得這片森林實在是大地之母慈祥的賜予。
LONG
);
set("item_desc",([
"flower":"你眼前所見的是一些美麗的花草，有紅有藍，多是你從未見過的。",
]));

set("exits",([
  "eastdown":__DIR__"m1",
  "southwest":__DIR__"m3",]));
 set("objects",([
 ]));
setup();
}
