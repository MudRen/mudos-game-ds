#include <weapon.h>


inherit GUN;

void create()
{
set_name("�F�z���N",({"engel gun","gun"}));
set("long","�o�O�@��F�z���N�A�����ԧB�H�ҷR�Ϊ��Z���C\n");
set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",380);
                set("rigidity",500);    
                set("material","iron");
                set("limit_int",8);
                set("limit_dex",7);
                set("limit_str",2);
        }



        set("bullet_type","small");     
        set("max_load",5);              
        init_gun(10);  
        setup();
}

