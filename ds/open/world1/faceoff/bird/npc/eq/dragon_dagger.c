#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
        set_name(HIC"�J���s"NOR, ({ "dragon dagger","dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�ǻ����o�O���R���٪����W�Z��, �P�_�ߦX��
�����P,���_�ߤw��������h�~, �ѤU���o��J���s�b�P�ɤ����w�i�٤�, �A�J
�Ӥ@��, �M���L�x�Ŧ�, �����a���H������,�O�@�ⷥ�����Ū��P��.");
set("value", 30000);
                set("material", "steel");
        }
        init_dagger(40);
set("replica_ob", __DIR__"dagger.c");
 set("weapon_prop/int", 3);
 set("weapon_prop/dex", 2);
 set("weapon_prop/str", -2);
// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N��ⴤ��$n, �K�ɤ@�}�H�𪽽��F���! �C\n");
        set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");

// The setup() is required.

        setup();
}

