#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
  set_name(MAG"����u"NOR, ({ "chimera boots","boots" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�]�~  �_���Ԫ��e�}�s�����u�l�A�u�l�e���Q���W�[�F���ֶˮ`�O�C\n");
    set("unit", "��");
    set("material","fur");
    set("value",8000);
// 2003.3.30 �s�W lv���� by ksj
    set("limit_lv",35);
    set("armor_prop/dex",1);
    set("armor_prop/con",1);
    set("armor_prop/damage",5);
    set("armor_prop/shield",3);
    set("armor_prop/armor", 8);
  }
  setup();
}
