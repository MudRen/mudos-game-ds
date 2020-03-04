#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ȩ�");
        set("long", @LONG
�o�O�H�B�ȴ̪��ȩСA�̭��\�F�n�X�i���H�B�ɡA�o�O���ȴ̪�
�̤j�S��A�A�i�H�䪺�������H�B�ɥh�𮧡A�ɪ��e�����|�ߤ@�i�P
�l�A�W�����|�ЧA���m�\�^��A��ꤣ�СA�j�a�]���ӷ|�a !(qk) 
LONG
        );
        set("exits", ([
  "out" : __DIR__"hotel.c",
]));
        set("light", 1);
        set("no_clean_up", 0);  
        set("no_fight", 0); 
        set("valid_startroom", 1);
        setup();
}

void init()
{
        add_action("do_qk","qk");
}

int do_qk()
{
        object me;
        me=this_player();
        if( me->query_temp("qk") <= 0 )
        {
                write("�A�𮧪����ƨS�P ~ ~�I\n");
                return 1;
        }
        if(me->query_temp("is_busy/qking"))
        {
                write("�A���b��ı�C\n");
                return 1;
        }
        message_vision(HIW "$N��F�@�i�������H�B�ɡA����W���h�𮧤F��\n\n" NOR,me);
        tell_object(me, HIC "�A�B�_���\\�A�ƴH�B���𬰤��O.....\n\n\n\n" NOR );
        tell_object(me, HIR "�A�����Ѧ��G��ˤF..... :)\n\n\n" NOR );
        me->disable_player_cmds("�A���b�𮧡C\n");
        me->set_temp("is_busy/qking","�A���b�𮧡C");
        me->start_busy(5);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
        tell_object(me,HIG"�A�N�G�ߤ��𺥺��^í�A�ǳƦ��\\��\n"NOR);
        me->receive_heal("hp",me->query_con()*1);
        me->receive_heal("ap",me->query_con()*3);
        me->receive_heal("mp",me->query_int()*2);
        return;
}

void sleep2(object me)
{
        if(!me) return;
        tell_object(me,HIG"�A�����⥪�k�����F�X��A���֤@�}�A�믫��_�F����\n"NOR);
        me->receive_heal("hp",me->query_con()*3);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision(HIB"$N���l�@�f��A�����i�y�A�q�H�B�ɤW���F�U�ӡC\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/qking");
        me->receive_heal("hp",me->query_con()*2);
        me->receive_heal("mp",1+me->query_int()*1);
        me->receive_heal("ap",me->query_con()*10);
        me->add_temp("qk",-1);
        return;
}

