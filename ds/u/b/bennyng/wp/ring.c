#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name("死神鑽戒", ({ "DeadGod","ring" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這是一隻閃閃的鑽石戒指,是所有少女發夢都想著的鑽戒,\n");
                set("unit", "隻");
                set("material", "carbon");
//              set("no_drop",1);
                set("no_sac",1);
                set("value",55000);
                set("armor_prop/sou",1);
                set("armor_prop/int",3);
                set("armor_prop/armor", 3);
                set("wear_msg","$N把這$n戴上,臉上露出邪惡的笑容!");
                set("remove_msg","$N除下了$n,想找個地方收藏..");
        }
        setup();
}
int query_autoload() { return 1; }
