#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
        set_name("鬼頭長劍",({"ghost-head sword","sword"}));
        set("long",@LONG
劍把的末端鑲著一顆詭異的鬼頭，劍身上閃著凜凜劍光，看起來鋒利
無比，用起來可得小心。
LONG
);
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");        
        set("value",500);
        set("volume",2);        
        set("material","iron");       
              }        
        set("weapon_prop/str",1);
        init_sword(30);
        setup();
}    
