#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name( "�Ǧ�W��", ({ "grey cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1500 );
                set("long",@long
�o�O�@�����ᬰ���Ū��Ǧ�W��A�ᦳ�O�x���ġC
long
                );
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor" : 3,
                ]));
        }

        setup();
}
