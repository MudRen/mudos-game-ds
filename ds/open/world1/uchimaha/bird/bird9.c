#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","石階");

 set("long",@LONG
你往前又走了一段距離, 來到一個石階底下, 你抬
起頭來看了看北方, 有一條長長的石階往北邊延伸出去,
你抬頭看了看天空, 發現這裡的天上, 有許許多多的鳥
在天空中飛行, 並且是往北邊飛去。 

LONG
    );
 
 set("exits",(["northup":__DIR__"bird10",
               "west":__DIR__"bird8",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
