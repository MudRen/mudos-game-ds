#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIW "Naboo��"HIY"�~��" NOR , ({ "naboo citizen","citizen"}) );
        set("race","�H��");
        set("gender","�k��");
        set("age",25);
        set("level",15);
        set("long",HIW "�o�ӬO��bNaboo�����~�� \n"NOR);
        set("chat_chance",70);
        set("chat_msg",({
	(: "random_move" :),
        }) );
        setup();
}