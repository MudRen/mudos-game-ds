#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("��M", ({ "blade" }) );
        set_weight(3500);
        setup_blade(1, 14, 60, 2);

        if( !clonep() ) {
                set("wield_as", ({"blade"}));
                set("unit", "��");
                set("value", 500);
                set("rigidity", 25);
                set("long", 
"�o�O�@���K�s����M�A�ѩ����K�y�A�@��H����R����C\n"
                );
        }
        setup();
        /* ��Sblade */
        set("name",
                ENHANCE_D->enhance_weapon(this_object(),0,"�M") );
}

