#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{
set_name("光子能",({"light-clip","clip"}) );
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","光子槍專用的彈藥");
        }
      set("value", 800);
   set_weight(1000);
set("amount",25);
  set("bullet/damage",50);        //武器威力
set("bullet/unit","束");
 set("bullet/name","光能");
set("type","light_clip");
setup();
}
