inherit ROOM;
void create()
{
        set("short", "�s�y");
        set("long",@LONG
�o�̬O������s�y���a��A�D���즹���M���ǭׯ�L�A�]�\����
�H�~��󦹡A�D����������C�G�A�A�ݨӸӬO���H�M�z�L������A�ϧA
��[�T�H�o�̦��H��A�ӪF�����������G���Ӥp�_�A�_�䦳�@�������b
�s�y�A��n�h�O���s�U�C
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"mu13",
  "southwest" : __DIR__"mu11",
]));
set("item_desc",([
        "����":"�@���p�p�����_�A�ݨӥi�H�e�H�j�j�p(squeeze)�L�C\n",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

void init()
{
  add_action("do_squeeze","squeeze");
}

int do_squeeze(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "����") return notify_fail("�A�n�p�i���� ?\n");
  message_vision("$N�Y�ۨ��l�w�O�p�i�F���ؤ�\n",me);
  me->start_busy(1);
  me->move(__DIR__"mu14");
  return 1;
}





