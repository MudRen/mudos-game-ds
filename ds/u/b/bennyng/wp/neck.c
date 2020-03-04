#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name("死神首飾", ({ "DeadGod","necklace" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","泛起黑氣的法術頸鍊,\n"
                           "對法術的抵抗力有相當的威力,有相當的防禦力。\n");
                set("unit", "條");
                set("material", "carbon");
//              set("no_drop",1);
                set("no_sac",1);
                set("value",40000);
                set("armor_prop/wit",5);
                set("armor_prop/sou",3);
                set("armor_prop/int",3);
                set("armor_prop/shield",20);
                set("armor_prop/armor", 3);
        }
        setup();
}
int query_autoload() { return 1; }
