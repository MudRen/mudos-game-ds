inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("楊威利槍彈夾",({"super morral clip","morral","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","一個金屬製的彈夾, 每一組彈夾出廠時都裝有500發子彈。裝填指令
:reload clip");
        }
set("value", 6000);
set_weight(1220);
set("amount",500);
set("bullet/damage",220000);
set("bullet/unit","砲");
set("bullet/name","神之彈");
set("type","super-big");
setup();
}
