#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIC"���ֹu"NOR, ({ "boots" }) );
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�@�����Ŧ���ֻs�����u�l�A�ݰ_���Z�n�ݪ��C\n");
    set("unit", "��");
    set("material","fur");
    set("value",3000);
    set("armor_prop/dex",2);
    set("armor_prop/shield",1);
    set("armor_prop/armor", 6);
  }
  setup();
}
