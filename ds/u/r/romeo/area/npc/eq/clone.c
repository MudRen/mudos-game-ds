#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY "金縷衣"NOR,({ "golden-silk-cloth","cloth" }) );
        set("long",
"以金絲將玉片連結起來的衣服，通常是為了王公貴族死後埋葬而製
，而這一件金縷衣的玉片十分精細，使其不但不像一般的金縷衣厚重
，並且玉片更散發出溫潤鮮紅的光澤，看來這些玉不知吸收了幾百年
死人的血氣才有這樣的美麗。。\n"
);
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "件" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/int", -1);
        }
        setup();
}

