inherit ROOM;
void create()
{
  set ("short", "墓道");
  set ("long", @LONG

      你繼續摸索著前進，出口就在不遠的前方。

LONG
);
  set("exits", ([
  "east" : __DIR__"room78",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
