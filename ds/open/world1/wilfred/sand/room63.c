inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"north"     : __DIR__"room64",
"southeast" : __DIR__"room62",
]));
  setup();
}
