#include <ansi.h>
#include <armor.h>
inherit WRISTS;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"清風腕"NOR,({"white wrists","wrists"}) );
        set("long",@LONG
你完全看不出來這是什麼材質，硬要說的話，大概是絲綢一類的吧！
令你驚異的是它的觸感，既輕且柔......
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",20);
                set("unit", "雙");
                set("light",1);       
                set("value",10700);          
                set("volume", 4);                       
                set("material", "silk");   
        }
          set("limit_int",40);
          set("limit_dex",40);
        set("armor_prop/armor",7);  
set("armor_prop/wit",1);
       set("armor_prop/bar",-1);
        set("armor_prop/dex",2);
        set("armor_prop/str",2);
        setup();
}

