/**
 * Shadow's area [荒廢漁村 - 義莊祠堂 - graveyard23]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
#define SHADOW_GRAVEYARD "/u/s/shadow/area/"

inherit ROOM;

void open_war(object me, object ob);
void end_war();
int query_ghost();

void create()
{
	set("short",HIG"義莊祠堂"NOR);
	set("long",
"一座偌大的祠堂，供奉著施家中地位較高的長者靈位，兩旁斑駁\n"
"的護龍滿是塵埃，蜘蛛網遍佈整座祠堂，地上則散落著一些供奉祭祀\n"
"用的器具。轉頭向左一看，居然有一"HIR"骨骸"NOR"懸吊於橫樑之上，在空蕩蕩\n"
"的祠堂中飄呀飄地，讓人怵目驚心！\n"
	);
	set("light", 0);
	set("exits",([
		"south": __DIR__"graveyard22",
	]));
	
	set("item_desc",([
		"骨骸": @LONG
    在空中飄盪的骨骸，用一條粗麻繩繫在祠堂的橫樑上，身上的大
紅衣物早已褪去了顏色，但可以想見的是死者死時的怨恨，否則怎麼
會選擇這樣的方式終結自己的生命，看著骨骸，你心中興起了一股憐
憫之意，突然興起了想把他拿下來的念頭(get)。
LONG
	]));   
	
	setup();	
}

void init()
{
	add_action("do_get", "get");
}

int do_get(string arg)
{
	object me, room, manager;
		
	if (!arg)
		return 1;
	else if (arg != "骨骸")	{
		return notify_fail("你要拿甚麼呢？\n");
	}	else {
		me = this_player();
		room = environment(me);
		
		if ( room->query_temp("get") )
			return notify_fail(HIG"一陣綠霧蒸發在空氣中，甚麼事也沒有...\n"NOR);
		else {
			room->set("open_war",1);
			call_out("open_war", 3, me, room);
			/* 讓 ppl 無法 recall & south */
			room->set_temp("get", 1);
			room->set("exits",([]));
			room->set("no_recall","祠堂的陰氣讓天地喪失了傳送力量。");
		}
	}
	return 1;
}

void open_war(object me, object ob)
{
	int i;
	object g, ghost;
	
	if( !ob->query("open_war") ) return;

	/* Start GraveyardWar */
	message("world:world1:vision", HIW"\n\t"+me->name(1)+"闖入了義莊的禁區∼\n"NOR, users());
	message("world:world1:vision", HIR"\n\t瞬間一陣鬼哭神號，義莊的天空漫起一股腥風血雨\n"NOR, users());
	message("world:world1:vision", HIR"\n\t紅衣女鬼的尖叫聲響徹整個天空...∼ 負 心 者 殺 無 赦∼\n\n"NOR, users());
	
	/* 呼叫出紅衣女鬼 */
	ghost = new(__DIR__"npc/ghost");
	ghost->move(ob);
	
	/* 呼叫出義莊管理員*/
	g = new(__DIR__"npc/manager");
	g->move(__DIR__"graveyard23");

	/* 產生活死人 */
	for(i=0; i<1; i++)
	{
		g = new(__DIR__"npc/dead1");
		g->move(__DIR__"graveyard21");
	}
	/* 產生食屍狗 */
	for(i=0; i<1; i++)
	{
		g = new(__DIR__"npc/dog1");
		g->move(__DIR__"graveyard21");
	}
	
	
	call_out("end_war", 180);
	return;
}

void end_war()
{
	object ghost;
	
  if( query_ghost() )	call_out("end_war",30);
	else {
		message("world:world1:vision", HIR"\n\t一聲淒厲的尖叫夾雜著不及吐訴的怨恨以及對世人的詛咒穿破了雲層，消逝在義莊的天空中...\n\n"NOR, users());
		this_object()->set("open_war",0);
	}       
	return;
}

int query_ghost()
{
	object ghost;

	while( objectp(ghost = find_living("GraveyardWar")) )
	{
		if( !environment(ghost) )	{
			destruct(ghost);
			ghost = 0;
		}
		else break;
	}
	if( objectp(ghost) ) return 1;
	else return 0;
}
