inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"west"      : __DIR__"room60",
"north"     : __DIR__"room51",
"southwest" : __DIR__"room72",
]));
  setup();
}
