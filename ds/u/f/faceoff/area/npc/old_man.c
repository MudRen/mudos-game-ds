#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѤH",({"old man","man"}));
 set("long",@LONG
�@�Ӻ����K�����ѤH.
LONG
    );
 set("attitude", "peaceful");
 set("age",72);
 set("gender","�k��");
 set("level",20);
 set_skill("sky-dagger",20);
 set("chat_chance_combat",200);
 setup();
}