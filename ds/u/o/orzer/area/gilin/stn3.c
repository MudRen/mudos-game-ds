inherit ROOM;
void create()
{
        set("short","�j��W");
        set("long",@LONG
�A�b�j��W�樫�ۡA���M�o�{�e�����G�S���q���F�A�J�Ӥ@�@��ӧA��
�b���L�u�O�䤤�@�Ӥ��K�}�F�A�n�Q�~�򩹥j��W�e�i�i��n�M��O�����A
�e��y���B���t�@�Ӥ��K�A�]�\�i�H���չL�h�ݬݡC
LONG
        );
        set("exits", ([
  "west" : __DIR__"stn2",
]));
        set("no_clean_up", 0);
        set("light",0);
        set("item_desc", ([
            "���K" : "�j��W���䤤�@�q���K�A�b�����B�y���B�A�]�\\�i�H���W�h(jump up)�ݬݡH\n",
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
  if(!arg || arg != "up") return notify_fail("�A�n������� ?\n");
  if(me->is_busy())  return notify_fail("�A���b��\n");  
  message_vision("$N�o�O���K�F�@��",me);
  me->start_busy(1);
  if(me->query_skill("dodge",1)<60){
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
  me->move(__DIR__"stn4");
  tell_room(environment(me), "���M�U���@�}�n�T�A"+me->name()+"��í�����q�U���K�F���F�W�ӡI\n", ({ me }));
  }
  return 1;
}












