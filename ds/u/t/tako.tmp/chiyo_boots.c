#include <armor.h>

#include <ansi.h>

inherit BOOTS;

void create()

{

        set_name("��c" ,({ "straw sandals","sandals" }) );

        set("long","�@���ܯ}�ª��c�l,�n����F�ܪ����@�q�ɶ��F\n");

        set_weight(3000);

        if ( clonep() )

                set_default_object(__FILE__);

        else {
                set("material", "leather");                set("unit","��");
                set("limit_con",2);
}                
                set("value",220);

                set("volume",3);
                set("armor_prop/armor",5);                set("armor_prop/dex", 1);
                set("armor_prop/dodge",7);
                set("armor_prop/con",-3);

        setup();

}

