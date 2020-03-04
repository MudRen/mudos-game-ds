inherit ROOM;
void create()
{
  set ("short", "十字路口");
  set ("long", @LONG
你來到一個小小的十字路口上，東邊和西邊好像住著幾戶人家，而南
邊再過去便偏離了黃沙邊，走到黃沙平原中了，北邊有座丘陵。
LONG
);

  set("exits", ([
  "east" : __DIR__"room19",
  "west" : __DIR__"room16",
  "north" : __DIR__"room13",
  "south" : __DIR__"room24",
]));
  set("objects",([
  __DIR__"npc/npc14" : 4,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
