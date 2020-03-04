inherit ROOM;
void create()
{
        set("short","�Ŧa");
        set("long",@LONG
�o�O�j��L�����@���Ŧa�A�a���Q�����Z�A�ݨӤ����O�۵M�Φ���
�ˤl�A�Pı���G�O���H��N�y�����A�i�O�n�Q�b�@�K���L���y�X�Ŧa�A
�ä��O�@��e�����Ʊ��A�P��]�S���u��A�O�H�Q���ôb�A���a������
�Ӥ@�}�}�x���A����O�@���a�V�C
LONG
        );

        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "�a�V" : "�Ŧa�������a�V�A���a�����@�q�Z���A�p�G���۫H�]�\\�i�H���U�h(jump down)�ݬݡH\n",
            ]));
        setup();
        replace_program(ROOM);
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
  message_vision("$N�W�l���a�V�U�@��",me);
  me->start_busy(1);
  if(me->query_skill("dodge",1)<75){
   message_vision("�A�i�O���a�ɤ@�ӯ���í�L�ˤF\n",me);
   me->receive_wound("left_leg",5+random(20));
   me->receive_wound("right_leg",5+random(20));
   me->receive_wound("left_arm",5+random(20));
   me->receive_wound("right_arm",5+random(20));
   me->receive_wound("head",5+random(20));
   me->receive_wound("body",5+random(20));             
   me->receive_damage("hp",me->query("hp")*1/4);
   me->move(__DIR__"t19-1.c");
   tell_room(environment(me), "�y���@�n�A"+me->name()+"�q�a�V���F�U�ӡA�ݨӨ��F�I�L�ˡI\n", ({ me }));
 }    
  else {
  message_vision("�A$N�W��������a���W\n",me);    
  me->move(__DIR__"s19-1");
  tell_room(environment(me), "���M�@�}���n�A"+me->name()+"�����B�����q�a�V�W�����F�U�ӡI\n", ({ me }));
  }
  return 1;
}





