#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("佛跳牆(buddha's favorite stock) [誠意 %d 份]",query("time") );
}

void create()
{
        set_name(HIM"佛"HIC"跳"HIY"牆"NOR,({"buddha's favorite stock", "stock", "_GHOST_STOCK_", "_GHOST_STOCK2_"}) );
        set("long",@LONG
這鍋佛跳牆是以整只鮑魚、日本花蘑菇、海黃瓜、干扇貝、烏骨雞、
湖南火腿、人參等原料煮成，連和尚都抗拒不了這垂涎三尺的香味，
跳過圍牆也要喝上一口。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","份");
        }
        set("value", 100);
        set("time", 5000);
    
        setup();
        set("long", query("long") + getLong() );
}

