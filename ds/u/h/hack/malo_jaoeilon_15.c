#include <ansi.h>
inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("趙毅倫",({"jao ei lon","jao","ei","lon"}) );
	set("long",@LONG
一個小頭銳面的教官這站在這裡東張西望的。
LONG);
	set("age",32);
	set("level",15);
	set("race","human");
            set("master","hack");
	set("evil",-15);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","嘿，只要安分守己我就不會為難你。");
               set("nickname",HIG"三民公車教官"NOR);
setup();

	add_money("dollar",240);
 }