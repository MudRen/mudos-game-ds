#include <ansi.h>
inherit NPC;
void create()
{
set_name("���d�s��", ({"lanka thief"}) );
set("age",30);
set("long","���d���Ӫ��s��C\n");
set("level",10);
set("attitude", "aggressive");
set("chat_chance",50);
set("chat_msg",({(: random_move :)}));
setup();
}

