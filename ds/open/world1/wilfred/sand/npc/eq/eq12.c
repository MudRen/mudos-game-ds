#include <armor.h>
inherit ARMOR;
void create()
{
  set_name("�@����" ,({ "heart armor","armor" }) );
  set("long","�@���K�s����A�Υֱa�T�w�b���W�A�u�@��F�̭��n���ߤf�����A�]�����m�ĪG�����C");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "iron");
    set("volume",2);
    set("unit", "��");
    set("value",1000);
  }
  set("armor_prop/armor",12);
  setup();
}