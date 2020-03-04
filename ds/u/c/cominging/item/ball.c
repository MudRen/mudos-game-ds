// ball.c, celebrate NBA bull's victory, clone only, temporary obj by grain

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name(HIM+"�x�y"+NOR, ({ "basket ball", "ball" }));
        if( !clonep() ) {
                set("unit", "��");
                set("base_unit", "��");
                set("base_value", 1);
                set("base_weight", 1);
                set("long", "
�@���ݰ_�Ӯ��s�o���x�y, �W���蹺��

 #####   #    #  #       #               #####   #    #  #    #   ####
  #    #  #    #  #       #               #    #  #    #  ##   #  #
   #####   #    #  #       #               #    #  #    #  # #  #   ####
    #    #  #    #  #       #               #####   #    #  #  # #       #
     #    #  #    #  #       #               #   #   #    #  #   ##  #    #
      #####    ####   ######  ######          #    #   ####   #    #   ####

                �����O�ƻ�N��, �̫��٦��X���U�k�r��, ���G�g���O
                play [<�b�����H>]       :�B�y [���]
                pass <����u�W���H>     :�ǲy <����>
                shake                   :�n�y
                ");
        }
        setup();
}

void init()
{
        add_action("do_play", "play");
        add_action("do_pass", "pass");
        add_action("do_shake", "shake");
}

int do_play(string arg)
{
        object me, target;
        me=this_player();
        if( me->is_busy() )
                return notify_fail("�A���b��.\n");
        if( arg )
                target=present(arg, environment(me));
        me->start_busy(10);
        if( !target ){
                call_out((:message_vision("\n�I��@�I�I��@�I��  �I�I��\n", $1):), 1,me);
                call_out((:message_vision("\t$N�}�l�B�_�y��\n", $1):), 3, me);
                call_out((:message_vision("\t\t$N����k��, ��U�B�y\n", $1):), 5, me);
                call_out((:message_vision("\t\t\t$N�i�}�j�L, �̰ʵۦ��Y, �����D�b�ǽ�\n", $1):), 7, me);
                call_out((:message_vision("\n\t�I��@�I�I��@�I��  �I�I��\n", $1):), 9, me);
        } else {
                call_out((:message_vision("\n�I��@�I�I��@�I��  �I�I��\n", $1):), 1,me);
                call_out((:message_vision("\t$N�}�l�b$n���ǹB�_�y��\n", $1, $2):), 3, me, target);
                call_out((:message_vision("\t\t$N�V��$n����k��, ��U�B�y, �������˵�$n\n", $1, $2):), 5, me, target);
                call_out((:message_vision("\t\t\t$N�i�}�j�L, �̰ʵۦ��Y, �@�I�n��$n�������ˤl\n", $1, $2):), 7, me, target);
                call_out((:message_vision("\n�I��@�I�I��@�I��  �I�I��\n", $1, $2):), 9, me, target);
        }
        return 1;
}

int do_pass(string arg)
{
        object me, target;
        string msg;

        if(!arg) return notify_fail("SYNTAX: pass <ID>\n");
        me=this_player();
        if( me->is_busy() )
                return notify_fail("�A���b��.\n");
        target=find_player(arg);
        if(!target || !interactive(target))
                return notify_fail(arg+"���b�u�W, �Ϊ̤w�g�_�u�F.\n");
        if( me==target )
                return notify_fail("�ǵ��O�H�a, �ѤѦӭ����y�A�i�S�ⴤ�౵��.\n");
        if( !this_object()->move(target) )
                return notify_fail(arg+"������y, �A�٬O�ǵ��O�H�a.\n");
        msg="�A�¤Ѥj��: �U�઺�Ӷ���, �бN�����x�y�{�V "+target->name()+" , ��"+gender_pronoun(target)+"�U�a���h�a!\n";
        write(HIM+ msg+ NOR);
        msg="\n\t�Ať�� "+capitalize(me->query("id"))+" ���R��: \n\t    �U�઺�Ӷ���, �бN�����x�y�{�V "+target->name()+" , ��"+gender_pronoun(target)+"�U�a���h�a!\n";
        message("shout", MAG+ msg+ NOR, users(), me);
        msg="\n�I��@�I�I��@�I��  �I�I��\n";
        call_out((:message("tell", $1, $2):), 1, msg, environment(target));
        msg="\n\t�@���������y, �ѤѦӭ�,  �����S��  �������b�A�Y�W, �A��o�F�@���y\n";
        call_out((:message("tell", HIR+ $1+ NOR, $2):), 2, msg, target);
        target->start_busy(6);
        msg="\n   �@���������y, �ѤѦӭ�,  �����S��  �������b "+target->name()+" �Y�W\n    "+target->name()+"�Ⲵ�L�Q�L���R�j, �˦b�a�W���f.\n";
        call_out((:message("tell", $1, $2, $3):), 3, msg, environment(target), target);
        return 1;
}

int do_shake()
{
        string msg;
        if( this_player()->is_busy() )
                return notify_fail("�A���b��.\n");
        this_player()->start_busy(2);
        msg="\t�Ať�����Ǩ�  �㤽�����[��o�� ���n��\n";
        call_out((:message("tell_r", HIM+ $1 +NOR, $2):), random(4), msg, environment(this_player()));
        call_out((:message("tell_r", HIM+ $1 +NOR, $2):), random(4), msg, environment(this_player()));
        return 1;
}

