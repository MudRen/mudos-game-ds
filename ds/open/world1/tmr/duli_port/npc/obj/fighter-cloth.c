#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name("�Z�D�A", ({ "fighter cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 250);
                set("long", "�@��ݤf¸���u�ȤM�v�r�˪��Z���A�A��a�N�_�ӫD�`���ΪA�C\n");
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 4,
                ]));
        }

        setup();
}


