#include <weapon.h>
#include <ansi.h>
inherit GUN; 
void create()
{
set_name("紫煌定風弓",({"purple-bow","bow"}));
set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
繼紫煌定風劍後，竭達羅又打造一把舉世無雙的弓，乃是取自十萬
大山的靈鳥骨所製。 
LONG);
                set("unit", "把");
                set("rigidity",200);    
                set("material","gold");
                set("limit_int",30);
                set("limit_dex",40);
                set("limit_str",35); 
        }
        set("bullet_type","small");     
        set("max_load",3);              
        init_gun(40);   
        setup();
        set("value",20000); 
}

