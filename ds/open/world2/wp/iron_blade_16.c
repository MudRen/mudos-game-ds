#include <weapon.h>
inherit BLADE;

void create()
{
set_name("�u��M",({"short combat blade","blade"}));
	set_weight(4300);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
�o�O�@��x�����o���u��M�A���F���ĥ��n�ɤ]�ΨӦۦF�C
LONG);
		set("unit", "��");
		set("material","iron");
        }
 	init_blade(16);
	setup();
        set("value",1550);
        set("backstab_bonus",18);
}
int can_stab() { return 1; }
//int query_autoload() { return 1; }
