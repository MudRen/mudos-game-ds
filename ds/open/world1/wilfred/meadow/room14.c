inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room15",
"west"      : __DIR__"room13",
"south"     : __DIR__"room7",
"north"    : __DIR__"room21",
]));
}
