#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(MAG"五頭龍"RED"護身符"NOR, ({"dark amulet","amulet" }) );
        set("long", "這是一個刻有黑暗之后塔克西絲徽記的五頭龍護身符。\n");
        set_weight(1900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個" );
                set("armor_prop/armor", 300);
                set("armor_prop/shield", 600);
        set("wear_msg",CYN"$N"CYN"將一件$n"CYN"掛在脖子上, 低聲的唸著讚頌黑暗之后的禱文。\n"NOR);
        set("unequip_msg",CYN"$N"CYN"將$n"CYN"由脖子上取下, 高聲的讚美黑暗之后的強大。\n"NOR);
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }
