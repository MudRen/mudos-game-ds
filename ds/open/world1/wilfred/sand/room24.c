inherit ROOM;
void create()
{
  set ("short", "���F��~");
  set ("long", @LONG
�o�̬O���F��~������A�D�W���F�u�u�A�j���j�_�K�p�@�D�D������
�ɭ��A���W�o�󤣥͡A����Ƭ���D�A���B�A���n�K�w�����F���F�D
���d��A����F���줤�F�A�ӥ_��h�O���F��C
LONG
);

  set("exits", ([
  "north" : __DIR__"room15",
  "south" : __DIR__"room25",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

