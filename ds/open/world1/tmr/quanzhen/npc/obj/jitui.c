// jitui.c ���L

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("�N���L", ({ "jitui", "tui" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�K�N�o���Q�Q�����L�C\n");
                set("unit", "��");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 15);
                set("wield_msg", "$N��_�@��$n�A���b�⤤��Z���C\n");
                set("material", "bone");
        }
        init_hammer(1);
        setup();
}

int finish_eat()
{
        if( !query("weapon_prop") ) return 0;
        set_name("�ٱo��������L���Y", ({ "bone" }) );
        set_weight(150);
        set("long", "�@�ڰٱo��������L���Y�C\n");
        return 1;
}
