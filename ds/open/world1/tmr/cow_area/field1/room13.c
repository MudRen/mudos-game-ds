inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room14",
"west"      : __DIR__"room12",
"south"     : __DIR__"room6",
"north"    : __DIR__"room20",
]));
}
