#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
  set_name(MAG"�W�a�S�����D�@"NOR , ({ "snake whip","whip" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@�ⴭ�a���a���@�l�A�@���S���٦��@�ɲɪ���A�O���������d��[\n"
        "���A�٨㦳�B�~�����ˤO�C\n");
    set("material", "silver");
    set("value",4700);
    set("weapon_prop/str",1);
  }
  init_whip(35);
  setup();
}

