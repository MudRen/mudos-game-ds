#include <armor.h>

#include <ansi.h>

inherit BOOTS;

void create()

{

        set_name(HIM"輕步"HIG"靴"NOR ,({ "hight boots" , "boots" , "hight" }) );

        set("long","這是疾風門專用的鞋子，傳說穿上這雙鞋子後，能像貓走路一般的輕。\n");

        set_weight(3000);

        if ( clonep() )

                set_default_object(__FILE__);

        else {

                set("unit"  ,"雙");

                set("value" , 220);

                set("armor_prop/dex",    10);

        set("material","cloth");

                set("volume",2);

                set("armor_prop/armor",  50);

        }

        set("wear_msg","$N穿上了疾風門的$n。\n");

    set("unequip_msg","$N脫下了$n。\n");

        setup();

}
