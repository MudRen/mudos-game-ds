#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
  set_name(HIR"�t��"HIW"��M"NOR ,({ "christmas gloves","gloves" }) );
  set("long",@LONG
�o�O�@���j�j���զ��M�A���b��̳��M���ة��ַP�A�A�y�W�S�X�L�L�����A
�W�Q�n���W�o����M�C
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "fur");
    set("volume",1);
    set("unit", "��");
    set("value",1);
  }
  set("armor_prop/armor",1);
  setup();
}

