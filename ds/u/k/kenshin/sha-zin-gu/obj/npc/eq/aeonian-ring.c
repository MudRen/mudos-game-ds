#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(HIW"千古玉戒"NOR ,({ "aeonian ring","ring" }) );
        set("long",@LONG
流傳千年的一只戒指，據說含有玉帝之神力。
LONG);
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",1);
                set("unit", "對");
                set("value",3000);
        }
        set("wear_msg",HIG"$N戴上千古玉戒後，突然數道從天而降的光芒降落在$N中!!"NOR);
        switch(random(3))
        {
        case 0:        
                set("armor_prop/con",2);
                set("armor_prop/str",4);
                set("armor_prop/bar",1); 
                set("armor_prop/armor",7);
        break;
        case 1:
                set("armor_prop/dex",2);
                set("armor_prop/int",1);
                set("armor_prop/tec",1); 
                set("armor_prop/armor",3);
        break;
        case 2:
                set("armor_prop/int",-1);
                set("armor_prop/str",-1);
                set("armor_prop/dex",-1);
                set("armor_prop/con",-1);
                set("armor_prop/bar",-1);
                set("armor_prop/tec",-1);
                set("armor_prop/armor",-4);
        break;
        }
        setup();
}


