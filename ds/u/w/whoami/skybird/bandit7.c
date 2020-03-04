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
                "west":__DIR__"bandit6", 
                "southeast":__DIR__"bandit8",
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();

}

