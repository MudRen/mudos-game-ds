//u/c/chiaa/obj/eq/amber_ring.c
#include <ansi.h>
#include <armor.h>
inherit FINGER;  //�������

void create()
{
        set_name(HIY"�[��"CYN"�٫�"NOR,({"amber ring","ring"}) );
        set("long","�H�öQ���ѵM�q�۵[�ĩҰ����٫�,���۲H���⪺���A�C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(355); 
                set("unit", "�u");       
                set("value",1500);                             
                set("material", "amber");   //�[��
                set("armor_prop/armor",6);             
                set("armor_prop/int",1);
        }
        
        setup();
}
