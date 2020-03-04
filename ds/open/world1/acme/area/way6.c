inherit ROOM;
void create()
{
	set("short", "���D�X�f");
	set("long", @LONG
�ש��F���D�X�f�F�A�b�X�f���e�観�ӥ۱V�A���۱V�ư��A�G
�۱V�W�Y�S�����F�A���n���W�h�O�Q���������ơC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"way5",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "�۱V" : "�o�O�@�Ӭ۷�~�k���۱V�A�n��(climb)�W�h�ᬰ�x���C\n",
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
          if(arg != "�۱V")
            return notify_fail("�A�n�k������H\n");
          else {
            if(me->query("str")<9) 
            {
              tell_object(me,"�A���O�q�����L�k�k���W�h�C\n");
            }
            else {
              message_vision("$N�ĤO�����۱V�W���h�C\n",me);
              me->move(__DIR__"stone3");
            }
            return 1;
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
      fish->move(__DIR__"way6");
      me->set_temp("fish",i+1);
    }
}
