#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIB "血盔" NOR,({ "blood-hat","hat" }) );
        set("long",
"血盔，正如其名，整個頭盔上都是血。新的。濕漉漉的鮮血。
不斷在盔上流淌。好像流不盡的樣子，傳說人帶上此盔即成惡鬼，
鬼帶上此盔即成惡魔！。\n"
);
        set_weight(1900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "頂" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/str", -1);
        }
        setup();
}

