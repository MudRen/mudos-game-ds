#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
	set_name("年獸",({"year monster","monster"}) );
	set("long",@LONG
一隻的轉化人形的年獸，被上天配下來到七域舉辨抽獎(prize)和兌
獎(change)活動。你可以打 llist 看看有那些獎品。
LONG
);
	set("age",5000);
	set("level",200);
        set("attitude", "peaceful");
	set("race","人類");
        set("gender", "男性" );
	set("chat_chance",10);
	set("chat_msg",({
	"年獸輕輕地拍著你的頭。\n",
      "年獸說道：「年終抽獎活動！！一次只須經驗值一千點就可以了。\n",
	"年獸啍著輕快的歌曲，似乎非常的快樂。。\n",
	}) );
	setup();
}


void init()
{
	::init();
	add_action("do_prize","prize");
	add_action("do_change","change");
	add_action("do_list","llist");
}

int do_prize()
{
	int i,j;
	object me,obj;
	me=this_player();
	if(me->query("exp") < 1000)
		return notify_fail("抽獎一次需要 1000 exp。\n");
		
	message_vision("$N把手伸進去年獸的嘴巴裡動了動，隨既拿出了一張彩券。\n",me);
	obj=new(__DIR__"year_paper");
	j=random(300);
	if(j==0) obj->set_level(1);
	else if(j<5) obj->set_level(2);
	else if(j<15) obj->set_level(3);
	else if(j<30) obj->set_level(4);
	else if(j<50) obj->set_level(5);
	else if(j<75) obj->set_level(6);
	else if(j<105) obj->set_level(7);
	else if(j<140) obj->set_level(8);
	else if(j<200) obj->set_level(9);
	else obj->set_level(10);
	obj->move(me);
	me->add("exp",-1000);
	return 1;
}

int do_change()
{

	object paper,me;
	int lv;

	me=this_player();

	if(!objectp(paper=present("year paper",me) ) )
		return notify_fail("你身上並沒有可兌獎的獎券。\n");
	lv=paper->query("level");
	switch(lv)
	{
	case 1:
	break;
	case 2:
	break;
	case 3:
	break;
	case 4:
	break;
	case 5:
	break;
	case 6:
	break;
	case 7:
	break;
	case 8:
	break;
	case 9:
	break;
	case 10:
	break;

	}		
	destruct(paper);
	return 1;
}

int do_list()
{
	tell_object(this_player(),@long

中國民俗過年特別活動
-----------------------------------------------------
第一特獎：聲望 100
第二特獎：聲望 50
第三特獎：聲望 30
第四特獎：聲望 10
第五特獎：經驗值 10000
第六特獎：經驗值 5000
第七特獎：經驗值 3000
第八特獎：經驗值 1000
第九特獎：經驗值 500
第十特獎：經驗值 100

long
);

return 1;
}
