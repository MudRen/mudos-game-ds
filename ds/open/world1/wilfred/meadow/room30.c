inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room31",
"west"      : __DIR__"room29",
"south"     : __DIR__"room25",
"north"    : __DIR__"room35",
]));
}
