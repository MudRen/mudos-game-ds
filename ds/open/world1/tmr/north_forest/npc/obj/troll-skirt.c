#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name(HBK "暗矛巨魔毛裙" NOR,({ "anmao-troll skirt","skirt" }) );
        set("long",@LONG
在約二百年前，森金率領暗矛部落在大漩渦附近的島嶼定居，暗矛
部落人人都是穿著這種毛裙，除了舒服保暖之外，在戰爭連連的那
個時期，這毛裙相當耐穿，不容易磨損。
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "條");
                set("value", 1200);
                // 女性專用
                set("female_only", 1);
        }
        set("armor_prop/armor", 5);
        set("armor_prop/shield", 5);
        set("armor_prop/str", 1);
        set("armor_prop/dex", 1);
        set("armor_prop/hit", 25);
        setup();
}


