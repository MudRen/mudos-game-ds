#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name(HIR"�]��"HIW"���M"NOR,({"blood flame","flame","fist"}));
        set("long",@LONG
�W�������g���F�c�ѧ�����A�ϱo�A�����N�]�H�����ɡC
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",50);
        set("limit_level",26);
        set("unit", "��");        
        set("value",50000);
        set("volume",2);        
        set("material","steel");       
              }        
        set("weapon_prop/con",1);
        set("weapon_prop/int",-2);
        init_fist(60);
        setup();
}    

