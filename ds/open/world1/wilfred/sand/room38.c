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
  "west" : __DIR__"room39",
  "north" : __DIR__"room36",
]));
  set("no_clean_up", 0);
  set("outdoors", "land");
  setup();
  replace_program(ROOM);
}
