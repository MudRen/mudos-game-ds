#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
    set_name(HIR"�u"HIW"�E"NOR"�K�["HIW"��a"NOR,({"orochi waist","waist"}));
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
  setup();
}

int query_autoload() { return 1; }
