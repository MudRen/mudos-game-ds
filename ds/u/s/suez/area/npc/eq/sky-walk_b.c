#include <armor.h>
inherit BOOTS;

void create()
{
set_name("空行靴",({"sky-walk boots","boots"}) );
set_weight(700);
        if( clonep() )
set_default_object(__FILE__);
        else {
set("long",
                "一雙漂亮的鞋子，淡藍的表皮，黑色的鞋底，金線繡的\n"
                "流雲紋輕輕的勾住了流過表面的微風。穿上它似乎覺得\n"
                "整個人神清氣爽，連腳步都輕快起來。\n");


set("material", "cloth");
set("unit", "雙");
set("value", 1500);

set("limit_level",10);
set("armor_prop/armor", 3);
set("armor_prop/shield", 2);
set("armor_prop/dex", 2);
set("armor_prop/int", -1);
set("armor_prop/dodge", 7);
        }
        setup();
}
