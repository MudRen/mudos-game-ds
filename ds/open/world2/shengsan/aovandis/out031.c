// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "郊區農田");
	set("long", @LONG
這裡的農田有點小，不過夜間仍然會有青蛙呱呱呱的叫聲從田間傳來
，幾株棕梠樹被種植在農田旁邊，清風把棕梠樹輕輕的吹著，樹葉間摩擦
出沙沙的聲音。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out032",
	    "north": __DIR__"out024",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}