#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(HIM"��"HIY"�[��"HIR"�Z"NOR ,({ "fan-light armor","armor" }) );
  set("long",@LONG
�o�O�@��x�ۯ[���⪺���ҡA���b��W�����A�i�O�o���m�j�j��
�j�����A�ӥB�۵M�o�X�X���A���H�@�ѹ��R���O�q�A�֦������H�w
�ߪ��𮧡A�þ֦��@�i�i���𮧴�X�C
LONG
);
  set_weight(8500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "��");
    set("value",50);
  }
  set("limit_level",25);
  set("armor_prop/armor",150);
  set("armor_prop/con",20);
  set("armor_prop/dex",20);
  set("armor_prop/bar",2);
  set("armor_prop/sou",2);
  set("armor_prop/dodge",30);
  set("armor_prop/int",20); 
  set("armor_prop/hit",50);
  set("armor_prop/str",20);
  set("armor_prop/show_damage",1);
  set("armor_prop/bio",3);  
  setup();
  this_object()->start_light(1);
}
int query_autoload() { return 1; }


