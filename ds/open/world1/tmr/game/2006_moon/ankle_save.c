#include <ansi.h>
#include <armor.h>
inherit ANKLE;

void create()
{
  set_name(HIY"�b��"HIW"�}��"NOR ,({ "run-moon ankle","ankle" }) );
  set("long","�o�O�@����a�ǲ����}��A��b�}��W�A�n���ٺ��Ӯ𪺡C\n�i2006����`�b�묡��-�o�����~�j");
  set_weight(1800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "��");
    set("value",0);
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);

  }
  set("armor_prop/armor",5);
  set("armor_prop/shield",5);
  set("armor_prop/str",1);
  set("armor_prop/con",1);
  set("armor_prop/int",1);
  set("armor_prop/dex",1);
   set("armor_prop/show_damage",1);
  setup();
}

int query_autoload() { return 1; }


