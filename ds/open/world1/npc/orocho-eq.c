#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
          set_name(GRN"八歧"RED"•"HIY"龍眠"NOR,({"orochi armor","armor"}) );
        set("long",@long
有點極度的終極裝備。[Save EQ]
long
);
        set_weight(10000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",3);
                set("unit", "件");
                set("value",100000);
                set("max_lv",100); 
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("limit_lv",50);
        } 
                set("armor_prop/armor",40);
                set("armor_prop/show_damage",1);
        setup();
} 
int query_autoload() { return 1; }

