#include <weapon.h>
inherit BLADE; 
#include <ansi.h>
void create()
{
  set_name( HIM"��"HIR"�s"HIY"�z"HIC"��"BLU"��"RED"�P"HIW"�M"NOR , ({ "Dreamcast blade","blade" }) );
  set_weight(1800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
set("long","�o�ODreamcast�̷R���_�M�E");
    set("material", "iron");
    set("value",1200);
    set("volume",1);
  }
  init_blade(1000);
  setup();
}

