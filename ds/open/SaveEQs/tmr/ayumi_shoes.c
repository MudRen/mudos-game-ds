#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name(HIC"����"HIM"��"BLU"��"NOR ,({ "shadow-sky shoes","shoes" }) );
        set("long", @LONG
�@���ѫG�ȵ����]�Ъ������c�A�O�y��ХD�S�������Y���@�C

�P�E ayumi ��DS�������^�m�C -Tmr 2007/04/08
LONG
);
  set_weight(200);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("unit", "��");
    set("volume",1);
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
  set("armor_prop/armor", 5);
  set("armor_prop/shield",5);
  set("armor_prop/bar",1);
  set("armor_prop/show_damage",1);
  setup();
}

int query_autoload() { return 1; }



