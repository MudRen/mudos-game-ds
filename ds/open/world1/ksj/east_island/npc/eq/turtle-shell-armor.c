#include <armor.h>
inherit ARMOR;

void create()
{
  set_name("�t�ߥ�",({ "turtle-shell armor","armor" }) );
  set("long",@LONG
���j���Q�t�ŴߡA��n�i�H���H�M�i�h�A���L�ݰ_�Өä��n�ݴN�O�F
�C
LONG);
  set_weight(4500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",4);
    set("unit", "��");
    set("value",1000);
  }
  set("armor_prop/armor",17);
  set("armor_prop/dodge",-4);
  setup();
}
