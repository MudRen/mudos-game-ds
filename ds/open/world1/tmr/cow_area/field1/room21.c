inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room22",
"west"      : __DIR__"room20",
"south"     : __DIR__"room14",
]));
}

