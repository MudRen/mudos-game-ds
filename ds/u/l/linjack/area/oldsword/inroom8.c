#include <room.h>
inherit ROOM;
void create()
{
 set("short","茶樓");
 set("long",@LONG
這邊是向雲堂的餐館, 有幾個廚子和送菜的小僕在忙進忙出,
聽說這邊平時對外賓也有開放, 可以來此買兩盤小菜或一壺茶來
解解飢渴, 而開辦大宴時, 大家則以正廳為中心開桌吃飯. 這邊
有一些各地來的旅人在此歇腳, 你望外看去, 可以看到壯觀的屋
頂花園! 有許多園丁正在慢慢的照顧他們心愛的花草.
LONG
    );
 set("exits",([ "down":__DIR__"inroom62",
               "north":__DIR__"garden1",
                "east":__DIR__"garden2",
               "south":__DIR__"garden3",
                "west":__DIR__"garden4",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
