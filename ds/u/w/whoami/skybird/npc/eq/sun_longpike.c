#include <weapon.h> 
#include <ansi.h>
inherit F_UNIQUE;
inherit FORK;
void create()
{
        set_name("長槍"HIY"射日"NOR,({"sun longpike","longpike","pike"}) );  
        set("long","李鎮遠的隨身武器，重達百斤，一般人連拿著走路都有困難，更別說\n"
                   "裝備成武器了但也正因為如此它殺傷力才會這麼驚人•\n");
          set_weight(23000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("replica_ob", __DIR__"steel_pike.c");
        set("unit","桿");
        set("value",8600);
        set("volume",4);
        set("material","iron");
        set("limit_str",95);
        set("limit_lv",45); 
        set("weapon_prop/str",4);
        set("weapon_prop/con",2); 
        set("weapon_prop/dex",-4);
        set("weapon_prop/bar",2); 
        set("weapon_prop/wit",-2);
        set("weapon_prop/dodge", -25); 
        set("weapon_prop/hit", -50);
        init_fork(89);
        }
        setup();
}

