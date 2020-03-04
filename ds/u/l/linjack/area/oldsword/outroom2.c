#include <room.h>
inherit ROOM;
void create()
{
 set("short","侍衛休息室");
 set("long",@LONG
這邊是向雲堂大門外給侍衛平時休息的簡陋休息室, 
裡面有兩三名侍衛正在吃著小菜談天, 看起來他們都已
經疲憊不堪了. 還有個小樓梯往下走.
LONG
    );
 set("exits",([ "east":__DIR__"outroom1",
                "down":__DIR__"outroom5",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}