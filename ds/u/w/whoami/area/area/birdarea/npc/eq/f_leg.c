#include <ansi.h>
#include <armor.h>
inherit LEGGING; 
void create()
{
  set_name(YEL"����"NOR"�H��",({"fox leggings","leggings"}));
  set("long", @LONG 
�@��Ϊ��W���Y���Y���X�Ӫ��H�ҡA�̵۪��W���}���������E��
�m�O�|�]�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",5000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",12+random(6)); 
  set("armor_prop/shield",1+random(4));
  set("armor_prop/dex",1);
  set("armor_prop/con",2); 
  set("armor_prop/int",-2);
  set("armor_prop/con",2);
  setup();
}

