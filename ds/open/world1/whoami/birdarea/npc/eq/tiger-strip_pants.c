#include <ansi.h>
#include <armor.h>
inherit PANTS; 
void create()
{
  set_name(HIY"�꯾"NOR"����",({"tiger-strip pants","pants"}));
  set("long", @LONG  
�@�����ۦѪ괳�������ǡA�N�_�ӳn�������A�ӥB�٤Q�����O�x
�M�z��A���λ��A�o�]�@�w�O�����J���ǧ@���@�E
LONG);
  set_weight(1300);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",4);
    set("value",3400);
    set("material","fur");
  }
  set("limit_lv",28);
  set("armor_prop/armor",8); 
  set("armor_prop/shield",4);
  set("armor_prop/dex",1);
  set("armor_prop/int",1);
  set("armor_prop/con",1);
  setup();
}

