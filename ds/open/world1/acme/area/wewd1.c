//釣魚樂  Edit By -Acme-

#include <ansi2.h>

#define Y_SIZE 10       //直座標
#define X_SIZE 30       //橫座標
                        //大小改這裡就行了...
                        //直座標 乘上 橫座標 大於某一數值將會有BUG

#define FISH   10       //數量亂數，越大出現機率越低

inherit ROOM;
string being(int i);
mixed *area=allocate(Y_SIZE);
int fishing(object me,object obj,int yy,int xx);

void create()
{
        set("short", "溪邊");
        set("long", @LONG
這是小溪旁的小路，往西可看見一座木橋，木橋下的小溪清澈見底，
還可瞧見溪中的小魚兒自在的游著，溪旁有許多的釣客在此垂釣，似乎收
獲可觀，釣客不由自主的微笑著。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"pons",
		"east" : __DIR__"pass8",
	]));
	set("objects",([
		__DIR__"npc/shipman" : 3,
	]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
