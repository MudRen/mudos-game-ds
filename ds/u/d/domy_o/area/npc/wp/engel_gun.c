#include <weapon.h>


inherit GUN;

void create()
{
set_name("沙漠之鷹",({"engel gun","gun"}));
set("long","這是一把沙漠之鷹，為阿拉伯人所愛用的武器。\n");
set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
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

