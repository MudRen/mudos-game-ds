inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room53",
"northwest" : __DIR__"room73",
"north"     : __DIR__"room62",
]));
  setup();
}
