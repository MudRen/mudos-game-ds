#include <armor.h>
inherit LEGGING; 
void create()
{
  set_name( "�ªZ�H��" , ({"black leggings","leggings"}));
  set("long", @LONG 
�o�O�@��¨I�I���H�ҡA�ϥΤ@��j�������K�����A�u�H�ͤ���ô�ۡC
LONG);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 1);
    set("value", 3000);
    set("material","iron");
  }
  set("limit_lv",20 );
  set("armor_prop/shield",10 );
  set("armor_prop/con", 1);
  setup();
}

