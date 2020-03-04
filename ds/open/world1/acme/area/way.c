inherit ROOM;
void create()
{
	set("short", "���D");
	set("long", @LONG
�o�����D�U���ӷ����A���դ]�w�C�F�\�h�A�����ʵy�t���H�L�k
���a�Y�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"swirl2",
  "east" : __DIR__"way2",
]));

	setup();
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
      fish->move(__DIR__"way");
      me->set_temp("fish",i+1);
    }
}
