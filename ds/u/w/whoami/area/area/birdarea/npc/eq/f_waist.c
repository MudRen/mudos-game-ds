#include <ansi.h>
#include <armor.h>
inherit WAIST; 
void create()
{
  set_name(YEL"����"NOR"�a",({"fox belt","belt"}));
  set("long", @LONG
�@���Ϊ��W�����ڰ��X�Ӫ�ô�a�A�򵳵����N�_�ӯu�O�ΪA�E��
�m�O�|�]�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",7+random(4)); 
  set("armor_prop/shield",7+random(4));
  set("armor_prop/dex",1);
  set("armor_prop/con",1);
  setup();
}

