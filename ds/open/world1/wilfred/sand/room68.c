inherit ROOM;
void create()
{
  set ("short", "少陽");
  set ("long", @LONG

石壁上刻著：
四象之象，若以天己為甚，變化見矣，若以地動為行，陰陽相易矣。

LONG
);
  set("exits", ([
  "north" : __DIR__"room69",
  "northeast" : __DIR__"room66",
  "southeast" : __DIR__"room61",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
