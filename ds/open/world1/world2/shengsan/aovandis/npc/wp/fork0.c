#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
    set_name("���Ƥe",({"steak fork","fork"}));
    set("long","�o��e�l�O���ÿ������A���M�ܤp���O�ΨӤe�H�]�O���h���C\n");
    set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "��");
          set("material","steel");
        }
        set("value",210);
        set("weapon_prop/hit",5);
        init_fork(4);
        setup();

}
//�i�ΨӭI��
int can_stab()
{
	return 1; 
} 
