inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room21",
"west"      : __DIR__"room19",
"south"     : __DIR__"room13",
"north"    : __DIR__"room27",
]));
}
