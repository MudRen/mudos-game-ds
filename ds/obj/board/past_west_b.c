#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name( HIM"聖碑"NOR ,({ "Legendary pillar", "pillar","board" }));
    set("location","/open/world1/meetroom_west.c");
    set("board_id", "past_west_b");
	set("long",@LONG
這個大石碑就像一根頂天立地的棟樑一般, 十分雄偉狀觀, 除了
外觀驚人之外, 石碑之上也刻了許多圖形, 不知道象徵著什麼東
西? 但是比較引人注意的是, 圖形縫隙之間都刻上了密密麻麻的
文字.
LONG
	);
	setup();
	set("capacity",150);
	set("master",({ "baal","uchimaha" }));
}
