inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room27",
"west"      : __DIR__"room25",
"south"     : __DIR__"room19",
"north"    : __DIR__"room31",
]));
}
