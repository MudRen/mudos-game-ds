//u/c/chiaa/obj/eq/dark red_shield.c
#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(RED"�`������"NOR,({"dark red shield ","shield"}) );
        set("long","�H�ѵM�������p��,�y�L�[�u���y,�D�`��w\n");
        
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(4000);  
                set("limit_str",18);
                set("unit", "��");       
                set("value",5555);                                                     set("material", "diamond");   //�p��
                set("armor_prop/armor",25);     
                set("armor_prop/shield",16);   
       }
      set("weapon_prop/parry",15);        //�[ enable �ޯ�15
          setup();
}
