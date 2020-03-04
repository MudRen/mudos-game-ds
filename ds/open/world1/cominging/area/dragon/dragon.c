inherit ROOM;

void create()
{
	set("short","狂龍幫大廳");
	set("long", @LONG
一跨過門檻，心頭一震，原來這就是江湖上黑道聞之喪膽的狂龍
幫，想起自己以前的所做所為，手掌心中不禁冒出一陣冷汗。沒想到
狂龍幫的大廳和一般江湖上的幫派不同。左邊牆上掛著幫主昔年闖江
湖的捷天和闢地兩劍，再看右邊．．這時才發現，狂龍幫眾一個個屈
膝坐在地上，旁邊站著的數人似乎都是內中好手，一個個太陽穴隆起
，手握劍把，全神專注的瞪著你。
LONG

	);
	set("exits",([
  "south" : __DIR__"dragon_garth.c",
  "north" : __DIR__"dragon_meeting_room.c",
  "northeast" : __DIR__"crazy_dragon.c",
  "southeast" : __DIR__"fire_dragon.c",
  "northwest" : __DIR__"god_dragon.c",
  "southwest" : __DIR__"valor_dragon.c",
  "up" : "/open/world1/wilfred/club/dragon/online",
]));
	set("objects",([
__DIR__"box1" :1,
]));
	set("item_desc",([
  "捷天":"一把聽說幫主在某日從天而降至家園後方的一把劍，劍鋒處閃閃發光，而輕如水，似可擲天一般.\n",
  "闢地":"綠黃色的一把魔劍，傳說這把魔劍是血洗過一千多萬人所鑄成的，隱隱還發出一點血色.\n",
]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
	call_other( "/obj/board/dragon_club_b", "???" );
}

void init()
{
	add_action("do_kill",({ "kk","kill" }));
  this_player()->set_temp("come_from_dragon",1);
  this_player()->set_temp("come_from_sky",0);
}

int valid_leave(object me, string dir)
{
	if( dir=="north" && !wizardp(me) )
	{
		if(CLUB_D->check_member("dragon",getuid(me)) < 4) return notify_fail("那裡只有長老以上才能進去。\n");
	}
	return ::valid_leave(me, dir);
}

int do_kill(string arg)
{
	if( arg == "guard" || arg == "dragon guard" )
	{
		tell_object(this_player(),"你想要殺害自己的手足？！\n");
		return 1;
	}
	else return 0;
}
/*這裡是狂龍幫的大廳，在這裡有許多珍貴奇物在此，常常有外地返回的兄弟
貢獻寶藏和一些奇珍異寶，四周的牆上掛滿了書法名家的帖子而其後還藏有些機
關，在這裡有些臥椅，上面都鋪了相當多的虎皮、蛇皮之類等等之物，還在門前
有個匾額，上面寫著”飛鴻騰達”四字，象徵著狂龍幫的勢力一日不可一日之盛
，目前以有許多門眾，在大廳周圍有些出口，還標明著是做何用處，可見狂龍幫
之盛、之財、之勢！*/
