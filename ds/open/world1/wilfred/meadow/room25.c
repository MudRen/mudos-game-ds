inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room26",
"west"      : __DIR__"room24",
"south"     : __DIR__"room18",
"north"    : __DIR__"room30",
]));
}
