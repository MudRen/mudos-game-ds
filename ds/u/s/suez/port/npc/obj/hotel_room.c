#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIM"凡琴斯島旅館房間"NOR);
set("long",@LONG
這是一間十分寬敞的房間，別緻的傢俱一一座落在牆邊，幾本書冊整
齊的擺放在靠窗的桌上，那從窗口透入的光線，讓整個房間充滿著和外面
天空一樣的感覺。隱隱約約在你的耳畔，是大廳的音樂聲，是街上的車馬
聲，在這個房間中有如夢中般的模糊虛幻，你走向那舒適溫暖的床褥，享
受這難得的悠閒時光。
LONG);
set("light",1);
set("no_cast",1);
set("no_fight",1);
set("no_clean_up",1);
setup();
}
