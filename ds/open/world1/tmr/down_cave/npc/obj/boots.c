#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("���u", ({"boots" }) );
        set_weight(2500);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1500);
                set("long",@long
�o�O�@���y�Ǧb��{��W�����u�A�`�Q�y���b���䪺���]����ۡA�q
�`�㦳�_�S����O�A��ϥΪ̯���o�B�~�����U�C
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 5,
                ]));
        }

        setup();
        set("name",
                  ENHANCE_D->enhance_armor(this_object(),0,"���u") );
}

