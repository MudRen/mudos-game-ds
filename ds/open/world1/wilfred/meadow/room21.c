inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room22",
"west"      : __DIR__"room20",
"south"     : __DIR__"room14",
"north"    : __DIR__"room33",
]));
}

int valid_leave(object me, string dir)
{
  if( dir == "north" && !userp(me) && me->query("id") != "ghost") return notify_fail("���̥u�����a�~��i�h�C\n");
  return ::valid_leave(me, dir);
}
