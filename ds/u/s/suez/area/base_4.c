#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", CYN"飛雲軒"NOR);
	set("long",@LONG
你身旁的土壁上刻了「飛雲軒」三個字，四周有簡陋的梅花樁､木人
以及許多勤奮練功的摘星門弟子。不過看得出來，沒有師父指導的他們，
武功進展實在有限。但是認真的表情卻使你對他們油然生敬。
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "north" : __DIR__"base_5",
               ]));
            set("objects",([
              __DIR__"npc/apprentice1" : 2,
           __DIR__"npc/apprentice2" : 2,
              ]) );
        set("light",1);
	set("no_clean_up", 0);
	setup();
}