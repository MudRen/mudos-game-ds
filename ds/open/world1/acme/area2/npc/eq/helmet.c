#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("軹瓏頭盔" ,({ "zhi lung helmet","helmet" }) );
        set("long","這是一頂紫氣大現的頭盔，但頗為沉重。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(12000);
        set("material", "iron");
        set("unit", "頂" );
       set("value",2000);
                set("volume",3);
        }
        set("limit_str",8);
          set("limit_con",20);
     set("armor_prop/armor",9);
        set("armor_prop/int",3);
         set("armor_prop/dex",-1);
        setup();
}

