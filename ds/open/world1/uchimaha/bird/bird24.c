#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit MOBROOM;
void create()
{
 set("short",HIC"天梟教"NOR"練武場");

 set("long",@LONG
 你來到了天梟教的練武場, 你看見這裡有許多的小
 徒弟在這裡練功, 你看看這些小徒弟, 你發現他們不過
 是剛學成靈翼八步訣的小新手, 而且武功很差, 還不會
 天嘯匕法, 所以在這練習。 
 
LONG
    );
 
 set("exits",(["north":__DIR__"bird26",
               "east":__DIR__"bird20",
     ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",80);
        set("mob_amount",4);    
        set("mob_max",12);
        set("mob_object",({     
            __DIR__"npc/fighter",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
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
