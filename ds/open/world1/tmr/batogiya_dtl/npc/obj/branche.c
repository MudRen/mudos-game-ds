// ��K weapon

#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("�\��K", ({ "branche", "branche" }) );
        set_weight(2000);
        setup_sword(1, 8, 20, 0);
        if( !clonep() ) {
                set("wield_as", 
                ({"sword","secondhand sword"})
                );
                set("unit", "��");
                set("value", 50);
                set("rigidity", 10);
                set("long", "�o�O�@�ڤw�\����K�A���ӷ���C�A�ˤ]�i��C\n");
        }
        setup();
}

