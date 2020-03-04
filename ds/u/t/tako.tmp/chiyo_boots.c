#include <armor.h>

#include <ansi.h>

inherit BOOTS;

void create()

{

        set_name("草鞋" ,({ "straw sandals","sandals" }) );

        set("long","一雙很破舊的鞋子,好像穿了很長的一段時間了\n");

        set_weight(3000);

        if ( clonep() )

                set_default_object(__FILE__);

        else {
                set("material", "leather");                set("unit","雙");
                set("limit_con",2);
}                
                set("value",220);

                set("volume",3);
                set("armor_prop/armor",5);                set("armor_prop/dex", 1);
                set("armor_prop/dodge",7);
                set("armor_prop/con",-3);

        setup();

}

