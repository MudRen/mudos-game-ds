#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","地牢");
 set("long",@LONG
這裡是山寨裡的牢房﹐牢房裡面的刑具可以說是應有盡有﹐
似乎比官府牢房裡的刑具還要多。牢房的牆上還鎖著幾個半死
不活的士兵﹐看來即便華陀再世也沒法救活他們了.
LONG);
 set("exits",([ 
                "northwest":__DIR__"bandit8", 
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();

}


