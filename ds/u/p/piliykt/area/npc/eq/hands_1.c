#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
        set_name(HIR"����@��"NOR ,({"phoenix hands","hands"}) );
        set("long",@LONG
����@��,�O����Ĩ��W���ͻH����,���פj�p��n�O�i�H���ӷ��@��.
�䨾�m�O��,�S���K.
LONG
);
        set_weight(1800); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_lv",15);
                set("unit", "��");       
                set("value",3600);          
                set("volume", 6);                       
                set("material", "leather");   
        }
        set("armor_prop/armor",8);       
        set("armor_prop/str",2);
        set("armor_prop/dex",1);     
   setup();
}

