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
  "north" : __DIR__"room35",
  "eastdown" : __DIR__"room8",
]));
  set("objects",([
  __DIR__"npc/npc9" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
