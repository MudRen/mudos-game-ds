#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name("�y�a", ({ "belt"}) );
        set_weight(300);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 2000);
                set("long", "�o�O�@���y�Ǧb��{��W���y�a�A�`�Q�y���b���䪺���]����ۡC\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "armor": 2,
                ]));
        }
        setup();
        set("name",
                  ENHANCE_D->enhance_armor(this_object(),0,"�y�a") );
}

