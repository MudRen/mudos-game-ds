inherit ROOM;
void create()
{
  set ("short", "���F�D");
  set ("long", @LONG
�o�̬O�s�j�����F���줤�A�ߤ@���@����D�A�u���D�W���F�u�u
�A�j���j�_�K�p�@�D�D������ɭ��A���W�o�󤣥͡A����Ƭ���D�A
���B�����C���a��a�H�٤����y���F���z�A�Ӷ��p�n�q�¤ѫe���Y�s
���A�@�w�n��g�o�D���A�ҥH���F�D�]���y�s�D�z���O�١C
LONG
);

  set("exits", ([
  "west" : __DIR__"room4",
  "south" : __DIR__"room2",
]));
  set("objects",([
  __DIR__"npc/npc17" : 1,
  __DIR__"npc/npc18" : 1,
  __DIR__"npc/npc19" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
