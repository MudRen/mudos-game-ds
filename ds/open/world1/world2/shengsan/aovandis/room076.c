// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"職業介紹所"NOR);
	set("long", @LONG
長桌子上的文件有些的凌亂，一位中年婦人正在辦公。冷氣充斥這整
個房間，左邊牆壁有個文件整理盒(box)，看起來裡面應該有許多的工作
機會。你看到牆上懸掛著一個漂亮的告示牌(note)。
LONG
	);
	set("item_desc", (["note":@NOTE

佈告牌上寫著:
[1;32m
	很高興能有機會為您介紹工作，請先看看文件整理盒(box)
	內的工作機會，如果喜歡請跟服務人員講，我們將會親切的
	為您服務。謝謝您的光臨。

[1;33m					* 職業介紹所 *
[m
NOTE
        ,"box":@NOTE

這個盒子上寫著「工作機會」四個字，裡面裝著一疊一疊的文件。

NOTE
	]) );

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room064",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/woman" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}