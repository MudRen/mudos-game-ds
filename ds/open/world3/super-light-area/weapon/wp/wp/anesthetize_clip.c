inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("麻痺彈",({"anesthetize clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "顆");
        set("long","一顆附有麻痺效果的子彈, 請使用reload填裝.\n");
        }
set("value", 50);
set_weight(1000);
set("amount",1);                //彈藥量
set("bullet/damage",20);        //殺傷力
set("bullet/unit","顆");        //彈藥單位
set("bullet/name","麻痺彈");      //彈藥名稱
set("type","small");            //子彈型式
setup();
}


