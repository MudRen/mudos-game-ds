#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIY"��������"NOR,({"gold earring","earring"}));
  set("long", @LONG
�ª��s���������A�{ģ�O�H�I�K�������C
LONG
);
  set_weight(400);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",1);
    set("value",1920);
    set("material","gold");
  }
  set("armor_prop/armor",1);
  setup();
}
