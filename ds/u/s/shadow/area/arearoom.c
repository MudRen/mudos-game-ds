/**
 * Shadow's area room [v.1]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"霸王主帳"NOR);
	set("long",@LONG
一個異常堅固的蒙古包，正前方擺置著一個古樸的長桌，桌上舖
著著一張褐黃色牛皮捲軸，仔細一看原來都是一些軍機與戰事攻防之
計，看著看著不僅讓你領略到霸王羽的雄才大略，也不禁為霸王的百
戰百勝心折。帳內左右兩側分列了項羽的近衛兵「十八鐵騎」，個個
皆是能以一擋百的好手，一身勁裝更顯露不凡的氣勢，除非真是吃了
秤陀鐵了心否則千萬不可在此造次。
LONG
	);
	set("light",1);
	set("exits",([
		"north": "/u/s/shadow/workroom",
		"east": __DIR__"a1",
	]));

	/**
	 * 設計物品與生物
	 */	 
	set("item_desc",([
		"捲軸": "		
"HIG"目前正在進行中的區域有:\n"NOR"
    1. 漁村
    2. 水世界\n
"HIW"以後想要進行的區域有:\n"NOR"
    1. 古戰役\n"])); 
	
	setup();

}
