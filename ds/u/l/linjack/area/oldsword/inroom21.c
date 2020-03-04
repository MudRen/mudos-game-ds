#include <room.h>
inherit ROOM;
void create()
{
 set("short","外走道");
 set("long",@LONG
向雲堂最好的風景觀點就是這裡了, 你放眼望去, 將百里景觀
盡收眼底, 發覺自己就好像融入了那種情境當中, 你往下看去, 還
有條頗寬的溪流, 整面牆都是光滑的, 想要從溪水對岸躍過來的, 
必得要有高強的輕功底子, 但為防萬一, 這邊也有數名護衛在看守.
往北走可以到走道外面的草坪.
LONG
    );
 set("exits",([ "south":__DIR__"inroom12",
                "northdown":__DIR__"outroom16",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
