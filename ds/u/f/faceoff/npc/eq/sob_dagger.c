#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
        set_name(HIR"�_��"NOR, ({ "dragon dagger","dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�ǻ����o�O���R���٪����W�Z�����@, �ڻ����P
�쬰�@��k�L�Ҧ�, �ӥB���G�M�ѱ����@�q���Ѫ��t��, �o��P����F�C��G�Q�G
��]�߳��|�o�X���_���n, �B�q�P�T�o�X�w�����n����, ���L�ǻ��k�ǻ�, �o�@��
�P���M���L�x�t��, ���G���@�Ѧ��������b��W.");
                set("value", 600);
                set("material", "steel");
        }
        init_dagger(45);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N��ⴤ��$n, �K�ɤ@�}���𪽽Ħʨ���! �C\n");
        set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");

// The setup() is required.

        setup();
}
