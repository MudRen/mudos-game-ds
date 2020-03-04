inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�A�o�{�Q�ݵ۪����u���G�Ӧۦ��a�A�i�O�o�S�o�{�����ܼv�A�o��
�u���@�ʰѤѪ��j�Ѿ��A������F�����ʤj�A�i��n�T�|�ӤH�i�}��
�~���_�ӡA�Pı���ӬO�ܱy�[�����v�F�C
LONG
        );
        set("exits", ([
  "southwest" : __DIR__"t19",]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "�j�Ѿ��" : "�@�ʫD�`���j�����A�W���K���Z�K�ݤ��M���A�]�\\�i�H�k��(climb)�ݬݡH\n",
            ]));   
        setup();
}


void init()
{
  add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "�j�Ѿ��") return notify_fail("�A�n�k������F�� ?\n");
  if(me->is_busy())  return notify_fail("�A���b��\n");  
  message_vision("$N�a�����j�Ѿ��@�D",me);
  me->start_busy(1);
  if(me->query_dex()<50)
  message_vision("�A�i�O�ʧ@���F�Ӧӱ��F�U��\n",me);
  else {
  message_vision("�A$N�F�������V�ӤW\n",me);    
  me->move(__DIR__"stn1");
  tell_room(environment(me), "���M�U���@�}�n�T�A"+me->name()+"���۪K�F���F�W�ӡI\n", ({ me }));
  }
  return 1;
}










