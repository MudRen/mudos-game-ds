inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�o�̤w�g�Z����˪L���̪F���A�H���`�O�p�v�H�Ϊ����ۡA�F��
�s�����ۤ@�D�p�s��A����ݰ_���٤����A�Pı�i�H�~���y�M���@�U�A
�i�O�q�s��A���G�]���@�ѲD���j�ӡC
LONG
        );
        set("exits", ([
  "west" : __DIR__"t16",
   ]));
        set("item_desc", ([
            "�s��" : "�@�D�s���d�U���u���A���y�ݨӤ��p�A�̭����G���ө��}�H\n",
            "���}" : "�s���W���@�Ӥp�}�A�Q�s��B�����Z���o�{�A�]�\\�i�H��V(into)�H\n",
         ]));   
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}


void init()
{
 add_action("do_into","into");
}

int do_into(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "���}") return notify_fail("�A�n��V����F�� ?\n");
  if(me->is_busy())  return notify_fail("�A���b��\n");  
  message_vision("$N�V�O�������}�i�J",me);
  me->start_busy(1);
  if(me->query_con()<50)
  message_vision("�A�i�O��O�����Q���y�R�F�X��\n",me);
  else {
  message_vision("�A$N�L�����y��F�i�h\n",me);    
  me->move(__DIR__"swn1");
  tell_room(environment(me), "�F���@�n�A"+me->name()+"�q���}�~���F�i�ӡI\n", ({ me }));
  }
  return 1;
}








