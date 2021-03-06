/**
 * Shadow's Workroom [v.1]
 */

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"霸王陵"NOR);
	set("long",@LONG
你來到了一個幽暗的偌大空間，肅殺的沈悶空氣壓得你幾乎喘不
過氣。你忐忑不安地環繞一週，突然間！從遠方傳來震天的喊殺聲朝
你急遽接近。就在你張慌失措之時，龐大的軍陣在你面前倏地消失，
只剩下空氣中瀰漫的詭譎氣氛，朦朧間一位古裝將軍慢步走到妳的面
前，高大的身軀披著漆黑的鎧甲，足登短靴、腿扎行滕，腰懸稀世青
銅寶刀，虎視眈眈地看著你！牆上掛了一幅對聯（couplet），隱約
透露出這兒的主人是誰。
LONG
	);
	set("light",1);
	set("exits",([
		"out": __DIR__"meetroom_east",
	]));

	set("item_desc",([
		"couplet":
		HIG"
		疾      凌   
		風      雲   
		軍      霸   
		魂      氣   
		鎮      隨   
		四      風   
		方      逝"
		NOR"\n",
	]));

	/**
	 * 設計物品與生物
	 */	 
	/*
	set("objects",([
	__DIR__"npc/wuji":1,
	]));
	*/
	set("valid_startroom", 0);
	setup();
 
	/**	 
	 * 呼叫其它的物件
	 */
	call_other("/obj/board/shadow_b","???");
	
	
}
