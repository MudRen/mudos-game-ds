inherit ROOM;
int reborn = 1;
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
  "east" : __DIR__"room32",
  "westdown" : __DIR__"room30",
]));
  set("item_desc", ([
  "���Y" : "�@���j�p���������Y�A�䤤���ǥ~�λŦ��Z���A�]�\\�i�H���(search)���L�X�Ϊ��C\n",
]));
  set("outdoors", "land");
  setup();
}

void init()
{
  add_action("do_search","search");
}

int do_search(string str)
{
  object me = this_player();
  if(str == "���Y")
  {
    if(reborn)
    {
      message_vision("$N�b�å۰襤½½���.....\n",me);
      message_vision("��M�o�{�䤤�@�����Y�~�Φ����A�]�\\�i�H�@���Z���C\n",me);
      message_vision("\n$N�o�{�@���ۤ��C\n",this_player());
      new(__DIR__"npc/wp/wp2")->move(environment(me));
      reborn = 0;
    }
    else message_vision("$N�b�å۰襤��F�S��A���G�S�o�{����i�Ϊ��F��C\n",me);
  }
  else return 0;
  return 1;
}
