#include <weapon.h>
#include <ansi.h>
inherit SWORD;


void create()
{
set_name( MAG "�i���ѡj" NOR,({"In-Tan sword","sword"}));
set("long","��~���y���мC�ɡA���C�����n���@��A���W���i���ѡj�C\n");
set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",30000);
set("material","iron");
        }
init_sword(100);
set("weapon_prop/dex",100);
set("weapon_prop/str",100);
set("weapon_prop/con",100);
set("weapon_prop/int",100);
set("weapon_prop/hungchen-sword",50);
set("weapon_prop/parry",100);
set("weapon_prop/dodge",100);
set("weapon_prop/damage", 170);
        setup();
}
