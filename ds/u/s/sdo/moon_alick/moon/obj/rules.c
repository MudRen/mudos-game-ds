#include <ansi.h>

inherit ITEM;

string show_long();

void create()
{
	set_name(HIC"花燈大會告示板"NOR, ({ "board" }) );
	set("no_get", 1);
	set("no_sac", 1);
	set("value", 0);
	set("long", ""+this_object()->show_long()+"");

	setup();
}

string show_long()
{
	string msg;
/*
（１）題目視為普通謎題(Quest)處理，禁止以公開頻道詢問或解答問
　　　題。
*/
	return (@long
謎語是一種既好玩又益智的玩意，它透露一點點，又隱藏了一點點，
這正好逗起猜謎者的好奇心，引發大家追尋謎底的興趣。謎語也充滿
娛樂性、文學性和知識性，多猜謎語，還可以提高猜謎者的推理能力
和分析能力。由於這項活動益處甚多故此本年度中秋節之花燈大會將
舉行一項活動－『燈謎競逐』，此遊戲守則如下：

（１）遊戲進行時間為９月至１０月２日晚上１２時正。
（２）是次遊戲設特級大獎一名、大獎四名及普通參加獎。
（３）遊戲玩法為：
　　　　　首先到題目處，然後鍵入指令 answer 回答問題。
　　　　　例如：answer release
　　　　　若題目沒特別指示，答案須為『中文』字。
　　　　　＊注意＊有部份題目為ＩＱ智力題。
（４）有任何問題請向巫師 Release 查詢。 

Write By -Alickyuen@DS- & -Release@DS- on 23/9/2001
long);
}