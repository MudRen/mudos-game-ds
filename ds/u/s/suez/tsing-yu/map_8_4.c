inherit ROOM;
void create()
{
	set("short", "當鋪");
        set("long", @LONG
    小小的一間當鋪中。擺滿了各式各樣的東西。在這裡連走個路都不方
便。看這些典當的東西，你發現這裡的主人似乎很用心的照顧著，一點灰
塵也沒有，雖然擁擠但是仍然整理的井然有序，難怪大家都放心把東西典
當在這裡。

LONG
);
	set("exits",([
	"north" : __DIR__"map_7_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

