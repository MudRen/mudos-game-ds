#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
        set_name(HIC"�����@��"NOR,({"jade-toad wrists","wrists"}) );
        set("long",@LONG
�@�����Ŧ���ֻs������M�A�ݰ_���Z�n�ݪ��C
LONG
);
        set_weight(600); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");       
                set("value",5000);          
                set("volume", 2);                       
                set("material", "fur");   
        }
        set("armor_prop/armor",2);       
        set("armor_prop/int",2);
        set("armor_prop/shield",4);
        setup();
}
