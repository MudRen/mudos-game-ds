#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
        set_name("������M",({"flame kill gloves","gloves"}) );
        set("long",@LONG
���⪺��M�A�W���ٱa���˹_�A�ϥήɥi�o�p�ߡC
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",20);
                set("unit", "��");       
                set("value",1200);          
                set("volume", 4);                       
                set("material", "steel");   
        }
        set("armor_prop/armor",4);       
        set("armor_prop/str",1);
        set("armor_prop/damage",2);
        set("armor_prop/bio",-1);
        set("armor_prop/wit",-1);
        setup();
}


