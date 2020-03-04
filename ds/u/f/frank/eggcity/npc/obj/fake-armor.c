#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("錟都無敵金剛甲",({"matchless armor","armor"}) );
        set("long",@LONG
一身金光閃閃的盔甲，流線型的造型，深深吸引人的目光，不過只是
仿造品不過，他確實是不錯的盔甲。
LONG
);
        set_weight(5000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",15);
                set("limit_con",15);
                set("unit", "件");       
                set("value",100);          
                set("volume", 3);                       
                set("material", "air");   
        }
        set("monster_armor_type","armor");
        set("monster_armor_prop/armor",32);       
        set("monster_armor_prop/con",3);
        set("monster_armor_prop/shield",18);
        set("armor_prop/armor",30);
        set("armor_prop/shield",18);
        set("armor_prop/con",2);
        setup();
}


