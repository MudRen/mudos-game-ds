#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIW"白色之戀"NOR, ({ "Showing love", "showing", "love" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","Aring專用....:P \n");
                set("unit", "件");
                set("material", "unknown");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("value",1);
        }
        //============以下片段開放區域勿用, 否則會大混亂===============
        //==    若開放區域要寫此種偽裝eq , 必定要設為 Only One EQ    ==
        set("armor_prop/id",  ({"(Snowelf) "}));
        set("armor_prop/short",({HIC"雪兒"HIW"三世"NOR"(Snow elf)"NOR}));
        set("armor_prop/long", ({"龜派氣功 \n"}));
        //==============================================================
        set("armor_prop/armor", 120);
        setup();
}
int query_autoload() { return 1; }

