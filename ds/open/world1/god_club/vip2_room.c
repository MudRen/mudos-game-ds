#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"�n�@�өж�"NOR);
        set("long", @long

�o�O�@�ӥR���ۯ��t�𮧪��ж��A���b�o�̡A�A�Pı��ۤv�N���t�H
�L�ƪ����P��W���Y�A���T���A�Q�u�Ӹ֡B�@�ӹ�F�C

long    );
        set("light", 1);
        set("exits", ([
  "southwestdown": __DIR__"flag_devilrom.c",
]));
set("outdoors","land");
        setup();
        set("stroom", 1); 
}
/*
int room_effect(object me)
{
        switch(random(5))
        {
         case 0:
         write("�A���b���e�A�ɨ��۶����N�D���ַP�C\n");
         tell_object(me, HIY "�Aı�o�������R���F���O�C\n" NOR ); 
me->delete("wound");
me->receive_heal("hp",200);
         return 1;

         case 1:
         write("�A���b�ɤW�A�P���ۭ��j�i�ж����𮧡C\n");
         tell_object(me, HIC "�Aı�o�Y���M���F���֡C\n" NOR ); 
me->delete("wound");
         me->receive_heal("mp",200);
         return 1;

         case 2:
write("�Aı�o�L��A��O�b�ж����m�_�F���k�C\n");
         tell_object(me, HIB "�Aı�o�����R����O�A�n���Z�֡I\n" NOR ); 
         me->receive_heal("ap",200);
me->delete("wound");
         return 1;
         default:       return 1;
         }
}

void init()
{
        add_action("do_full","full");
}
int do_full(string arg)
{
        object me;
        me = this_player();
        if( me->is_busy() )
                return notify_fail("�A�٦b���a, ���ӨS�ɶ��h�l��. \n");
                me->start_busy(1);

call_out("full",0,1,me);
call_out("full",0,2,me);
        return 1;
}

void full(int c,object me)
{
        switch(c) {
        case 1:
                tell_object(me,HIC"�A�j�j���l�F�@�f���t����D�D\n"NOR);
                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);
        break;

        case 2:
                tell_object(me,HIG"�Aı�o�믫�����A�����R���O�q�I\n"NOR);
                me->set("hp",me->query("max_hp") );
                me->set("mp",me->query("max_mp") );
                me->set("ap",me->query("max_ap") );
                        break;
        }
}
*/
