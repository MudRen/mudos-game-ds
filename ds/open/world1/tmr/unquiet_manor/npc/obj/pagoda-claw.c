#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(GRN"�i�K�F��"NOR,({"pagoda claw","claw"}) );
        set("long","�o�O�Ѻi��K�ΤH���զ����@��F���A���ͤ��𷥭��A�x�p���H�ڥ��S�k�l���C\n");
        set_weight(3000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
                set("value", 16000);
                set("material","gold");
                set("weapon_prop/int", 2);
                set("weapon_prop/str", 1);
                set("weapon_prop/hit", 5);
                set("volume",2);
                set("limit_int", 40);
                set("limit_level", 30);
        init_fist(55);
        setup();
}

