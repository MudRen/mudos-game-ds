#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("�j�M", ({ "big blade", "blade" }) );
        set_weight(8000);
          setup_blade(2, 10, 120, 4);

        if( !clonep() ) {
                set("wield_as", ({"blade","twohanded blade"}));
                set("unit", "��");
                set("value", 500);
                set("rigidity", 30);
                set("long", 
"�o�O�@����M�W�N����b���ت��j�M�A�O�q�y���������H�A�s���������ʡC\n"
                );
        }
        setup();
}

