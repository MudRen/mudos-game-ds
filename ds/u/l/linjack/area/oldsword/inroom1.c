#include <room.h>
inherit ROOM;
void create()
{
 set("short","後偏廳");
 set("long",@LONG
這是向雲堂的後偏廳, 雖然比正廳要小的多, 不過感覺
起來讓人倍感溫暖, 而且裝潢更加富麗堂皇, 你的前方有張
鋪著虎皮的大椅子, 應該是平常時堂主在休息時坐的椅子,
椅子旁有個通道, 不知道通往哪裡.
LONG
    );
 set("exits",([
               "north":__DIR__"hall5",
                "east":__DIR__"inroom2",
                "west":__DIR__"inroom3",
               "south":__DIR__"inroom65",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
