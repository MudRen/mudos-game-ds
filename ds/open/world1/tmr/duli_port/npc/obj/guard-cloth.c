#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name("����A", ({ "guard cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 250);
                set("long", 
                "�o�O�@��M����ĵ�ì諸��A�A�ݫe�f�U�٦��@�ӡuĵ�v���r�ˡC\n"
                );
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 3,
                ]));
        }

        setup();
}

