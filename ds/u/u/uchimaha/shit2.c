#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(MAG"便便"NOR ,({ "shit" }) );
        set("long",HIC"這是由"HIW"白便便"NOR""HIC"所大出的便便, 還熱熱的呢。\n"NOR);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("no_sac",1);
        set("material", "peel");
        set("unit", "陀" );
                set("value",10);
        }
        set("armor_prop/armor", 1000);
        set("armor_prop/id",({"Shit Man"}));
        set("armor_prop/name",({"身上沾有便便的怪人"}));
        set("armor_prop/short",({"身上沾有便便的怪人(Shit Man)"}));
set("armor_prop/long",({"一個身上沾滿便便的怪人, 你不由的想要嘔吐。\n"}));
        setup();
} 

