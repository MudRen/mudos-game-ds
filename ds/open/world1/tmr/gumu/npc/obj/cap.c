#include <armor.h>
inherit HEAD;
void create()
{
  set_name("�D�a",({"taoist cap","cap"}));
  set("long", @LONG
�o�O�@���D�h�b�����D�a�C
LONG);
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value", 200);
    set("material","fur");
  }
  set("armor_prop/armor",  3);
  set("armor_prop/shield", 5); 
  setup();
}

