#include <ansi.h>
#include <weapon.h>
inherit FORK;


void create()
{
  set_name(HIW"�ﰨ�j"NOR, ({ "dragon horse-spear","spear" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", HIW"�ݻa�ѱ���H���A�ݸU�������l�ɡA���H��ű���K�ҡA�j���ߦ����H���C\n"NOR);
    set("material", "iron");
    set("value",3000);
    set("volume",3);
    set("limit_int",15);
    set("weapon_prop/str",2); 
    set("weapon_prop/dex",1);
    set("weapon_prop/int",-3); 
 }
  init_fork(65);
  setup();
}

