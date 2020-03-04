inherit ROOM;
void create()
{
	set("short", "�y�i��U");
	set("long", @LONG
�y�y�i��z�U�A���y����I�����S���A�`���G�Q�V�B�A�w�񩳧�
�A�����O������S�U���A���@�K�ª��`�}�A���`�}�f�A�y����x�A�x
���Q�V�A��l�O�L�a�A���U�票�ۡA�]�ȶȤ@��L�ܡC�����B����B
�Z��B�����A�ʪ���̬ҨI�I
LONG
	);
	set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
    "up" : __DIR__"l",
  "east" : __DIR__"swirl",
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
      me->receive_damage("hp",random(10)+10);
      me->move(__DIR__"swirl");
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
      fish->move(__DIR__"valley");
      me->set_temp("fish",i+1);
    }
}
