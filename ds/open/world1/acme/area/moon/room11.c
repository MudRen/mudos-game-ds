inherit ROOM;

void create()
{
	set("short","戰月之間");
	set("long", @LONG
一進入此處，你不自禁的感到一陣興奮。因為這裡觸目所及的全
是些稀世珍寶，其中還有許多是你叫不出名字的。這眾多的寶物全是
月族的前輩們在行走大江南北之時，冒著各種的危險所辛苦得到的。
為了造福其他的族人們，他們特別將寶物千里迢迢的帶回廣寒宮來放
置於此。所有的族人在使用這些寶物之時，應該心懷感謝並且好好珍
惜。

LONG
	);
	set("exits",([
  "south" : __DIR__"room10.c",
]));
	set("objects",([
__DIR__"item/weapon_box" :1,
]));
/*	set("item_desc",([
  "浮刻":@DESC1

                              人
                              不
                              犯
                              我
                              
                              我
                              不
                              犯
                       燕     人
                       赤     
                       霞       
                              
DESC1
,
]));
*/
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
}

