// Room: /u/m/mulder/area/road16.c

inherit ROOM;
inherit MOBROOM; 
void create()
{
	set("short", "廢車場");
	set("long", @LONG
恭喜你∼！你可能或是他還沒出來迎接你．你是新手的，請
你快些走啦，若然你出來的話那就誰也到幫不到你，你只好向你
的朋友說一聲：「再見∼！」
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road13",
]));
	set("no_clean_up", 0);
	set("light",1);
	set("chance",100);
	set("mob_amount",3);
	set("mob_object",({
	"/u/m/mulder/area/npc/mask",
	"/obj/example/dog",
	}) );
	setup();
	
}
void init()
{
	::init();  
        add_action("d_creat","creat");	        
        add_action("d_stop","stop");
}

int d_stop(string arg)
{
 this_object()->set_temp("stop_creat",1);
 tell_object(this_player(),"怪物地雷已關閉!\n");
 return 1;
}

int d_creat(string arg)
{
 this_object()->set_temp("stop_creat",0);
 tell_object(this_player(),"怪物地雷已開啟!\n");
 return 1;
}
