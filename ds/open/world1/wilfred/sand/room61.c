inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"northeast" : __DIR__"room60",
"west"      : __DIR__"room62",
"northwest" : __DIR__"room68",
]));
  setup();
}
