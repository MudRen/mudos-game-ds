inherit ROOM;
void create()
{
  set ("short", "玄武門");
  set ("long", @LONG

石壁上刻著：西主玄武，屬白金，悅，為澤。
LONG
);
  set("exits", ([
  "out"       : __DIR__"room49",
  "northwest" : __DIR__"room55",
  "southeast" : __DIR__"room54",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
