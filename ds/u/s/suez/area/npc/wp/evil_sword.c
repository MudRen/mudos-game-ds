
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name("������C" ,({ "evil sword","sword" }) );
        set("long","�o�O�@�ⴶ�q�����C�A���O�W�����G�g�V�F���֨���C\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","iron");
        }
        set("unit", "��" );
         set("value",3250);
       set("weapon_prop/shield", 3);
        setup();
init_sword(20);
}
