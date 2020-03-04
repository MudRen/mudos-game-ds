#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
        set_name(HIR"�_��"NOR, ({ "sob dagger","dagger" }) );
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��"); 
                set("long", "�ǻ����o�O���R���٪����W�Z�����@�A�ڻ����P�쬰�@��k�L�Ҧ��A��\n"
                            "�G�M�ѱ����@�q���Ѫ��t���E�o��P����F�C��G�Q�G�骺�]�ߡA���|\n"
                            "�o�X���_���n�A�B�q�P�T�o�X�w�����n�����E���L�ǻ��k�ǻ��A�o�@��\n"
                            "�P���M���L�x�t���A���G���@�Ѧ��������b��W�E\n");
                set("value", 3300);
                set("material", "steel");
                set("volume",1);
        }
        init_dagger(39);
        set("wield_msg", "$N��ⴤ��$n, �K�ɤ@�}���𪽽Ħʨ��ޡI\n");
        set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");
        setup(); 
        call_out("sob", 60);
}

void sob()
{
        object me = environment(this_object());

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("weapon") == this_object())
        {
        message_vision(CYN"$N��M�o�X�@�}�Y�F���������n�A�D�̬Ҥ��H�ӷX�K�K\n"NOR, this_object());
        }
        call_out("sob", 120);
}

