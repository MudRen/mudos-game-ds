#include <armor.h>

inherit HEAD;

void create()
{
        set_name("�i���Y�y",({"brave scarf","scarf"}) );
        set("long","�o�O�u���u�����i�h�i�j���Y�y�C\n");
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","steel");
                set("unit", "��");
                set("value",1200);
                set("limit_lv",25);
                set("armor_prop/armor", 4);
                set("armor_prop/int",3);         
                set("armor_prop/dex",3);
        }
        setup();
}


