#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("������u", ({ "steel boots", "boots" }) );
        set_weight(2500);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 2500);
                set("long",@long
�o�O�@��������y�����u�A�y������j��A�D�`�a��T�@��C
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 10,
                        "dex": -1,
                ]));
        }

        setup();
}
