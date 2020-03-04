#include <ansi.h>
inherit MOBROOM;
void create()
{
	set("short","第二碼頭");
	set("long",@LONG
這裡是第二碼頭的底端，通常不會有什麼人來。以前雖然是沒什麼問
題，但是隨著薩爾薩斯的發展，出入的人也愈來愈複雜，有一些素行不良
的人就聚集在此，成為薩爾薩斯的犯罪滋生地。不過上次一些船家受不了
那些人老是破壞他們的貨物，請了幾名冒險者來「清掃」一下。目前這裡
只剩下雜亂的痕跡而已。
LONG 
);
	set("exits",([
	    "east":__DIR__"port_17",
		]));

	set("world","world1");
	set("outdoor","land");
	set("chance",37);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"npc/hoodlum",
	}) );
	setup();
}