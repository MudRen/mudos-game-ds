#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
  set_name(CYN"�v�z"NOR ,({ "uchimaha gloves","gloves" }) );
  set("long","�o�O�@�ӷ|�]�����u����M�A�ݰ_�Ӥ��O�Фh�����C");
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "skin");
    set("volume",2);
    set("unit", "��");
    set("value",2000);
  }
  set("armor_prop/armor",13);
  set("beast_armor_prop/armor",7);
  set("limit_con",12);
  setup();
}

