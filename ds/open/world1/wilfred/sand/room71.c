inherit ROOM;
void create()
{
  set ("short", "白虎門");
  set ("long", @LONG

石壁上刻著：東主白虎，屬木，鼓雷，性喜動。

LONG
);
  set("exits", ([
  "out"       : __DIR__"room49",
  "northwest" : __DIR__"room50",
  "southeast" : __DIR__"room51",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
