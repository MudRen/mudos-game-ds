inherit ROOM;
void create()
{
	set("short", "�`�}��");
	set("long", @LONG
�o�O�y�i��U�㦳�j�O�l�O���`�}���A�A�������Y�l�h�A�o���I
�Q��k��k�X�h�A�_�h�N���ũ󦹡C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"valley",
  "east" : __DIR__"swirl2",
]));
	setup();
}
void init()
{
    object me;
    me=this_player();
    call_out("start",2,this_player() );
    me->start_busy(2);
}
int start()
{
    int i;
    object me;
    me=this_player();
    i=me->query_temp("swirl");
    if(me->query_skill("swim")<40)
    {
      message_vision("$N�Q�j�O���x���ҧl�A�಴��$N�w�L�v�L�ܡC\n",me);
      me->receive_damage("hp",random(10)+20);
      if(i>4)
      {
        me->move(__DIR__"swirl2");
        me->delete_temp("swirl");
      }
      else {
        me->set_temp("swirl",i+1);
        me->move(__DIR__"swirl");
      }
    }
}
int room_effect(object me)
{
        if( !userp(me) ) return notify_fail("�u�����a�~�|�Q�����@�C....:P\n");
        switch(random(4))
        {
                
         case 0:        message_vision("$N�Ө�����o�j�O�������A$N�uı�o���Y�@���A�R�X�F�@�f�A��C\n",me);
                        me->receive_damage("hp",random(20)+50);
                        call_out("fish",4,me);
                        return 1;
         case 1:        message_vision("$N�]�x��L�[�A�@�ɼ�����A�ܤF�@�j�f�����C\n",me);
                        me->receive_damage("hp",random(20)+30);
                        return 1;
         default:       message_vision("$N�@�Ӥ��p�ߧl�Q�����F�A�S�X�F�h�W�����C\n",me);
                        me->receive_damage("hp",random(20)+10);
                        return 1;
        }
}
int fish()
{
    int i;
    object me,fish;
    me=this_player();
    i=me->query_temp("fish");
    if(i<10)
    {
      message_vision("�A�ݨ��b�`�}����X�F�@�s���H���A�i��O����{���A�~��ӳo�̪��a�C\n",me);
      fish=new(__DIR__"npc/fish");
      fish->move(__DIR__"swirl");
      me->set_temp("fish",i+1);
    }
}
