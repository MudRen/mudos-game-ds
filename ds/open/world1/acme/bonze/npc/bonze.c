#include <ansi.h>
inherit NPC;
void create()
{
        set_name("必清" , ({ "bi ching bonze","bonze" }) );
        set("level",4);
        set("race","人類");
        set("gender","男性");
        set("age",15);
        set("title","凌雲寺小和尚");
        set("long","他是凌雲寺的小和尚，正愁眉苦臉，不知在苦惱什麼。\n");
        set("chat_chance", 3 );
        set("chat_msg",({
           "必清說道：唉，監寺師叔又叫我掃地了。\n",
          (: random_move :),
        }) );
        setup();
carry_object(__DIR__"wp/staff2")->wield();
}
