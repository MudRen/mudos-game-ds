inherit ROOM;

void create()
{
        set("short", "臨時工作室");
        set("long", @LONG
這裡是夢幻七域工讀生臨時工作室。

	取得工讀生身分時請牢記以下準則:

	1. 不可利用特權圖利其他玩家
	2. 不可利用特權危害其他玩家
	3. 不可給予其他玩家任何物品
	4. 不可和其他玩家發生戰鬥
	
	違反以上規則將砍檔，終身不再錄用。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : "/open/world2/lichi_town_2/map_5_26",
]));
        set("no_clean_up", 0);
	set("no_fight",1);
    set("valid_startroom",1);
	set("light",1);
        set("objects", ([ 
        ]) );
        setup();

call_other( "/obj/board/superplayer_b", "???" );
}

