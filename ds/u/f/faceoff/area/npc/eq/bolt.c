inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("弩箭",({"bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "隻");
        set("long","一隻柳木箭身的弩箭, 可以提供良好的射程與殺傷力, 請用reload 指令將它放上弩.\n");
        }
set("value", 50);
set_weight(1000);
set("amount",1);                //彈藥量
set("bullet/damage",13);        //殺傷力
set("bullet/unit","隻");        //彈藥單位
set("bullet/name","弩箭");      //彈藥名稱
set("type","small");            //子彈型式
setup();
}
