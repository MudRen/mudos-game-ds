#include <weapon.h>
inherit SWORD;
void create(){        set_name("小麥芽劍", ({"sexking sword","sword",}) );        
     set_weight(5);        
     if( clonep() )
                set_default_object(__FILE__);
        else {

     set("unit", "枝");                set("long",@LONG            這只不過是一枝小麥草的嫩芽罷了。LONG
        );

     set("volume",3);       set("value", 400);        set("material","iron");                set("sword",41);                
      }     
     set("wield_msg", "$N「哇咧」地一聲抽出一枝$n握在手中。\n");        set("unwield_msg", "$N將手中的$n摺一摺放入口袋裡。\n");        init_sword(300); 
     setup();
}

