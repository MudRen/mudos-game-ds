#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("���׵u�M", ({ "short knife","knife" }) );
        set_weight(2500);
        setup_blade(1, 12, 60, 0);

        if( !clonep() ) {
			set("wield_as", ({ "blade" , "secondhand blade" }));
                set("unit", "��");
                set("value", 450);
                set("rigidity", 25);
                set("long", 
"�o�O�@���K�s���w�g���ת��u�M�A�ѩ����K�y�A�@��H����R����C\n"
                );
        }
        setup();
        /* ��Sblade */
        set("name",
                ENHANCE_D->enhance_weapon(this_object(),0,"�u�M") );
}
