inherit ROOM;
void create()
{
  set ("short", "���v");
  set ("long", @LONG
�o�O���F�����v�A�G�p����s�ЫΡA���~�����F�ϥ��C���
�f�H�A�Фl�b�j�󤧮ǡA�����@��C�A�~�������Ӽ����A�O�Ӧ��H��
�����p��C
LONG
);

  set("exits", ([
  "east" : __DIR__"room16",
]));
  set("objects",([
  __DIR__"npc/npc26" : 1,
]));
  set("no_clean_up", 0);
  set("light",1);
  setup();
  replace_program(ROOM);
}
