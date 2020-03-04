//bag.c by luky
inherit ITEM;
inherit F_BULLET;
void create()
{
set_name("三厘米子彈彈夾",({"bullet-3mm clip","bullet","clip"}));
        set_weight(900);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("material", "iron");
        set("long",@LONG
一個金屬製的彈夾, 每一組彈夾出廠時都裝有八發子彈。
裝填指令:(reload clip)
LONG);
        }
set("amount",8);		//彈藥量
set("bullet/damage",22);	//殺傷力
set("bullet/unit","發");	//彈藥單位
set("bullet/name","三厘米子彈");	//彈藥名稱
set("type","small");		//子彈型式
setup();
set("value", 400);
}

