// taiyi2.c
// Java Oct.10 1998
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "�ӤA��");
        set("long", @LONG
�A���b����̡A�uı�o����B�D�z���C�����|�P���p���C�A����
�Ѫi���y�A�s�����v�A�����M�H�C�o�̭�ӬO�ӤA�����F���A�Ӳ֪�
�ܡA�A�i�H��(climb) �W���C������h�A���䪺�s�p�������G���@��
�j�}�C�Q���Q�C(swim)�L�h�ݡH
LONG
        );
        set("outdoors", "zhongnan");
	set("coor/x", -3190);
	set("coor/y", 180);
	set("coor/z", 40);
	setup();
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_swim", "swim");
}
int do_climb(string arg)
{
        object me = this_player(); 
        int c_exp;
        c_exp = me->query("combat_exp");
        if( !arg || arg != "up")
        {
                write("���Ӥ�V�S�k���C\n");
                return 1;
        }

        message_vision("$N�b�ӤA���������W���F�W�h�C\n", me);
        me->move("/d/quanzhen/taiyi1");
        message_vision("$N�q�ӤA�������F�W�h�C\n", me);
        return 1;
}
int do_swim()
{
        int c_exp,c_skill;
        object me = this_player();

        c_exp=me->query("combat_exp");
        c_skill=me->query_skill("jinyan-gong",1);
	if ( me->query("qi") < 10 )
		me->unconcious();
	else
	{
        	me->receive_damage("qi",10);
        	if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill < 51))
			me->improve_skill("jinyan-gong", (int)me->query_skill("jinyan-gong", 1));
	        message_vision("$N�b�ӤA�������F�E���A�ΤO�C�F�_�ӡC\n", me);
	}
        return 1;
}
