#include <armor.h>

#include <ansi.h>

inherit CLOTH;

void create()

{

        set_name(HIR"卍"HIW"語"HIY"護"HIC"袍"NOR ,({ "more cloth","cloth" }) );

        set_weight(1000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

 set("long",@LONG

這是傳說中羽夜子在十歲當年某高僧給他的護袍。

LONG

     );

                set("unit", "件");

                set("value",500);

                set("material", "steel");

                set("armor_prop/shield",2);

                set("armor_prop/con",3);

                set("armor_prop/armor", 23);

        }

        setup();

}
