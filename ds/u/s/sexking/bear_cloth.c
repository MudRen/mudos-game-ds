#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("忍束裝",({"bear cloth","cloth"}) );
        set("long",@long
這件衣服黑漆漆的一片，大都是忍者們行動時穿的衣服。
LONG
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
           set("material", "cloth");            
           set("unit", "件"); 
          set("value",1000);
          set("armor_prop/int",1);         
          set("armor_prop/armor",6); 
          set("volume",4); 
         set("armor_prop/show_damage",1);
 }
setup();
}
