#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("���", ({ "wood axe","axe" }) );
        set_weight(3000);
        setup_axe(1,8,30, 4);

        if( !clonep() ) {
                set("wield_as", ({"axe","twohanded axe"}));
                set("unit", "��");
                set("value", 350);
                set("rigidity", 30);
                set("long", 
"�o�O�@��p�ӥ�����s���Y�A���Ӭ�����ٳ��ϥΡC\n"
                );
        }
        setup();
}

