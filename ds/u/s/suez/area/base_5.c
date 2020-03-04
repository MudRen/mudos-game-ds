#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"摘星門"NOR);
	set("long",@LONG 
除了四面的牆上掛的火把，這裡就只有那面寫著「摘星門」的匾額，
和通往其他房間的通道而已。雖然簡陋，卻打掃的乾乾淨淨，地上以細石
鋪滿，牆壁也漆上樸素的白色。但是畢竟是個土室，壁上､天花板上偶而
還是會落下些許土屑。
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "east" : __DIR__"base_1",
                   "west" : __DIR__"base_2",
                   "north" : __DIR__"base_3",
                   "south" : __DIR__"base_4",
               ]));
        set("light",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}