#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("��M", ({ "wood blade","blade" }) );
        set_weight(3000);
        setup_blade(1,8,40,4);

        if( !clonep() ) {
                set("wield_as", ({"blade","twohanded blade"}));
                set("unit", "��");
                set("value", 350);
                set("rigidity", 30);
                set("long", 
"�o�O�@��p��M�A�Q���Ө����ٵy�������C\n"
                );
        }
        setup();
}

