
#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("���C", ({ "long sword", "sword" }) );
          set_weight(7000);
        setup_sword(2, 10, 40, 2);

        if( !clonep() ) {
                set("wield_as", "sword");
                set("unit", "��");
                set("value", 500);
                set("rigidity", 20);
                set("long", "�o�O�@���K���y�����C�A��_�u�C�ӡA��㦳���ˤO�C\n");
        }
        setup();
}

