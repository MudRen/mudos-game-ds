inherit ROOM;
void create()
{
  set("short", "牯牛草原南方");
  set("long", @LONG
行經極為漫長的路程後，你來到了牯牛草原的南邊，從
這裡往北走到草原的另一邊是漠北地區，而西邊是磐龍城，
南邊是孟村。
LONG
);
  set("exits", ([
// "east"      : __DIR__"room6",
// "west"      : __DIR__"room5",
"out"     : __DIR__"room1",
"north"    : __DIR__"room12",
]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
}

int valid_leave(object me, string dir)
{
  if( dir == "out" && !userp(me) ) return notify_fail("那裡只有玩家才能進去。\n");
  return ::valid_leave(me, dir);
}
