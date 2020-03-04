#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(GRN"�K�["HIW"��a"NOR,({"orochi waist","waist"}));
  set("long", @LONG
�K�[�j�D����ֻs�����y�a�A���@�ΤM�j���J�C
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",2);
    set("value",5000);
    set("material","fur");
  }
  set("limit_lv",35);
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  set("armor_prop/str",1);
  set("armor_prop/con",2);
  set("armor_prop/int",1);
  setup();
}
