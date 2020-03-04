// Room: /u/a/acme/test/swirl2.c

inherit ROOM;

void create()
{
	set("short", "�`�}��");
	set("long", @LONG
�o�O�y�i��U�㦳�j�O�l�O���`�}���A�A�������Y�l�h�A�o���I
�Q��k��k�X�h�A�_�h�N���ũ󦹡C�A�o�{���B���a�A�o���a���s�A
�ȤT�V�����ؼe���@�����_�C�ѥ͸U���A�y�Ƥ��_�A���B�i���@�G�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"swirl",
  "east" : __DIR__"way",
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
          if(arg != "���a")
            return notify_fail("�A�n�k������H\n");
          else {
              message_vision("$N�ĤO�������a�W���h�C\n",me);
              me->move(__DIR__"stone2");
              return 1;
          }
}
int room_effect(object me)
{
        if( wizardp(me) || !userp(me) ) return notify_fail("�u�����a�~�|�Q�����@�C....:P\n");
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
      fish->move(__DIR__"swirl2");
      me->set_temp("fish",i+1);
    }
}
