#include <weapon.h>
inherit SWORD;

void create()
{
set_name("�Ѯv���C",({"peach sword","sword"}));
set("long","�o�O�@��D�h�ΨӨ���]���Ǫ����C�C\n");
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
		set("value",2000);
set("volume",2);
        }
init_sword(20);
set("weapon_prop/hit",5);
set("weapon_prop/int",2);
         setup();
} 
