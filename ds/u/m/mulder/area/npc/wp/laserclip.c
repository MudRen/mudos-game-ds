//bag.c by luky
inherit ITEM;
#include <ansi.h>
inherit F_BULLET;
void create()
{

set_name(HIG"激光槍能源夾"NOR,({"laser clip","laser","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","這是激光槍的能源。裝填指令:(reload clip)\n");
        }
set("value", 400);
set_weight(1220);
set("amount",10);		//彈藥量
set("bullet/damage",35);	//殺傷力
set("bullet/unit","束");	//彈藥單位
set("bullet/name","激光");	//彈藥名稱
set("type","laser");		//子彈型式
setup();
}

