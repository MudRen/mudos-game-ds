#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", CYN"迴風居"NOR);
	set("long", @LONG
迴風居，這裡的天頂開了個洞，陣陣涼風由洞中傳出，許多摘星門弟
子練武累了就聚集在此聊天，這裡擺了許多食物和水，食物是生的不能吃
，但是水倒是可以讓你喝個痛快。
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "south" : __DIR__"base_5",
               ]));
         set("item_desc",([
        "天頂":"看著那個洞，你不禁懷疑下雨時這裡會不會淹水....\n",
        "食物":"有醃肉，燻魚，醬菜....的材料，所以不能吃，生吃會拉肚子。\n",
         ]));

       set("objects", ([ 
          __DIR__"npc/obj/pot" : 1,
           __DIR__"npc/apprentice2" : 1,
        ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();

}