//聖誕活動第二名 婷婷(tintin) 禮物 -by tmr-

#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name(HIW "白色長裙" NOR ,({ "tintin skirt","skirt" }) );
        set("long",
"聖誕活動第二名 婷婷所得獎的禮物。\n"
"一件純天蠶絲製的白色長裙，在日光照射下，約呈半透明狀。\n"
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "fur");
                set("unit", "件" );
                set("value",2500);
                set("valme",3);
                set("no_sac",1);
                  set("armor_prop/armor", 15);
                set("armor_prop/dex",1);
        }
        setup();
}

int query_autoload() { return 1; }
