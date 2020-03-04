#include <room.h>
#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
void create()
{
set("short",HIR"[麻將室]"NOR);
set("long", @LONG
這是賭坊裡的一間密室，室內擺設了幾張麻將桌。這裡的光線很
昏暗，舊式的燈泡，暗暗的橘色燈光，還有一股濃濃的煙味，令人有
十分墮落的感覺。西邊牆上的小白板（ｂｏａｒｄ）上頭寫著一些凌
亂的小字。
LONG
);
set("light",1);
set("no_fight", 1);
set("no_cast", 1);
set("no_exert", 1);
set("no_magic", 1);
set("no_steal", 1);
	set("no_whisper", 1);
set("exits",([
"east": __DIR__"mjroom",
]));
set("objects",([
"/obj/mjlady3":1,
]));
set("item_desc",([
"board":@BOARD

一般基本的操作： 每種牌都有其代碼　例：一萬－＞1w 七索－＞7s

加入牌局：addin		摸牌：mo 或是 0
設定賭注: bet <數量>	丟牌：dump xx 或是 dd xx
開始牌局：start		吃：eat xx xx
重開牌局：restart	碰：pon
看玩家1的牌：.1		槓：gon (暗槓用 gon xx)
看玩家2的牌：.2		胡：hu
看玩家3的牌：.3		自動設定: setmj (詳細指令請打 help setmj)
看玩家4的牌：.4	        自動聽牌: tin <廢牌代碼> ***新功能測試中
看自己的牌：. (或是觀戰者看目前戰況)
給別人看自己的牌: showmj <id>

		(以上的 xx 為牌的代碼  例：eat 2w 3w)

麻將的基本遊戲規則請參考 help mj

BOARD,
]));
setup();
}
