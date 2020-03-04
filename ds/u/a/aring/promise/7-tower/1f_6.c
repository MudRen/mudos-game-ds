#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIC"靜心殿堂"NOR);
        set("long", @LONG
一走入殿堂內，便可感覺到一股莊嚴的氣息從裡頭散出，兩旁的
雕像似乎在指引著什麼似的，在旁有兩盞破燈，一處亮著，但一處則
熄滅，不知有何用意。
LONG);
        
        set("no_recall", 1); 
        set("no_quit",1);       
        set("item_desc",([
     "破燈": HIW"\n此破燈似乎很久沒有點燃(fire)了？\n"NOR,
        ]));
         set("objects", ([ /* sizeof() == 1 */
          __DIR__"lamp" : 1,
        ]));
        set("world", "past");
        set("no_clean_up", 0);
        set("light",0);

        setup();
}  

