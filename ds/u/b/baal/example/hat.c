#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("昊戠頭盔" ,({ "hao chi hat","hat" }) );
        set("long","這是一個官兵常穿戴的防身頭盔。\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "iron");
        set("unit", "個" );
         set("value",700);
set("volume",2);
        }
          set("armor_prop/armor", 6);
        setup();
}
