#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name(HIY"��"HIM"��"HIW"�y"HIC"�a"NOR,({"dreamcast waist","waist"}) );
        set("long",@LONG
�o�O�@�����Ӱ����y�a�E
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",15);
                set("unit", "��");       
                set("value",1500);          
                set("volume", 3);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/con",2);
        setup();
}
