#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name("��������",({"mica shield","shield"}) );
        set("long",@LONG
�ѵM�����Φ����޵P�A�������g�L�H�u���y�A�i�H��ܳ������k�N��
�O�A�����۪��ϳ��O�q�O�ܱj�j���C
LONG
);
        set_weight(3000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",20);
                set("unit", "��");       
                set("value",1200);          
                set("volume", 4);                       
                set("material", "mica");   
        }
        set("armor_prop/armor",20);     
        set("armor_prop/shield",14);   
        setup();
}


