// cane.c

#include <weapon.h>

inherit F_BLUNT;

void create()
{
        set_name("����", ({ "fishing rod","rod","_OBJECT_ROD_" }) );
        set_weight(1000);
        setup_blunt(1, 14, 40, 2);

        if( !clonep() ) {
                set("wield_as", ({ "blunt" }) );
                set("unit", "��");
                set("value", 250);
                set("rigidity", 12);
                set("long",
                        "�@�ڥΦˤl�������Ӫ�����C\n");
        }
        setup();
}

