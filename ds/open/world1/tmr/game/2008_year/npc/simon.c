#include <ansi.h>
inherit NPC;
inherit LOTTERYMAN;
void create()
{
        set_name( "賽門", ({ "simon mouse", "simon", "mouse"}));
        set("long", @LONG
艾文是「鼠來寶」三兄弟中的老大，是可愛的花栗鼠，
長的高大但是沉默了點，不僅會說話，還很會唱歌。
LONG
        );
        set("level", 1);
        set("title", HIG"鼠來寶"NOR);
        set("gender", "男性");
        set("race", "人類");
        set("age", 15);
        set("exp",1000);
	set("attitude", "peaceful");   //溫和的 NPC。
	set("no_kill",1);
	set("no_fight",1);

    setup();
}
