#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("���q�H��",({"bo-ton leggings","leggings"}) );
        set("long",@LONG
�o�O�����ì諸�@�L�H�ҡA�q��¦p�J�ҡC
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_dex",20);
                set("unit", "��");       
                set("value",1070);          
                set("volume", 4);                       
                set("material", "steel");   
        }
        set("armor_prop/armor",4);       
        set("armor_prop/dex",1);
        set("armor_prop/int",-1);
        setup();
}


