#include <armor.h> 
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIG"翠玉班指"NOR, ({ "green ring","ring" }) );
        set("long","一只很漂亮的戒指，你可以試著配戴看看。\n");
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "只");
        set("material", "jade");
        set("armor_prop/str",1);
        set("wear_msg",HIG"$N戴上了這只翠玉班指, 頓時感覺到一股很大的力量。"NOR);
        }
        setup();
}

