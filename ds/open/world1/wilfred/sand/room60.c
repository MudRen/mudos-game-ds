inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room52",
"north"     : __DIR__"room59",
"southwest" : __DIR__"room61",
]));
  setup();
}
