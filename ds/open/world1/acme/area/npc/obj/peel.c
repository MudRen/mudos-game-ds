#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("柚子皮" ,({ "pomelo's peel" , "peel" }) );
        set("long","這是一個厚厚的柚子皮，乍看之下，還真像一頂帽子。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "peel");
        set("unit", "頂" );
                set("value",10);
        }
        set("armor_prop/armor", 1);
        set("armor_prop/id",({"strange man","man"}));
        set("armor_prop/name",({"頭戴柚子皮的怪人"}));
        set("armor_prop/short",({"頭戴柚子皮的怪人(Strange man)"}));
set("armor_prop/long",({"一個頭戴柚子皮的人，你心裡不禁想起，是不是中秋節快到了。\n"}));
        setup();
} 
