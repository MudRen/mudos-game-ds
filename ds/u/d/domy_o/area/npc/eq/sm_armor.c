#include <weapon.h>
#include <ansi.h>

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
set_name(MAG"【SM專用】"HIW"鎧甲"NOR,({"sm armor","armor"}) );
set("long","這是一件SM專用的常見情趣裝，讓人興奮的好東西。\n");
set_weight(3100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "armor");
set("unit", "件");
set("value",1500);

set("wield_wear","$N穿上$n以後，便覺得自己很性感\n");

set("armor_prop/armor", 10);
set("armor_prop/shield", 3);

        }
        setup();
}

