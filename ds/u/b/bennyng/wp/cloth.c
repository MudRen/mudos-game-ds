#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("死神戰衣", ({ "DeadGod","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","武林中人一直想要的戰衣，世上只有一件。\n");
                set("unit", "件");
                set("material", "cloth");
//              set("no_drop",1);
                set("no_sac",1);
                set("value",20000);
                set("armor_prop/parry",1);
                set("armor_prop/armor",5);
        }
        setup();
}
int query_autoload() { return 1; }
