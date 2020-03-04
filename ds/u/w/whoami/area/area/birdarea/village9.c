#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"�y����"HIW+BLK"��"HIW"�p�̫F�G��"NOR);
        set("long", @LONG 
�A�{�b���b�p�̫F���ӤW, �b�o�̥u���X�i�ɩM��i����, �A�i
�H��ɤW�h��ı(sleep)�C
LONG
        );
        set("exits", ([
  "down" : __DIR__"village8.c",
]));
        set("light", 1);
        set("no_fight", 1);
        set("no_cast", 1);
        set("no_exert", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
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
        if( me->query_temp("sleep") <= 0 )
        {
                write("�A�ү�𮧪����Ƥw�Υ��F�I\n");
                return 1;
        }
        if(me->query_temp("is_busy/sleeping"))
        {
                write("�A���b��ı�C\n");
                return 1;
        }
        message_vision(HIG "$N�|�F�|�����A���֦��G�Q�O���ε���W�F�A�Ԥ����ɤW�@����\n\n" NOR, me);
        tell_object(me, HIG "�����@���A�H�Y�N�b���n�A�����ɤW�εۤF.....\n\n" NOR );
        tell_object(me, HIB "�C��C����C������C�C���C\n\n\n" NOR );
 me->disable_player_cmds("�A���b��ı�C\n");
        me->set_temp("is_busy/sleeping","�A���b��ı�C");
        me->start_busy(10);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
        tell_object(me,HIY"�A�����i�J�F�ڶm�A����F�A�߷R���֥d�C��:>\n"NOR);
        me->receive_heal("hp",me->query_con()*4);
        me->receive_heal("ap",me->query_con()*2);
        me->receive_heal("mp",me->query_int()*3);
        return;
}

void sleep2(object me)
{
        if(!me) return;
        tell_object(me,HIB"�A����]���Q�F�A���e�@�¡A�I�I���ΤF�U�h���C�C�C\n"NOR);
 me->receive_heal("hp",me->query_con()*5);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision(HIG"$N��M�Q���䪺�p�G���V���n���n���A�|�F�|�������F�L�ӡC\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/sleeping");
        me->receive_heal("hp",me->query_con()*7);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*3);
        me->add_temp("sleep",-1);
        return;
}

