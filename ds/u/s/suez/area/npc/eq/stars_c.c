#include <armor.h>

inherit CLOTH;

void create()
{
set_name("群星裹身",({"stars cloth","cloth"}) );

set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","黑色的質料上有著細微的破孔，銀白色的內裡由\n"
                "孔中散發出微弱的光芒，像極了充滿星星的夜空\n"
                "。聽說這種設計比全黑的夜行衣更不引人注目，\n"
                "使得大部分的盜賊都十分喜歡用它。"
);
set("material", "cloth");
set("unit", "件");
set("value",500);

set("armor_prop/armor", 5);
set("armor_prop/shield", 2);

        }
        setup();
}
