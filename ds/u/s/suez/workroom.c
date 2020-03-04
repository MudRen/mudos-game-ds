// Room: /u/s/suez/workroom.c

#include <ansi.h>
inherit ROOM;


void create()

{

	set("short",HIG "奇嵐軒"NOR);

	set("long", @LONG  
你一進入這個房間，發現這裡都是竹製的家具，綠色的桌
椅上擺滿了一本本古代的線裝書，涼涼的風將牆上的畫吹的不
停顫動，明亮的窗口旁有張小書桌，桌上擺了本筆記本和許多
文具。這裡就是武林奇俠蘇子奇的隱居之所，不知情的人還以
為是哪個騷人墨客的書房呢！
LONG

);
	
                set("exits", ([ /* sizeof() == 2 */
 
                "out" : __DIR__"fall",

                "hall" : "/d/wiz/hall1",
                "com" : "/u/c/cominging/workroom",
]));

	set("item_desc", ([ /* sizeof() == 1 */

  "線裝書" : "這些線裝書上畫滿了漫畫.....

看來這間屋子的主人....唉....。 
",

]));

	set("world", "undefine");

	set("no_clean_up", 0);

	set("valid_startroom", 1);


	setup();

	 call_other("/obj/board/suez_b", "???");


}
