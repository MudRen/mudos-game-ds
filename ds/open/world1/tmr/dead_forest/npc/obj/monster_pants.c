#include <armor.h>

inherit F_PANTS;

void create()
{
        set_name("��֤��", ({ "lion pants", "pants" }) );
        set_weight(2500);
        setup_pants();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 500 );
                set("long","�o�O�@��η�ֻs������ǡA���M���W���O�@�i�A�֦��۷�{�ת��@�ΡC");
                set("wear_as", "pants");
                set("apply_armor/pants", ([
                        "armor": 3 ,
                ]));
        }

        setup();
}
