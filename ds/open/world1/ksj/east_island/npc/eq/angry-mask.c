#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name(RED"���㭱��"NOR,({"angry mask","mask"}) );
  set("long",@LONG
�H�c���y���s��������A����W�����������N��o�Y�����g�O���O�j
�j�����Ҧ��C
LONG);
  set_weight(900); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",50);
    set("limit_lv",40);
    set("unit", "�i");       
    set("value",7000);          
    set("volume", 1);                       
    set("material", "gold");   
  }
  set("armor_prop/armor",5);
  set("armor_prop/int",-1);
  set("armor_prop/str",1);
  set("armor_prop/con",1);
  set("armor_prop/wit",-1);
  set("armor_prop/bar",1);
  setup();
}
