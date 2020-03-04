#include <ansi2.h>
inherit ROOM;
void create()
{
  set ("short", YEL"黃沙平原"NOR);
  set ("long", @LONG
這裡是一望無際的大沙漠，除了零星分佈的耐旱植物外，再也見
不到什麼值得注目的東西，一陣風沙吹來，將四週吹得迷霧朦朧，有
如身墮五里沙霧，只見東邊不遠處有個村莊，令人心安。
LONG
);

  set("exits", ([
  "east" : __DIR__"room24",
]));
  set("no_clean_up", 0);
  set("outdoors", "land");
  setup();
  replace_program(ROOM);
}
