inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room17",
"south"     : __DIR__"room9",
"north"    : __DIR__"room23",
]));
}
