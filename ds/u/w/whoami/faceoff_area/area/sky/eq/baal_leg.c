#include <ansi.h>
#include <armor.h>
inherit LEGGING;
void create()
{
        set_name(MAG"�����H"NOR,({"baal leggings","leggings"}) );
        set("long",@LONG
�o���H�һᬰ�_��, �b�����U���|�Ϯg���~, ���b�·t
�B�o�|�L�L���o�X����....
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_dex",20);
                set("unit", "��");
                set("light",1);       
                set("value",1070);          
                set("volume", 4);                       
                set("material", "blacksteel");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/dex",1);
        set("armor_prop/int",-3);
        setup();
}

