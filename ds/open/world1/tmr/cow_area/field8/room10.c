inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room11",
"west"      : __DIR__"room9",
"south"     : __DIR__"room4",
"north"    : __DIR__"room17",
]));
  set("chance",50);
  set("mob_amount",15);
  set("mob_object",({
  __DIR__"npc/npc1",
}));
}
