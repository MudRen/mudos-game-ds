// �i�H�Y���� rice.c
// Wed Nov 27 10:23:41 CST 1996 by Lsr@FSS

#include <ansi.h>

inherit ITEM;

string *RICE_MSG = ({
                CYN"$N"CYN"���_�p���͡A�����m�۪����C\n\n"NOR,
                CYN"�����������ϱo$N���G�}�l��t���c�G�G�C\n\n"NOR,
                CYN"$N�ί�F�@�ֳͧt��J�f���A�S�X���j������ @_@ \n\n"NOR,
                CYN"$N��M�η��֪��t�ק�L�l�����a�ݰ_�ӡC\n\n"NOR,
                CYN"$N�i�}�v�ܩi�몺�j�L�ڡA�@�f�⪣���]�i�h ..:D\n\n"NOR,
                CYN"$N��L�l�q�L�̩ԥX�ӡA�S�X���N������  :D~~~\n\n"NOR,
                });

void rice_msg(object me,int x);

void create()
{
        set_name(HIW"����"NOR, ({ "rice" }) );
        set("long",@LONG
�ȽL�l�W�˵ۭ������J�����A�����\�ۤ@��p���͡C
LONG
        );
        set("unit", "�L");
        set("base_weight", 200);
        set("value", 300);
}

void init()
{
        if( this_player()==environment() )
        add_action("xdo_eat","eat");
}

int xdo_eat(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return notify_fail("�A�Q�Y����O? \n");
        if( arg == "rice" )
        rice_msg(me,0);
        return 1;
}

void rice_msg(object me,int x)
{
        message_vision(RICE_MSG[x],me);
        if( ++x < sizeof(RICE_MSG) ) {
                call_out("rice_msg", 1, me, x);
        }
        else destruct(this_object());
        return;
}

