inherit ROOM;
void create()
{
  set ("short", "街道");
  set ("long", @LONG
鎮裡規模極小，只有一條大街，住戶也極少，街上黃沙滾滾，景
象一片淒涼，偶爾有外來客在此走動。
LONG
);

  set("exits", ([
  "west" : __DIR__"room19",
  "east" : __DIR__"room22",
  "south" : __DIR__"room23",
  "north" : __DIR__"room21",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
