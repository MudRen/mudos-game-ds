//u/c/chiaa/obj/eq/leading_cloak.c
#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
   set_name(RED"�Q"HIB"��"MAG"�ܭ�"NOR,({"leading cloak","cloak"}) );
   set("long","�Q����d���H�����ܭ�,�o�O�۷����o���@���_��.\n");
  
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(9500);
                set("material", "fell");  //�~��
                set("unit", "��");
                set("limit_con",15);                    
                set("armor_prop/dodge", 20);
                set("armor_prop/armor", 30);
                set("armor_prop/shield",15);
                set("value",12215);
        }
      set("weapon_prop/parry",30);        //�[ enable �ޯ�30
        setup();
}

