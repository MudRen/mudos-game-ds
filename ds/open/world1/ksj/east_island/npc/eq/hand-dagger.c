#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name("�K��M", ({ "hand dagger","dagger" }) );
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�`");
    set("long", "�K�s���u�M���A�M�b���ݪ��K���¤M�I�s�����ΡA�ⴤ�ۥi�H�Ω�\n"
                "�񨭮氫�C\n");
    set("value",700);
    set("volume",2);
    set("material","steel");
  }
  init_dagger(15);
  setup();
}
