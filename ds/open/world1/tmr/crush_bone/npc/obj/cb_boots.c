#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("�H����ɹu", ({ "crush bone boots", "boots" }) );
        set_weight(2500);

        if( !clonep() ) {
                set("unit", "��");
                  set("value", 800);
                set("long",@long
�o�O�@���ѸH����S���K�q�ʻɩҥ��y���@���ɹu�C
long
                );
                //set("wear_as", "feet_eq");
        } else 
                     set_default_object(__FILE__);


        setup();
}

