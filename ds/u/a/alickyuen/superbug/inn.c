// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�𮧶�");
	set("long", @LONG
�o�̬O�o�����]���𮧶��A�A�q���f�ݥX�h�A�ݨ�@�Ǵc�H�����ҡA
�o���٦��@�ǴȤl�]�������^�A�A�i�H���b�W���𮧡]��������^�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"a-17",
]));
set("light",1);
set("no_exert",1);
set("no_cast",1);
set("no_fight",1);
set("no_kill",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_rest","rest");
}

int do_rest()
{
        object me;
        me=this_player();
        if( me->query_temp("sleep") <= 0 )
        {
                write("�A�ү�𮧪����Ƥw�Υ��F�I\n");
                return 1;
        }
        if(me->query_temp("sleeping"))
        {
                write("�A���b��ı�C\n");
                return 1;
        }
        message_vision("$N���b�Ȥl�W�A������ı���N�εۤF��\n\n", me);
        me->disable_player_cmds("�A���b��ı�C\n");
        me->set_temp("sleeping","�A���b��ı�C");
        me->start_busy(6);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
        me->receive_heal("hp",me->query_con()*3);
        me->receive_heal("ap",me->query_con()*2);
        me->receive_heal("mp",me->query_int()*2);
        return;
}
void sleep2(object me)
{
        if(!me) return;
        me->receive_heal("hp",me->query_con()*3);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision("$N��M�Q���䪺�p�x���n���F�A���F�L�ӡC\n",me);
        me->enable_player_cmds();
        me->delete_temp("sleeping");
        me->receive_heal("hp",me->query_con()*3);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*2);
      me->add_temp("sleep",-1);
        return;
}
