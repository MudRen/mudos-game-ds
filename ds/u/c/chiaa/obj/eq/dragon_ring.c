//u/c/chiaa/obj/eq/dragon_ring.c
#include <ansi.h>
#include <armor.h>
inherit FINGER;  //�������

void create()
{
        set_name(HIC"�s"HIG"��"HIW"��"NOR,({"dragon ring","ring"}) );
        set("long","�@�u�ȥզ�A������,�W���٨�F�@���s�C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(300); 
                set("unit", "�u");       
                set("value",1200);                             
                set("material", "silver");   
                set("armor_prop/armor",10);       
                set("armor_prop/str",3);
                set("armor_prop/int",2);
        }
        
        setup();
}
