inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room7",
// "west"      : __DIR__"room2",
"north"    : __DIR__"room13",
]));
}
