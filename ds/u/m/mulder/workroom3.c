#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"小喇叭工作室"NOR);

	set("long", @LONG
這是小喇叭的工作室，你可看見周圍都貼滿了「深田恭子」的Poster。
和一張一張的寫真照片。向左看可以看見一個VCD櫃和書櫃，全部都是
「深田恭子」所演過的劇集和寫真，有『上帝，請給我多一點時間！』
LONG

	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"green.c",
  "naboo" : __DIR__"area/naboo/middle.c",	
  "enter" : __DIR__"area/inn",
  "star" : __DIR__"starwars",
 "war" : __DIR__"a10.c",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"kelly.c" : 1,
   __DIR__"kyoko.c" : 1,
__DIR__"area/naboo/npc/bar.c" :10,
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);


	setup();
	call_other("/obj/board/mulder_b.c", "???");
}
void init()
{
	call_out("leave_message",3,this_player());
	call_out("entercheck",2,this_player());
}

void entercheck(object ob)
{
 if(userp(ob))
 {
  if(wiz_level(ob) < wiz_level("(immortal)"))
  {
   message_vision(HIR"深田恭子說："+ob->name()+" 你怎會跑來這，你想點呀(-_-)！\n"NOR, ob);
   ob-> die();
  } else {
   message_vision(HIY"\n深田恭子說: 你好！！ "+ob->name()+"大大！今日怎這麼早呀！！\n"NOR, ob);
  }
 }
 return;
}

void leave_message(object me)
{
	object mulder,ob2;
	if( mulder=find_player("mulder"))
	{
		if(me->query("id")!="mulder")
		{
			ob2=present("mulder",this_object());
			if( ob2 ) return;
			add("guest",me->query("id")+" - ");
			tell_object(mulder ,"[1;37m有訪客來囉!("+me->query("name")+")[m\n");
			tell_object(me,"深田恭子(Kyoko)告訴你:你好呀！！小喇叭番來囉！\n");
		}
		else
		{
			if(query("guest"))
			{
				tell_object(me,"[1;37m今天的訪客有:"+query("guest")+"[m\n");
				delete("guest");
			}
			else
			{
				tell_object(me,"[1;37m今天還沒有訪客來過[m\n");
			}
		}
	}
	else
	{
		add("guest",me->query("id")+" - ");
		tell_object(me,"[1;37m深田恭子(Kyoko)告訴你: Mulder還沒上線哦，你隨意逛逛吧！[m\n");
	}
 

}