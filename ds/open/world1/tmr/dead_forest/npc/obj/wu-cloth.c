#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name( "�Q���_��" , ({ "wu-silkworm cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 8500 );
                set("long", "�o�O�@��ίQ������������A�A���M�j���J�B�������I�A�O�D�`���Q���_��C\n");
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 5,
                        "dodge": 5,
                        "cps": 1,
                ]));
        }

        setup();
}
