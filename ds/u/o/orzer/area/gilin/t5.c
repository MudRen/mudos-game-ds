inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�o�̤w�g�O�D�`���t�F�A�ݨӦ��G�w�g�S�����i�H�e�i�F�A�ݨӤ]
�\�n�ਭ���^�h�F�A�i�O���䪺���O�o�Q���ǲ��A�Pı���Ǥ��ӹ�l��
�ˤl�A�Ӧ��a���\�h���_�S�D��A�����q�譱�ǨӡC
LONG
        );
        set("exits", ([
  "east" : __DIR__"t4",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "���O" : "���������ê����O�A�ݨӫ���������F��A�]�\\�i�H���}(push)�ݬݡH\n",
            ]));   
        setup();
}

void init()
{
  add_action("do_push","push");
}

int do_push(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "���O") return notify_fail("�A�n���}����F�� ?\n");
  if(me->is_busy())  return notify_fail("�A���b��\n");  
  message_vision("$N����ΤO�Q����O���}",me);
  me->start_busy(1);
  if(me->query_str()<50)
  message_vision("�A�i�O���O�o�@�L���R\n",me);
  else {
  message_vision("�A���G$N�ΤO�Ӥj���i�F���O��\n",me);    
  me->move(__DIR__"sgn1");
  tell_room(environment(me), "�u�����O�@�}�̰ʡA"+me->name()+"��M�^�F�i�ӡI\n", ({ me }));
  }
  return 1;
}








