#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","走道");
 set("long",@LONG
一條不太寬也不很窄的走廊﹐左右兩邊站滿了負責守衛的人
﹐個個都狠狠地瞪著你瞧﹐一副要將你吃下的樣子﹐令人不由得
心裡覺得毛毛的﹐不敢直視.
LONG);
 set("exits",([ 
                "east":__DIR__"bandit7", 
                "westdown":__DIR__"bandit5",
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();

}

