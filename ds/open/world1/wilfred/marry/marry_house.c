inherit ROOM;
void create()
{
  set("short", "�p���");
  set("long", @LONG

�o�̬O���C�C�����Фl�A�o�M�����H�B�z���B�ߨơA�p���ݭn�� look wang�C

LONG
);
  set("exits", ([
  "north" : "/open/world1/tmr/area/ms1",
]));
  set("no_clean_up", 0);

  set("objects",([
__DIR__"marry_man" : 1,
]) );
  set("light",1);
  setup();
  replace_program(ROOM);
}

