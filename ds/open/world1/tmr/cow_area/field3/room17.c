inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room18",
"west"      : __DIR__"room16",
"south"     : __DIR__"room10",
"north"    : __DIR__"room24",
]));
}
