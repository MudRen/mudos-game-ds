// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
	HIB "黑無常說道﹕喂﹗新來的﹐你叫什麼名字﹖\n\n" NOR,
	HIB "黑無常用奇異的眼光盯著你﹐好像要看穿你的一切似的。\n\n" NOR,
	HIB "黑無常「哼」的一聲﹐從袖中掏出一本像帳冊的東西翻看著。\n\n" NOR,
	HIB "黑無常閤上冊子﹐說道﹕咦﹖陽壽未盡﹖怎麼可能﹖\n\n" NOR,
	HIB "黑無常搔了搔頭﹐歎道﹕罷了罷了﹐你走吧。\n\n"
		"一股陰冷的濃霧突然出現﹐很快地包圍了你。\n\n" NOR,
});

void create()
{
	set_name("黑無常", ({ "black gargoyle", "gargoyle" }) );
	set("long",
		"黑無常伸著長長的舌頭瞪著你﹐黝黑的臉上看不出任何喜怒哀樂。\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
		"黑無常發出一陣像呻吟的聲音﹐當他發現你正注視著他的時候﹐瞪了你一眼。\n",
		"黑無常把長長的舌頭伸出來﹐緩緩地舔了舔自己又黑又長的手指。\n"
	}) );
	set("age", 217);
	set("level", 99);
	set("combat_exp", 20000);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);
	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	if( !ob || !present(ob) ) return;

	if( !ob->is_ghost() ) {
		command("say 喂﹗陽人來陰間做什麼﹖");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

	ob->move(REVIVE_ROOM);
	message("vision",
		"你忽然發現前面多了一個人影﹐不過那人影又好像已經在那裡\n"
		"很久了﹐只是你一直沒發覺。\n", environment(ob), ob);
}


