#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
  set_name( "�v��̳n�@", ({ "sun-follow whip","whip"}) );
    set("long", "�v��̳n�@�O���q��ȥժ��@�l�A�O�ΫD�`�S������Ұ������A��a�D�`���աC");
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "iron");
    set("value", 1500);
  }
  init_whip(35);
  setup();
}


