inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room13",
"west"      : __DIR__"room11",
"north"    : __DIR__"room19",
]));
}
