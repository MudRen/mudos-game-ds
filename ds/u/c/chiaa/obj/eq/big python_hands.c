//u/c/chiaa/obj/eq/big python_hands.c
#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
    set_name(CYN"����"YEL"��M"NOR,({"big python hands","hands"}) );
    set("long","�o�O�Υ��j���D���D�֩һs��.\n");
 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(200); 
                set("limit_str",15);
                set("unit", "��");       
                set("value",1500);          
                set("material", "python"); //���D
                set("armor_prop/armor",8); //���m8    
                set("armor_prop/str",1);   //�O�q+1
        }
        
      set("weapon_prop/parry",10);        //�[ enable �ޯ�10
        setup();
}
