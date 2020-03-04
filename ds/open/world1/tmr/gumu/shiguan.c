// Room: /d/gumu/shiguan.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIB"�۴ä�"NOR);
        set("long", @LONG
�û\�������G�g�o���r�A�����@�h�A�G���O�Q���Ӥj�r�G�u�ɤk��
�g�A�������u�C�����@�͡A���z�_�H�C�v�o�Q���Ӧr�H�@���ҮѡA���O
�a�l�A�r��Ƥj�C��ɴû\�u���}�F�@�b�A���ײ��ݥh�A���O�M�M�����C
LONG    );
        set("exits", ([ 
                "out" : __DIR__"lingshi",
        ]));
        set("no_clean_up", 0);
        set("no_fight",1);
        setup();
}

void init()
{
        add_action("do_dian", "use");
        add_action("do_turn", "turn");
        add_action("do_ti", "pull");
        add_action("do_search","search");
}

int do_dian(string arg)
{
        object ob,me=this_player();

        if ( arg == "fire")
        {
                if(!objectp(ob = present("fire", me)))
                        return notify_fail("�A�S������A�I����H\n");
                message_vision(HIR"�uť�����M ---�����@�n�A$N�I�G�F�⤤������C\n\n"NOR,me);
                        write(HIY"�A�ݨ��Q���Ӧr�ɡA�u������ټg�o���\\�h�p�r�G�}�ѥɤk�߸g���k�A�^�m���_���Ǥ��U�A��H���t�A�@�[�K�� ......�����u�H .....\n"NOR);

                me->set_temp("marks/�j��1", 1);
                return 1;
        }
        return 0;
}

int do_search()
{
        object me = this_player();

        if (!me->query_temp("marks/�j��1")) return 0;
        if (me->query_temp("tomb_search") < 8)
        {
                message_vision(HIY"$N�I�G����A�J�Ӧa�b�۴ä��|�U�N���C\n"NOR,me);
                me->add_temp("tomb_search",1);
                return 1;
        }
        message_vision(HIR"$Nı�o��U�@�I�A�G�M�N��ӥi�e�@�⪺�W(ao)�B�A�����D�O�_�i�H���(turn)�C\n"NOR,me);
        me->delete_temp("marks/�j��1");
        me->delete_temp("tomb_search");
        me->set_temp("marks/�j��2", 2);
        return 1;
}

int do_turn(string arg)
{
        object me=this_player();
        string dir;
        if (!me->query_temp("marks/�j��2")) return 0;
        if (!arg||arg=="") return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۭ��I\n");
        if( arg=="ao" )
        {
                write("�A�n��W�B��������H\n");
        }
        if( sscanf(arg, "ao %s", dir)==1 )
        {
                if( dir=="left")
                {
                        message_vision(HIG"$N�N�W�B������ʴX�U�A�G�M�����P�ʡA�A�γ\\�|�Q�n�⥦��(pull)�_�ӬݬݡC\n"NOR, me);
                        me->delete_temp("marks/�j��2");
                        me->set_temp("marks/�j��3", 1);
                }
                else
                        message_vision(CYN"$N�N�W�B�J����F�X�U�A���G����]�S�o�͡C\n"NOR, me);
        }
        return 1;
}

int do_ti(string arg)
{
        object me =this_player();

        if (!me->query_temp("marks/�j��3")) return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۭ��I\n");
        if ( arg =="up")
        {
                message_vision(YEL "$N��򴤦�F�W�B�V�W�@���A�uť�س�@�T�A�é��۪O����Ӱ_�A$N�`���Ψ��A½���^�J�U�h�۫ǡC\n"NOR,me);
                me->delete_temp("marks/�j��3");
                me->move(__DIR__"shishi6");
                return 1;
        }
        return notify_fail("�A���������H\n");
}

