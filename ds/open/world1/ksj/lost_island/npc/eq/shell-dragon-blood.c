#include <ansi.h>
#include <path.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(RED"�K�s��"NOR, ({"shell dragon blood","blood"}) );
  set("long", 
"��I�K�s������A����o�X�S�⪺����C\n"
);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("volume",10);
    set("value",600);
    set("food_remaining",1);
    set("heal_hp",1000);  
    set("heal_ap",300);  
    set("heal_mp",300);  
    set("eat_msg","$N�Y�U�@���u�S������C");
    set("eff_msg",HIG "�Aı�o���@�Ѽ��y�q�����X����|�ϡA�y�ɯ��M��n�A��O�R�K�C" NOR );
  }
  setup(); 
}
