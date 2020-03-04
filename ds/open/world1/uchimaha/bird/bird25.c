#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit MOBROOM;
void create()
{
 set("short",HIC"天梟教"NOR"練武場");

 set("long",@LONG
 你來到了天梟教的練武場, 這裡是專門給大徒弟練
 功用的, 這裡的匕首多的不盡其數, 你看到他們正在學
 習旁邊天梟石像的姿式, 每個人的姿式都不一樣, 他們
 就在這裡練習靈翼八步訣。
 
LONG
    );
 
 set("exits",(["south":__DIR__"bird23",
               "west":__DIR__"bird21",
               "east":__DIR__"bird27",
     ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",80);
        set("mob_amount",3);    
        set("mob_max",10);
        set("mob_object",({     
            __DIR__"npc/fighter2",
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
