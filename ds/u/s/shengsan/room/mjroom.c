#include <room.h>
#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
void create()
{
set("short",HIR"["+HIY+"深田恭子麻將館"+HIR+"]"NOR);
set("long", @LONG
這是一間專門讓玩家們休息的娛樂場所，當你在為你的角色
辛苦鍛鍊時，別忘了休息是為了走更長遠的路，找三五好友一同
來打個幾圈吧，不過可別沉迷在賭博中喔∼∼∼∼詳細的規則請
看看佈告欄（ｂｏａｒｄ）
LONG
);
set("light",1);
set("no_fight", 1);
set("no_magic", 1);
set("no_spells", 1);
set("exits",([
]));
set("objects",([
__DIR__"mj":1,
]));
set("item_desc",([
"board":"
一般基本的操作：：  每種牌都有其代碼　例：一萬－＞1w 七索－＞7s
加入牌局：addin        開始牌局：start
摸牌：mo             重開牌局：restart
看玩家1的牌：.1      看玩家2的牌：.2
看玩家3的牌：.3      看玩家4的牌：.4
看自己的牌：.
丟牌：dump xx        吃：eat xx xx        
碰：pon              槓：gon              
胡：hu               聽：tin xx           
xx為代碼  例：eat 2w 3w
",
]));
setup();
}
