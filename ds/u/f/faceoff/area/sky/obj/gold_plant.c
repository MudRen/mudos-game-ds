#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("金梠草", ({ "gold grass","grass" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("value", 0);
                set("long", "這是一種長生長在水中的水生植物, 是種珍貴的中藥藥材!");
                }
        setup();
}

