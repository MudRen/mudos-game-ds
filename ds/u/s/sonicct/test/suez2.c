#include <ansi.h>
inherit NPC;
void create()
{
         set_name(HIG"��Ĭ�l�_"NOR, ({"pig suez","suez2"}) );
        set("long", "��\n");
        set("race", "�H��");
        set("age", 24);
        set("level", 1);
        set("attitude", "heroism");
        set("chat_chance",100);
       set("chat_msg",({
  (: command("say ��Ĭ�l�_") :),
}));
        setup();
}
