#include <ansi.h>
#include <armor.h>
inherit WRISTS;
void create()
{
        set_name(HIW"�M�ɵ�"NOR,({"white wrists","wrists"}) );
        set("long",@LONG
�o�O�ѥ��K�һs�����@�áA�ݨӬ۷���.
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",20);
                set("unit", "��");
                set("light",1);       
                set("value",1070);          
                set("volume", 4);                       
                set("material", "jade");   
        }
        set("armor_prop/armor",6);       
        set("armor_prop/dex",2);
        setup();
}
