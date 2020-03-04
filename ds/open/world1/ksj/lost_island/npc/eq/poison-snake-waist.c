#include <ansi.h>
#include <armor.h>
inherit WAIST;
void create()
{
  set_name(MAG"�G�r���a"NOR ,({ "poison-snake waist","waist" }) );
  set("long","�@������o�۴c�䪺�D�֡A���D���D�N�s�H�Y������C");
  set_weight(400);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "��");
    set("value",1000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/shield",1);
  set("armor_prop/dex",-1);
  set("armor_prop/con",-2);
  set("armor_prop/str",-1);
  set("armor_prop/int",-3); 
  set("armor_prop/bar",1);
  set("wear_msg",
      "$N�N�@��c�䪺$nô�b�y���A�y���y�x�����A�����O�q�ɼW�C\n"
       NOR);  setup();
  call_out("poison_by_waist", 30);
}

void poison_by_waist()
{
  object me = environment(this_object());
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/waist")==this_object() ) {
  me->apply_condition("poison", me->query_condition("poison")+(random(1)+1));
	me->receive_damage("hp", 35+random(50));
	// by alick
  message_vision(MAG"$N�o�X�@�}����r��A$n�l�J��ߨ��y��x��....\n"NOR, this_object(), me);
	}
  call_out("poison_by_waist", 35);
}
