#include <weapon.h>;
#include <ansi.h>;

inherit WHIP;

void create()
{
        set_name(HIW"銀索"NOR,({ "yin-suo whip", "whip" }) );
        set_weight(2000);
                set("long", "一條白色綢帶，末端還系著一個金色的圓球。\n");
                set("unwield_msg",HIY"$N隨手一抖，將銀索放入懷中。\n"NOR);
                set("wield_msg",HIY"$N緩緩從懷中取出一團冰綃般的物事握在左手之上。\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "團");
                set("value", 2000);
                set("material", "gold");
        }

        init_whip(30);
        setup();
}

