#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name("�¦�򨭦�", ({ "black body suit", "suit" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1500);
                set("long",@long
�o�O�@��k�H�b�諸�¦�򨭦�A�A���G�٥i�H�D��W�Y�ݯd�U�Ӫ��k�H�����C
long
                );
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 3,
                        "int": 1,
                        "dex": -1,
                ]));
        }

        setup();
}

