/*	File : "/open/world1/cominging/area/dragon/bank.c"	*
 *	Author : -Alickyuen@DS-					*
 *	Desc : 幫會專屬銀行,存放幫派存款			*
 *	Last Modify : 19-11-2001				*/

#include <dbase.h>
#include <ansi2.h>

inherit CLUB_BANK;
//inherit ROOM;

mapping info;

void create()
{
	set("short", HIW"『狂龍大錢莊』"NOR);
	set("long", @long
這裡就是狂龍幫內裡的狂龍大錢莊，用來放幫會經費之用。
long
+HIR"　　這裡可用的指令有：\n\n"
+"　　[deposit]　－－－－－－－　[存款－適用所在時空貨幣]\n"
+"　　[transfer] 　－－－－－－　[轉帳－適用任何時空貨幣]\n"
+"　　[withdraw] 　－－－－－－　[提款－適用所在時空貨幣]\n"
+"　　[clear]　－－－－－－－－　[清除存取記錄]\n"
+"　　[list] 　－－－－－－－－　[查看幫會資產排行]\n\n"NOR
);
	set("club_id", "dragon");
	set("club_level", 6);
	
	set("light", 1);
	set("exits", ([
		"up" : __DIR__"crazy_dragon",
	]));

	setup();

	set("long", query("long") 
		+ BANK_D->get_bank_amount(query("club_id")) 
		+ BANK_D->get_log(query("club_id"), "deposit")
		+ BANK_D->get_log(query("club_id"), "withdraw")
	);
}

