#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(MAG"殺神一式" HIG"風"NOR ,({ "killgod-wind surcoat","surcoat" }) );
        set("long",
"蚩尤當時剛稱皇時,因以自己天地為尊,鬼神都要敬他三分, \n""風神就幫他批了一件披風,命名為 殺神一式 風。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "silk");
        set("unit", "件" );
        set("value",400);
set("volume",3);
        }
          set("armor_prop/armor", 5);
          set("armor_prop/int", 1);
          set("armor_prop/sword", -20);
          set("armor_prop/dex", 1); 
          set("armor_prop/str", -1);         setup();
}


