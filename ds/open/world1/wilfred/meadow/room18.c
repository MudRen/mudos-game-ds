inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room19",
"west"      : __DIR__"room17",
"south"     : __DIR__"room11",
"north"    : __DIR__"room25",
]));
}
