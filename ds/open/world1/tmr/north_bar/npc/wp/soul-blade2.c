#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("����M", ({ "soul-evil blade","blade" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�o�O�@�����æb�v����餺�����M�A���a���@�٦�������A�A���Ѩ��c���𮧡C\n");
                set("volume",10);
                set("value", 8000);
                set("material","iron");
	  }
      set("limit_skill", 40);
      set("weapon_prop/str", 1);
      set("weapon_prop/con", 1);
      init_blade(50);
      setup();
}

