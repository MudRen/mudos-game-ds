#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(HIW"�ʤb�ý�"NOR,({ "blade wrists","wrists" }) );
  set("long",@LONG
�γ\�h���M���s���Ӧ����åҡA�s�@���覡�D�`�����ө_�S�A�U�Q��
�M���|�b�����ɦP�ɱ��˹��C
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1000);
    set("material", "steel");
    set("unit", "��");
    set("value",3000);
    set("volume",2);
  }
  set("armor_prop/armor", 8);
  set("armor_prop/damage",5);
  set("limit_con",20);
  set("limit_int",20);
  setup();
}
