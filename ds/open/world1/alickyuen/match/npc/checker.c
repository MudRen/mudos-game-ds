#include <ansi.h>

inherit NPC;

void create()
{
	set_name("比武大會監察人員", ({ "checker" }) );
	set("level", 100);
	set("long", @long
他是比武大會的工作人員，負責檢查玩家有否帶走比武場地之物資。
long);

	setup();
}
