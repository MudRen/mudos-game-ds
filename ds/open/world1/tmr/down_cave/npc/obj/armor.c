#include <armor.h>
inherit F_ARMOR;
void create()
{
        set_name("����", ({  "armor" }) );
          set_weight(10000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 2000);
                set("long", "�o�O�@��y�Ǧb��{��W�����ҡA�`�Q�y���b���䪺���]����ۡC\n");
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                          "armor": 10,
                ]));
        }
        setup();
        set("name",
                  ENHANCE_D->enhance_armor(this_object(),0,"����") );
}


