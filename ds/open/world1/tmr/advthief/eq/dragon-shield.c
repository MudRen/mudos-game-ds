#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(HIG "�|�����s��" NOR,({"sea-dragon shield","shield"}));
  set("long", @LONG
�o�O�@���Τj�����K�t�X����������j�ޡA�W���e���|���y�C��
�������s�A�ҥH�S�٥|�����s�ޡA��a��w�L��C
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 4);
    set("value", 8000);
    set("material","iron");
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 5);
  set("armor_prop/con",1);
  set("armor_prop/dex",1);
  setup();
}

