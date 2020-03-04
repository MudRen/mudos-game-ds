inherit ROOM;
void create()
{
    set("short", "皴玉古城北街");
        set("long", @LONG
    兩旁的山壁依舊高聳，讓這裡在白天時也是陰暗潮濕。山壁上的小洞
中放了一盞盞油燈，由於這裡的風似乎強了不少，所以油燈的火焰被吹的
搖晃不定，路上車馬的影子也不停的搖晃，映照在山壁上拉長的影子好似
鬼魅一樣緊跟著你，一股陰森森的感覺直上心頭，你的腳步愈走愈快了。

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_6",
	"north" : __DIR__"map_2_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

