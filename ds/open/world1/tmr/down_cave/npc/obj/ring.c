#include <armor.h>

inherit F_FINGER_EQ;

void create()
{
          set_name("�٫�", ({ "ring" }) );
        set_weight(100);
        setup_finger_eq();

        if( !clonep() ) {
                set("unit", "�T");
                set("value", 1500);
                set("long",@long
�o�O�@�T�y�Ǧb��{��W���٫��A�`�Q�y���b���䪺���]����ۡA�q
�`�֦��_�S���]�O�C                
long
                );
                set("wear_as", "finger_eq");
                set("apply_armor/finger_eq", ([
                        "armor": 2,
                ]));
        }
        setup();
        set("name",
                  ENHANCE_D->enhance_armor(this_object(),0,"�٫�") );

}


