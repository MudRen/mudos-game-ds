#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
  set_name(HIB"�s�l"NOR ,({ "dragon wing","wing" }) );
  set("long","�o�O�@���`�Ŧ⪺���j�e�H�A�O�q�l�u�s���W���U�v�s�Ӧ��A�軴�@�ΡC");
  set_weight(1200);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "��");
    set("value",2000);
  }
  set("limit_con",15);
  set("armor_prop/armor",13);
  set("armor_prop/con",1);
  set("armor_prop/dodge",10); //10->6 by ksj
  set("beast_armor_prop/armor",13);
  set("beast_armor_prop/con",1);
  set("beast_armor_prop/dodge",10);
  setup();
}
