//u/c/chiaa/obj/eq/light blue_shield.c
#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(HIB"���Ť���"NOR,({"light blue shield ","shield"}) );
        set("long","�H�ѵM�Φ����Ŧ��p��,�y�L�[�u���y,�D�`��w\n");
        
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(5000);  
                set("limit_str",18);
                set("unit", "��");       
                set("value",6666);                                                     set("material", "diamond");   //�p��
                set("armor_prop/armor",28);     
                set("armor_prop/shield",14);   
       }
      set("weapon_prop/parry",15);        //�[ enable �ޯ�15
          setup();
}
