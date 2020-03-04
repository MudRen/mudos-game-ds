inherit ROOM;
void create()
{
  set ("short", "�s�^�W");
  set ("long", @LONG
�n���e�����W�o�s�A�A�q�s�W���U��A�~�o�{�o�O�Ѥ@���j�p
���������Y�Ұ�_���s�C�A�O�H�Ǵe���O�A��M�o�O�ѤH�u�令���A
���S���֦��o����@�A�b�p��������a��F�o�y�s�C�H�q�o�̥i�H��
���Ӷ��F��b�s���F�䪽��Q���B�C
LONG
);

  set("exits", ([
  "west" : __DIR__"room31",
  "south" : __DIR__"room33",
  "eastdown" : __DIR__"room93",
]));
  set("objects",([
  __DIR__"npc/npc11" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
}

int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("stone beast", this_object())) && dir == "south" )
  {
    message_vision("�����@�n�A$n���M�ʤF�_�ӡA"+"�u���e�H���֪��t�׾צb$N���e�A����$N�L�h�C\n",me , guard);
	return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
