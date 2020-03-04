// Room: /u/a/alickyuen/area/inn4.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ST�DSOFT�ISleepingroom");
	set("long", @LONG
�o�̬O�o�����]���ȩСA�A�q���f�ݥX�h�A�ݨ�@�����R����A�o��
�٦��@�i�ɡ]����^�A�A�i�H�Φb�o�i�ɤW�𮧡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"inn2",
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
        add_action("do_sleep","sleep");
}

int do_sleep()
{
        object me;
        me=this_player();
        if( me->query_temp("pushpass") <= 0 )
        {
                write("�A�ү�𮧪����Ƥw�Υ��F�I\n");
                return 1;
        }
        if(me->query_temp("sleeping"))
        {
                write("�A���b��ı�C\n");
                return 1;
        }
        message_vision(HIW "$N�@�U����ɤW�A�N�a�Y�j�Ρ�\n\n" NOR, me);
       // tell_object(me, HIW "�����@���A�H�Y�N�b���n�A�����ɤW�εۤF.....\n\n" NOR );
       // tell_object(me, HIB "�C��C����C������C�C���C\n\n\n" NOR );

        me->disable_player_cmds("�A���b��ı�C\n");
        me->set_temp("sleeping","�A���b��ı�C");
        me->start_busy(10);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
 //       tell_object(me,HIG"�A�����i�J�F�ڶm�A����F�A�h���H�[���p���Y��\n"NOR);
        me->receive_heal("hp",me->query_con()*4);
        me->receive_heal("ap",me->query_con()*2);
        me->receive_heal("mp",me->query_int()*3);
        return;
}
void sleep2(object me)
{
        if(!me) return;
  //      tell_object(me,HIB"�A����]���Q�F�A���e�@�¡A�I�I���ΤF�U�h���C�C�C\n"NOR);
        me->receive_heal("hp",me->query_con()*5);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision(HIW"$N��M�Q���䪺�p�x���n���F�A���F�L�ӡC\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("sleeping");
me->delete_temp("pushpass");
        me->receive_heal("hp",me->query_con()*7);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*3);
//        me->add_temp("sleep",-1);
        return;
}