//updated 27/12
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("掌心雷彈夾",({"bullet clip","bullet","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","一個金屬製的彈夾, 每一組彈夾出廠時都裝有5發子彈。\n");
        }
set("value", 60);
set_weight(1500);
set("amount",5);		//彈藥量
set("bullet/damage",130);	//殺傷力
set("bullet/unit","發");	//彈藥單位
set("bullet/name","子彈");	//彈藥名稱
set("type","small");		//子彈型式
setup();
}

