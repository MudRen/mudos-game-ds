inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("中型彈夾",({"middle clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","一個中型彈夾10發。裝填指令:(reload clip)\n");
        }
set("value", 40);
set_weight(1220);
set("amount",10);
set("bullet/damage",40);
set("bullet/unit","發");
set("bullet/name","子彈");
set("type","middle");
setup();
}

