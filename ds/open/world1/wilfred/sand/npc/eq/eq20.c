#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIW"�p���s��"NOR ,({ "dragon scale","scale" }) );
  set("long","�@��������z������A���a�Ƭ���w�A�����@�h�m���y��ۡC");
  set_weight(600);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "diamond");
    set("volume",3);
    set("unit", "��");
    set("value",3800);
  }
  set("limit_int",10);
  set("armor_prop/armor",3);
  set("armor_prop/dex",3);
  set("armor_prop/dodge",3); // 5->3 by ksj
  set("beast_armor_prop/armor",3);
  set("beast_armor_prop/dex",3);
  set("beast_armor_prop/dodge",10); // 5->10 by ksj
  setup();
}
