#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("�u�C", ({ "short sword", "sword" }) );
        set_weight(2000);
        setup_sword(1, 14, 75, 5);

        if( !clonep() ) {
                set("wield_as", ({"sword","secondhand sword"}));
                set("unit", "��");
                set("value", 300);
                set("rigidity", 10);
                set("long", "�@���K�s���u�C�A�O�@��ȤH���򥻨����Z���C\n");
        }
        setup();
        /* ��Ssword */
        set("name",
                ENHANCE_D->enhance_weapon(this_object(),0,"�u�C") );
}

