// Room: /d/gumu/woshi1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",HIC"�p�׫�"NOR);
        set("long", @LONG
�o���O���L��~���׫ǡA�Ф��ŪŬ}�}�C�@�������C�ۧ@�ɡA�ɤW
�Q�F�i��u�A�@�T�ե���@���Q�A���~���F�@�ڤH����÷����L�Ǥ��A
�O�L�L���C
LONG    );
        set("exits", ([
                "west" : __DIR__"mudao20",
        ]));
        set("objects", ([
                __DIR__"obj/bed" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_zuo", "sleep");
}

int do_zuo(string arg)
{
        object me = this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۭ��I\n");

        if (arg == "bed" )
        {
                if( me->query_skill("force", 1) < 10)
                {
                        message_vision("$N�{�b�����\\�Ө�����H�ɧɪ��H�B����C\n", me);
                        me->start_busy(1);
                        return 1;
                }

                if( me->query("hp") < 50
                || me->query("ap") < 50
                || me->query("mp") < 50 )
                {
                        message_vision("$N�{�b������L�k�Ө�����H�ɧɪ��H�B����C\n", me);
                        me->start_busy(1);
                        return 1;
                }

                 message_vision("$N���W�F�H�ɧɡA�}�l��B���\\�A�Ϥ����M��j�p�P�ѡC\n", me);
                 me->receive_damage("ap", 50 );
                 me->receive_damage("hp", 50 );
                 me->receive_damage("mp", 50 );
                 if (random(10) > 2)
                 {
                        message_vision(HIC"$N�ծ������A�uı�o�믫�����A�����R���l�O�C\n"NOR, me);
                        if( me->query_condition("blooding") && random(3) ) {
                                message_vision(HIW"$N���W�y�媺�ˤf�A���M�_�񦡦a�ֳt¡�X�F�C\n"NOR, me);
                                me->apply_condition("blooding", 1);
                        }
                        me->receive_curing("all", 2 );
                  } else
                        message_vision(CYN"$N���W�H�ɧɡA�uı�o�B�N�방�A�u�ڡv���@�n�T�V�����a���F�_�ӡC\n"NOR, me);
                me->start_busy(4);
                return 1;
        }
        
        return notify_fail("�A�n���b�����H\n");
}

