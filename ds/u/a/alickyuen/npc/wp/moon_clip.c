#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{
set_name(HIY"彈夾"NOR,({"moon_clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","是一個金屬製的彈夾,上寫著【月影】二字,\n
          每一組彈夾都裝有25發子彈。\n");
        }
set("value", 30000);
set_weight(1220);
set("amount",25);                //彈藥量
set("bullet/damage",100);        //殺傷力
set("bullet/unit","發");        //彈藥單位
set("bullet/name","子彈");      //彈藥名稱
set("type","moon_clip");            //子彈型式
setup();
}
