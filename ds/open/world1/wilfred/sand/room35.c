inherit ROOM;
void create()
{
  set ("short", "���F��");
  set ("long", @LONG
�g�~�֤몺���F�A��X�F�o�����F�C���a�A�C���W�o�󤣥͡A��
�~�����A��a�H�٤����y���F���z�A���C�����s���½Y�s���P���F�D
���n�D�C
LONG
);
  set("exits", ([
  "west" : __DIR__"room36",
  "south" : __DIR__"room34",
]));
  set("objects",([
  __DIR__"npc/npc1" : 2,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
