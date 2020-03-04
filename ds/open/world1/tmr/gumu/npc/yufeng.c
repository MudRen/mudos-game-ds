// yufeng.c 玉蜂

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW "玉蜂" NOR, ({"yufeng","feng","bee"}) );
	set("race", "野獸");
	set("age", 8);
	set("long","這是一只玉色的蜜蜂，個頭比普通蜜蜂大得多，\n翅膀上被人用尖針刺有字。\n");

	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
"玉蜂在你頭頂轉了一圈，似乎發現這不是可采蜜的地方，就嗡嗡嗡地飛走了。\n",
"玉蜂圍繞著鮮花飛飛停停，似乎也不著重在采蜜上。\n",
	}) );

	setup();
}
