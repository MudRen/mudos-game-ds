#include <weapon.h>

inherit FIST;

void create()
{
        set_name("�K��", ({ "iron claw","claw" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@�ӱ`�����K���C\n");
                set("material", "iron");
        }
        init_fist(4);
        set("wield_msg", "$N�N�K���˦b��W.\n");

        set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");

        setup();
}
