#include <ansi.h>
#include <armor.h>
inherit WRISTS;
void create()
{
        set_name(HIW"�M����"NOR,({"white wrists","wrists"}) );
        set("long",@LONG
�A�����ݤ��X�ӳo�O�������A�w�n�����ܡA�j���O�����@�����a�I
�O�A�岧���O����Ĳ�P�A�J���B�X......
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",20);
                set("unit", "��");
                set("light",1);       
                set("value",10700);          
                set("volume", 4);                       
                set("material", "silk");   
        }
        set("armor_prop/armor",7);  
set("armor_prop/wit",1);
        set("armor_prop/dex",2);
        set("armor_prop/str",2);
        setup();
}

