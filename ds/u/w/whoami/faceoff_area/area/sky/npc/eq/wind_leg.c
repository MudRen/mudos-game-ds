#include <ansi.h>
#include <armor.h>
inherit LEGGING;
void create()
{
        set_name(CYN"�Э��H"NOR,({"wind leggings","leggings"}) );
        set("long",@LONG
�o�O�����t�D���@�L�A�ݨӨӾ����p...
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
                set("material", "blacksteel");   
        }
        set("armor_prop/armor",5);       
        set("armor_prop/dex",1);
        set("armor_prop/int",1);
        setup();
}

