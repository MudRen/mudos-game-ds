#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
  set_name(HIG"�K��l�R�@"NOR , ({ "dance whip","whip" }) );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�j�ѥH�e���R�̡A�b�K���F�}�̤�]�p��A�ҥ��y���W�j���L�C\n");
    set("material", "sliver");
    set("value",1000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",3);
  }
        set("wield_msg",HIM"$N�H�������R����áA���_���@����w�w���ϰʡC\n"NOR);
        set("unwield_msg", HIC"$N��U���@��A���ۦb�@�W�����R���𮧮����p�ɡC\n"NOR);
  init_whip(77);
  setup();
}

