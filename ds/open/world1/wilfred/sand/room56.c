inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room64",
"northeast" : __DIR__"room70",
"south"     : __DIR__"room55",
]));
  setup();
}
