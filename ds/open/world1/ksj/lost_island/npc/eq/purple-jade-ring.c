#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(MAG"���ɧ�"NOR,({"purple-jade ring","ring"}) );
  set("long",@LONG
�@�T���⪺�j�١A�W����۬ݤ�������r�A�x�۷ż����A�C
LONG
);
  set_weight(300); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("unit", "�u");       
    set("value",30000);          
    set("volume", 2);                       
    set("material", "stone");   
  }
// 2003.3.30 �s�W lv���� by ksj
  set("limit_lv",35);
  set("armor_prop/armor",1);       
  set("armor_prop/int",2);
  set("armor_prop/con",2);
  set("armor_prop/hit",5);
  setup();
}
