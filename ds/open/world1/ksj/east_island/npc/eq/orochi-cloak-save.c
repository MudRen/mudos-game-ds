#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
   set_name(HIR"�u"HIW"�E"NOR"�K�["MAG"���"NOR,({"orochi cloak","cloak"}));
  set("long", @LONG
�K�[�j�D���I��s�����ܭ��A�ܭ��W�ٱa���@�ƭI��A���ܭ��{ģ
�۲`�񪺨����C
LONG);
  set_weight(1300);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",7000);
    set("material","fur");
  }
  set("limit_lv",40);
  set("armor_prop/armor",20);
  set("armor_prop/shield",20);
  setup();
}

int query_autoload() { return 1; }
