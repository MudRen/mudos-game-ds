#include <weapon.h>

inherit GUN;
void create()
{
set_name("HANS自動手槍",({"hand gun","gun"}));
set("long","這是一把小型的射擊(shoot)武器, 一次可以裝填(reload)12發子彈。\n");
set_weight(4600);
        if( clonep() )
     set_default_object(__FILE__); 
     else {
                set("unit","把");
                set("value",1000);
                set("rigidity",1000);
                set("material","iron");
                set("limit_str",20);
          set("wield_msg","$N從口袋裡拿出一把$n, 並將$n的保險裝置解開。\n");
          set("unwield_msg", "$N將手中的$n保險裝置關閉, 插回槍帶中。\n");  
          set("bullet_type","small");
          set("max_load",12);
          init_gun(13); 
          setup();
}  
}
