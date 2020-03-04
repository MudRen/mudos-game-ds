#include <ansi.h>
inherit MOBROOM;
void create()
{
  set ("short", HIG"竹園"NOR);
  set ("long", @LONG
這裡種著許多青竹，蒼翠勁拔，顯然是有人特意加以照料的，竹
子分佈疏密有致，微風吹來，竹葉沙沙作響，彷如世外桃源。
LONG
);

  set("exits", ([
  "west" : __DIR__"room6",
]));
        set("chance",75); // 有人掛robot ,100->75
        set("mob_amount",5);
        set("mob_object",({
  __DIR__"npc/npc5",
  __DIR__"npc/npc6",
}) );
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
}

