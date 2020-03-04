#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���F��");
	set("long", @LONG
�A���B�b���F�����W�A�|�P�ɬO�����F�A�A�oı���l�C�C�����U�Y�J
���F�����A�K��������b�ԵۧA�A�A�ߤ����T���Q�_�O�_��e�ұ����H��
�޻�ӯ��R�F�A�A����ݰʵۡA�o�O���H�ӷX�A�٬O�֧����}���B���n�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hills",
  "south" : __DIR__"hills2",
  "southeast" : __DIR__"senwu1" ,
]));
	set("no_clean_up", 0);
  set("no_recall",1);
  set("no_goto",1);
    set("outdoors","land");

	setup();
}
void init()
{
  object me;
  me=this_player();      
  add_action("do_jump","jump");
  me->start_busy(2);
  me->set_temp("quicksand",1);
  me->set_temp("time",6);
  message_vision(HIR "\n���M���A$N�����}�����i�F�y�F����....\n" NOR,me);
  call_out("down_msg",1,me);
}
int do_jump(string arg)
{
        object me;
        me=this_player();
        if(!me->query_temp("quicksand")) return 0;
        if(arg!="up") return notify_fail("�A���b�U�����A�٬O���W(up)���o�n�a..\n");
        if(me->query_skill("dodge") > 15 )
        {
          message_vision(HIW"�u��$N�ĤO���ä�A�V�O�o�n���X�o�i�Ȫ��y�F�C\n"NOR,me);
          me->set_temp("jumpok",1);
        }
        else
        {  
          message_vision(HIW"�u��$N�ĤO���ä�A�V�O�o�n���X�o�i�Ȫ��y�F�C\n"NOR,me);
          message_vision(HIC"$N�Ϻɴ����ѼơA�o�L�k�ò�A�u�O�V���V�`�C\n"NOR,me);
        }
     return 1;
}

int down_msg(object me)
{
        int i;
        if(!me) return 1;
        me->start_busy(3);
        i=me->query_temp("time");
        me->set_temp("time",i-2);
        if(!me->query_temp("jumpok") )
        {
                tell_object(me,HIR "�A�oı�A�����l�C�C�����U�Y�C\n"NOR);

                if (i>=0)
                        call_out("down_msg",3,me);
                else
                {
                 me->move(__DIR__"howe");
        message_vision(HIW "$N�u�z�v���@�n�A�����a�ѤW������F��U���}�ޡC\n"NOR,me);
                me->delete_temp("jumpok");
                me->delete_temp("quicksand");
                me->delete_temp("time");
               }

        }
        else {
tell_object(me,HIC "�A�ϥX�`�p�����\\�A�������s���աA�ĤO�����W�@�D�A�q�y�F�̸��F�X�ӡC....\n"NOR);
                me->delete_temp("jumpok");
                me->delete_temp("quicksand");
                me->delete_temp("time");
        }
        return 1;
}
