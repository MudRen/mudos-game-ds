inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room20",
"west"      : __DIR__"room18",
"south"     : __DIR__"room12",
"north"    : __DIR__"room26",
]));
}
