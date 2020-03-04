inherit ROOM;
void create()
{
        set("short","���F�˪L����");
        set("long",@LONG
�A��F���F�˪L���̤����F�A�o�̪�����ܭ��A�|�P�j���@�ѪѪ�
���t�褧��A���D�o�̴N�O���Ѵ©M�e�­x�����Գ��A�q�o�˪���
���I���A�K�]�N�i�H���X��ɾԪp���G�P�A�譱�N�O�A�D�U���s�V�C
LONG
        );
        set("exits", ([
        "southwest" : __DIR__"t30",
        "southeast" : __DIR__"t39",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "�s�V" : "�@�����פ��C���a�V�A�ﭱ���G���F��A�]�\\�i�H���W�h�ݬݡH\n",
         ]));   
        setup();
}


void init()
{
 add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "�s�V") return notify_fail("�A�n���W����F�� ?\n");
  if(me->is_busy())  return notify_fail("�A���b��\n");  
  message_vision("$N�ܪ��@�n���F�_��",me);
  me->start_busy(2);
  if(random(me->query_skill("dodge",1))<65)
  message_vision("�A�i�O���\\�y�ڤ����ӷƤF�U��\n",me);
  else {
  message_vision("�A$N�p�P�����@�뻴�P�V�W�s�V\n",me);    
  me->move(__DIR__"smn1");
  tell_room(environment(me), "�@�D�H�v�{�L�A"+me->name()+"�q�s�V�U���F�W�ӡI\n", ({ me }));
  }
  return 1;
}














