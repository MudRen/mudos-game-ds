inherit ROOM;
void create()
{
  set ("short", "�Y�s����");
  set ("long", @LONG
�A���}���F�D�A�Ө�t�@���j���e�A�|�g���O���j�L��A��F�o
�̡A�A���_���ƨ������K�O�Y�s���F�C
LONG
);

  set("exits", ([
  "north" : __DIR__"room45",
  "south" : __DIR__"room43",
]));
  set("objects",([
  __DIR__"npc/npc4" : 4,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
