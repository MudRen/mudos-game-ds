#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create() {
        set_name("�����", ({ "steel staff", "staff"}) ) ;
                set("long",@LONG
����ҥ��y���I���A���R�_�Ӫ��ͭ��A�S���@�w����O
�O�L�k�ϥΪ��C
LONG
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_skill",30);
        set("unit", "��");        
        set("value",1000);
        set("volume",5);        
        set("material","steel"); 
              }        
        set("weapon_prop/int",2);
        init_staff(52);
        setup();
}
