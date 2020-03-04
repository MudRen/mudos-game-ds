#include <room.h>
inherit ROOM;
void create()
{
 set("short","休息室走道");
 set("long",@LONG
這邊和對面的外賓客房正好相反, 這裡的房間全是給向雲堂
內的部屬在休息的地方. 走道十分乾淨, 只是沒有像客房走道那
麼華麗而已. 有一些剛休息完的人在這邊走來走去, 但因為你的
來到而感到有點不安.
LONG
    );
 set("exits",([ "north":__DIR__"inroom41",
                 "east":__DIR__"inroom7",
                "south":__DIR__"inroom42",
                 "west":__DIR__"inroom43",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
