inherit ROOM;
void create()
{
    set("short","諸神塔第二層");
    set("long",@long
這座高聳入雲的巨塔就是傳說中遠古諸神所建造的「諸神塔」。
由於諸神之力的影響，這座巨塔能夠通到神境每個地方，而現在所在
的位置是諸神塔的第二層，走下樓梯可以通道第一層。此層分達四界
，天界、仙界、冥界、魔界，北邊則是四界之中族王與眾長老們開會
所使用的會議室。
long);
    set("exits",([
    "down" : __DIR__"ladder-1",
    "northeast" : __DIR__"flag_faerie",
  "up" : __DIR__"bank", 
  "north" : __DIR__"eldership", 
    "southwest" : __DIR__"flag_dark",
    "southeast" : __DIR__"flag_devilrom",
    "northwest" : __DIR__"flag_heaven",
]));
    set("objects",([
    __DIR__"shopman":1,
]));
    set("light",1);
    setup();
        set("stroom", 1);
}
