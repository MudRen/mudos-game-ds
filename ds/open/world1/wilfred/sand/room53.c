inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"west"      : __DIR__"room54",
"northeast" : __DIR__"room72",
]));
  setup();
}
