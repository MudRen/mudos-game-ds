// shop改自herb.c
// Luky 1999.1.9修改
inherit ROOM;
void create()
{
set("short","[1;35m愛爾裝備交換中心[m");
set("long",@LONG
你走進這裡發覺來到一間專門買賣裝備的商店，你看到
四週掛滿了各式各樣的盾牌和長劍等裝備，旁邊的玻璃櫃則
放了些盔甲和服裝，牆上貼了張注意事項(Sign)。
LONG
);
 set("light",1);
 set("storeroom",__DIR__"temp/shop");//此路徑最好打相對的喔
 set("exits",([
 "south" : __DIR__"pearl_16",
 ]));
 set("item_desc",([
 "sign":"暫停營業中。\n"
]));
setup();
}
