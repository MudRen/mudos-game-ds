#include <ansi.h>
#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create() {
        set_name( "�����z��" ,({"liyuan claw","claw"}));
        set("long",@LONG
�����z���O�T�~�P���~�~�F�θ��������R�ΪZ���A���W�観
�@�ƴç����ϼˡA�㪺���I�޲��C
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",10);
                set("unit", "��");        
                set("value", 3000);
                set("volume",2);        
                set("material","ivory");       
        }        
        set("weapon_prop/int", 1);
        set("weapon_prop/con", 1);
        init_fist(40);
        setup();
}    

