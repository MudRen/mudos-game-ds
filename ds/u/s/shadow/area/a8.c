/**
 * Shadow's area [荒廢漁村 - 周大嬸家 - a7]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"周大嬸家"NOR);
	set("long",@LONG
屋中家具簡樸卻相當整齊乾淨，木桌上有一盞酥油燈以及一本已
經翻開的三字經，一張木床及簡單的廚具，屋後還有雞群搶食咯咯叫
的聲音。
LONG
	);
	set("light", 0);
	set("exits",([
		"south": __DIR__"a7",
	]));

	set("objects",([
	__DIR__"npc/zhou":1,
	]));

	setup();
	
}
