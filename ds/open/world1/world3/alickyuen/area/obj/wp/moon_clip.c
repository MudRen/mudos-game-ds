#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{
        set_name(HIY"彈夾"NOR,({"clip"}));
        set("long",@long
是一個金屬製的彈夾,上寫著【月影】二字,每一組彈夾都裝有25發子彈。
long
);
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "個");
          set("value", 1000);
        set("material","gold");
        set("amount",25);                //彈藥量
        set("bullet/damage",50);        //殺傷力
        set("bullet/unit","發");        //彈藥單位
        set("bullet/name","子彈");      //彈藥名稱
        set("type","moon_clip");            //子彈型式
        }
        setup();
}

