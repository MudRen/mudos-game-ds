#include <ansi.h>
inherit NPC;
void create()
{
 set_name("老人",({"old man","man"}));
 set("long",@LONG
一個看起來相當平凡的老人.
LONG
    );
 set("attitude", "peaceful");
 set("age",72);
 set("gender","男性");
 set("level",20);
 set_skill("sky-dagger",20);
 set("chat_chance_combat",200);
 setup();
}

void init()
{
        add_action("do_ask","ask");
	add_action("do_say","say");
}

int do_ask(string arg)
{
      object me;
      me=this_player();
      if (arg != "man about name") return 0;
      message_vision(YEL"$N對老人問起他的名字。\n"NOR,me);
      message_vision(YEL"老人說道: 老夫的名字有何重要, 休要再提。\n"NOR,me);
      me->set_temp("know_name",1);
	return 1;
}

int do_say(string arg)
{
      object me;
      me=this_player();
      if (arg != "江湖幻滅似斗星, 唯有天梟霸千世") return 0;
	if(me->query_temp("know_name") == 1) 
	{ 
	message_vision(YEL"$N自言自語的說: 江湖幻滅似斗星, 唯有天梟霸千世。\n"NOR,me);
	me->set_temp("speak",1);
	 call_out("speak",1,me);
             return 1;
	}
	else
	{
	message_vision(YEL"$N自言自語的說: 江湖幻滅似斗星, 唯有天梟霸千世。\n"NOR,me);
	message_vision(YEL"但老人絲毫無動於衷。\n"NOR,me);
	    return 1;
	}
}


void speak()
{
      int i;
      object me,obj;
      me=this_player();
      obj=this_object();
      i=me->query_temp("speak");
      switch( i ) {
          case 1:
            command("say 啊 ! 小兄弟是何處得知這句話的 ?!");
            message_vision(YEL"老人忽然一震 , 苦笑道 : 都是過往事了 ...何必在乎..\n"NOR,me);
	    message_vision(YEL"老人苦笑道 : 還是被小兄弟套出話來了...老夫行不改姓, 坐不改名, 姓龍名音遠便是 !\n"NOR,me);
            obj->set("name","龍音遠",({"lung ain uin","lung","uin"}));
	    obj->set("title",BLU"雷霸一方"NOR);
	    obj->set("long","原來他就是天梟第十七代掌門 -- 雷霸一方 龍音遠 !! \n你發現他身上果然有一股非凡之氣, 果\然不\愧\是\天\梟掌門, \n就是不一樣 !! \n");
		break;
		}
}
