// In room073.c 圖書館
#include <path.h>
inherit NPC;

void make_mark();

void create()
{
	set_name("圖書館館員",({"library member","member"}) );
	set("long","這位圖書館員是個優秀的館員。\n");		
	set("age",23);
	set("level",3);
	set("race","人類");
	set("gender","女性");
	set("evil",-5);		// 邪惡度 -5 (正的表邪惡, 負表善良)
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 圖書館是大家智慧的寶庫，歡迎大家多多利用！"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",5);
	set_skill("block",5);
	set_skill("parry",8);
	set_skill("unarmed",10);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");

	set("bookroom",SHENGSAN2"aovandis/bookroom");

	setup();

	add_money("dollar",40);
}

void init() 
{
	::init();
	add_action("do_borrow","borrow");
	add_action("do_return","return");
}

int do_borrow(string arg)
{
	object me,book;
	string *item,bookname;
	int bookno,i,tmp,bookdate;

	me = this_player();

	if(!arg) return notify_fail("你要借什麼書呢?\n");
	if(sscanf(arg,"book%d",bookno)!=1) return notify_fail("你要借什麼書呢?\n");
	if(book=present(arg,me))
	{
		item = me->query("aovandis/library");
		for(i=0;i<sizeof(item);i++)
		{
			if(sscanf(item[i],"book%d_%d",bookno,bookdate)!=2)
				continue;
			bookname = "book"+(string)bookno;
			if(bookname == arg)
				tmp = 1;
		}
		if(tmp)
			command("say 你已經借過 "+arg+" 了。");
		else
		{
			me->add("aovandis/library",({arg+"_"+time()}));
			message_vision("$n把『"+book->query("name")+"』交給了 $N。\n",me,this_object());
			message_vision("$n將『"+book->query("name")+"』做了消磁後交還給了 $N。\n",me,this_object());
		}
	}
	else
		command("say 你身上並沒有 "+arg+" 阿？");
	return 1;
}

int do_return(string arg)
{
	object bookroom,me,book;
	string bookname,*item;
	int i,tmp,gotit,bookno,bookdate;

	me = this_player();

    if( !arg ) return  notify_fail("你要歸還什麼書呢?\n");
	if(sscanf(arg,"book%d",bookno)!=1) return notify_fail("你要歸還什麼書呢?\n");
	if(!bookroom=load_object(this_object()->query("bookroom"))) return 0;

	if(book=present(arg,me))
	{
		item = me->query("aovandis/library");
		for(i=0;i<sizeof(item);i++)
		{
			if(sscanf(item[i],"book%d_%d",bookno,bookdate)!=2)
				continue;
			bookname = "book"+(string)bookno;
			if(bookname == arg)
			{
				gotit = i;
				tmp = 1;
			}
		}
		if(!tmp)
			command("say 你沒有借過 "+arg+" 喔。");
		else
		{
			me->delete("aovandis/library",({arg+"_"+time()}));
			message_vision("$n把『"+book->query("name")+"』交給了 $N。\n",me,this_object());
			message_vision("$n將『"+book->query("name")+"』做了消磁後交還給了 $N。\n",me,this_object());
		}
			
	}
	else
		command("say 你身上並沒有 "+arg+" 阿？");

	return 1;
}

void make_mark()
{
	object *enemy, ob;
	command("say 哇！救命阿！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"，你這個可怕的惡魔，你將會受到懲罰的。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
