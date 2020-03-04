#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"�y����"HIW+BLK"�w"HIW"�p�̫F"NOR);
        set("long", @LONG
�A�Ө�F�y�������ȴ�--�p�̫F, �A�ݨ�o�̦��|�i�j��l
, ��l���٦��X�i�Ȥl, �A�i�H�b�o�̼Ȯɥ�(rest), ���ϧA
�u���֪ܲ���, �A�]�i�H�W�Ӻέ�ı�A�X�o.
LONG
        );
        set("exits", (["east": __DIR__"village7",
                       "up" : __DIR__"village9",
                      ]));
        set("objects", ([__DIR__"npc/waiter4" : 1,
        ]));
      
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("map","hotel");
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="up" )return ::valid_leave(me, dir);

        if( dir=="up" && me->query_temp("sleep") <=0 || !me->query_temp("sleep") )
                return notify_fail("�A�٨S�V���p�G�q�ж��I\n");

        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_rest","rest");
}

int do_rest(string arg)
{
        object me;
        me = this_player();
        if( me->is_busy() )
                return notify_fail("�A�٦b���a, ���ӨS�ɶ��h����. \n");
        if( me->query_temp("rest") <= 0 )
        {
                write("�A�үෲ�������Ƥw�Υ��F�I\n");
                return 1;
        }
        if( me->query_temp("is_busy/sitting") )
        {
                write("�A���b�R���C\n");
                return 1;
        }
        message_vision("$N�b�o�̧�F�@�Ӧ�l���F�U�ӡA�}�l�R���F�_�ӡC\n",me);
        me->add_temp("rest",-1);
        me->set_temp("is_busy/sitting","�A���b�R���C");
        me->start_busy(10);
        call_out("sleep",0,1,me);
        call_out("sleep",10,2,me);
        return 1;
}

void sleep(int c,object me)
{
        switch(c) {
        case 1:
                tell_object(me,HIC"�A�����}�l�i�J�ߪŪ����A�A���򳣤��Q�D�D\n"NOR);
                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);
        break;

        case 2:
                tell_object(me,HIG"�A�����C�}�����A��ߵ����F�^�ӡC\n"NOR);
                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int());
                me->delete_temp("is_busy/sitting");
        break;
        }
}

