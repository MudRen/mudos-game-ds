#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIB "�|����" NOR , ({ "ewoks" }) );
        set("race","�H��");
        set("gender","�k��");
        set("age",25);
        set("level",13);
        set_skill("dodge",40);
        set("env/wimpy", 25);
        set("long",HIB "�|�����O�@�ثܧC�����ͪ��C" NOR);
        set("chat_chance",5);
        set("chat_msg",({
                (: "random_move" :),
        }) );

        setup();
}