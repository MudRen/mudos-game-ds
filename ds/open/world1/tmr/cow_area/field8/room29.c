inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room30",
"west"      : __DIR__"room28",
"south"     : __DIR__"room24",
]));
}
