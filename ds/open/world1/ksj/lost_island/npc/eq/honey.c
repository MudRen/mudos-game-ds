#include <ansi.h>
#include <path.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(HIY"���e"NOR, ({"honey"}) );
  set("long", 
"�@���b���T�����s�A���e�A���o�@�@���᭻�C\n"
);
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("volume",1);
    set("value",50);
    set("food_remaining",1);
    set("heal_hp",30);  
    set("heal_ap",30);  
    set("heal_mp",30);  
    set("eat_msg","$N�Y�U�@�����������e�C");
    set("eff_msg",HIG "�Aı�o���e���Pı�R���b�f�Ĥ��A�O�A�^���L�a�C" NOR );
  }
  setup(); 
}
