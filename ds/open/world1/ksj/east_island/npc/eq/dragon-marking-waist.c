#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIY"�s���y�a"NOR ,({ "dragon marking waist","waist" }) );
  set("long",@LONG
�ѷ��a�B����´�����y�a�A�y�a�W�Ϊ��u¸�W�@�����F���{��������
�s�C
LONG);
  set_weight(1800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",2);
    set("unit", "��");
    set("value",10000);
  }
  set("limit_con",60);
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  set("armor_prop/con",2);
  set("armor_prop/tec",-1);
  set("armor_prop/bio",1);
  setup();
}
