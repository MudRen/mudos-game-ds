inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room8",
"west"      : __DIR__"room6",
"north"    : __DIR__"room14",
]));
}
