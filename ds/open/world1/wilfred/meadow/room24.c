inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room25",
"west"      : __DIR__"room23",
"south"     : __DIR__"room17",
"north"    : __DIR__"room29",
]));
}
