inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"west"      : __DIR__"room14",
"south"     : __DIR__"room8",
"north"    : __DIR__"room22",
]));
}
