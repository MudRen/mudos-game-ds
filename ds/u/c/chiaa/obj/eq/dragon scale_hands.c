//u/c/chiaa/obj/eq/dragon scale_hands.c
#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
    set_name(HIC"�s��"YEL"��M"NOR,({"dragon scale hands","hands"}) );
    set("long","�o�O���s������һs��,�۷�öQ.\n");
 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(400); 
                set("limit_str",20);
                set("unit", "��");       
                set("value",3000);          
                set("material", "scale"); //���
                set("armor_prop/armor",15); //���m15  
     
        }
        
      set("weapon_prop/parry",20);        //�[ enable �ޯ�20
        setup();
}
