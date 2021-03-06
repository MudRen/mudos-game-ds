#include <ansi2.h>
inherit ROOM;

void call_monster1();
void call_monster2();
void call_monster3();
void call_monster();
void no_monster();
int query_monster();

string *place=({"gcave1","gcave2","gcave3","gcave4","gcave5",
		"gcave6","gcave7","gcave8","gcave9","gcave10",
		"gcave11","gcave12","gcave13","gcave14"});
      
//string *monster=({"godlin_guard","godlin_savage"
//		  "ogre_warrior","ogre_archer","ogre_mage","ogre_boss"});

void create()
{	
	object monster,g;
	set("short", "台地上");
	set("long", @LONG
這塊台地上有著許多雜亂的足跡。不過這些足跡看起來並不是人
類所留下來的，而是另一種更為巨大的生物，因此小心的你開始戒備
。山壁上有著一個山洞，你似乎可以聞到山洞裡傳出一股令人做噁的
臭味。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  		"in" : __DIR__"gcave1",
  		"southdown" : __DIR__"burg10",
	]));
	setup();
	
        if( query_monster() ) return ;
	else {
	g=new(__DIR__"npc/goblin_guard");
    	g->move(__FILE__); }

}
int valid_leave(object me, string dir)
{
  	object guard;
  	if( objectp(guard=present("goblin guard", this_object())) && dir == "in" )
  	{
    	message_vision(
    	"只見$n怒吼一聲，擋住了山洞入口。\n",me,guard);
    	return notify_fail("");
	}
	return ::valid_leave(me , dir);
}
void call_monster()
{
  	object ob = this_object();
  	object m;
  	int i;

  	message("world:world1:vision",
  	GRN"\n\n\t【迷霧森林】  "HIC"  伏克村的怪物們暴動了！\n\n"NOR,users());
	for(i=0;i<=4;i++)
	{
    	m=new(__DIR__"npc/goblin_savage");
    	m->move(__DIR__+place[random(sizeof(place))]);
    	}
    	call_out("call_monster1",5,0);
  	return;
}
void call_monster1()
{
  	object m;
  	int i;

  	for(i=0;i<=4;i++)
	{
    	m=new(__DIR__"npc/ogre_warrior");
    	m->move(__DIR__+place[random(sizeof(place))]);
    	}
    	call_out("call_monster2",5,0);
    	
  	return;
}
void call_monster2()
{
  	object m;
  	int i;

  	for(i=0;i<=4;i++)
	{
    	m=new(__DIR__"npc/ogre_archer");
    	m->move(__DIR__+place[random(sizeof(place))]);
    	}
    	call_out("call_monster3",5,0);
    	
  	return;
}
void call_monster3()
{
  	object m,boss;
  	int i;

  	for(i=0;i<=2;i++)
	{
    	m=new(__DIR__"npc/ogre_mage");
    	m->move(__DIR__+place[random(sizeof(place))]);
	}
	boss=new(__DIR__"npc/ogre_boss");
	boss->move(__DIR__+place[10]);
	
    	call_out("no_monster",300,0);
    	
  	return;
}
void no_monster()
{
	object monster;
        if(objectp(monster=find_living("fog-forest-war-monster") ) )
	{
                 if(!environment(monster)) destruct(monster);
                  call_out("no_monster",30,0);
        }
        else {
        message("world:world1:vision",
        GRN"\n\n\t【迷霧森林】  "HIC"  伏克村的暴動平息了！\n\n"NOR,users());
	}
	return;
}
int query_monster()
{
        object monster;

        while( objectp(monster=find_living("ghost-forest-war-ghost")) )
        {
                if( !environment(monster) )
                {
                        destruct(monster);
                        monster = 0;
                }
                else break;
        }

        if( objectp(monster) ) return 1;
        else return 0;
}