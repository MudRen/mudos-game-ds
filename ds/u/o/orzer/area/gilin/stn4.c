inherit ROOM;
void create()
{
        set("short","�j��W");
        set("long",@LONG
�A�Ө�F�j�쪺�t�@�q���K�A�o�̤�_���n�󰪤F�A���A�߸̭��]�P
ı���ӽ��A���L�V���e�i�ͪ��̤]�N��[�������A���G�b�u�@�ۤ���F��
�@��A�γ\��o�ʾ�W���_�S���n�����C
LONG
        );
        set("exits", ([
  "east" : __DIR__"stn5",
]));
        set("no_clean_up", 0);
        set("light",0);
        set("item_desc", ([
            "�K�F" : "�j��W���䤤�@�q���K�A�b�����B�y�w�B�A�]�\\�i�H���U�h(jump down)�ݬݡH\n",
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
  if(!arg || arg != "down") return notify_fail("�A�n������� ?\n");
  if(me->is_busy())  return notify_fail("�A���b��\n");  
  message_vision("$N�ĤO���U�@��",me);
  me->start_busy(1);
  if(me->query_skill("dodge",1)<65){
   message_vision("�A�i�O�@�ɯ���í����U���F�U�h\n",me);
   me->receive_wound("left_leg",5+random(20));
   me->receive_wound("right_leg",5+random(20));
   me->receive_wound("left_arm",5+random(20));
   me->receive_wound("right_arm",5+random(20));
   me->receive_wound("head",5+random(20));
   me->receive_wound("body",5+random(20));             
   me->receive_damage("hp",me->query("hp")*1/4);
   me->move(__DIR__"t18.c");
   tell_room(environment(me), "�y���@�n�A"+me->name()+"�q�j�챼�F�U�ӡA�ݨӨ��ˤ��L�I\n", ({ me }));
  }    
  else {
  message_vision("�A$Níí�����W�F�K�F�W\n",me);    
  me->move(__DIR__"stn3");
  tell_room(environment(me), "���M����@�}�n�T�A"+me->name()+"�q�W�����K�F�u�������F�U�ӡI\n", ({ me }));
  }
  return 1;
}











