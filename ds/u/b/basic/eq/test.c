#include <ansi.h>
inherit NPC;
void kiss_delay(object me);
void create()
{
        set_name(HIM"����",({ "ching ching","ching"}));
        set("long","Basic like ���H�C�C\n");
        set("level", 1);
        set("gender", "�k��");
        set("age",17);
        set("chat_chance", 8);
        set("chat_msg", ({
       (:command("smile"):),
"������:basic�ڥͤ�֨�F��!!�C",
}));
        setup();
}
int accept_object(object who, object ob)
{
        object tob, a;
        tob = this_object();
        if( ob->query("id")!="necklace" || query_temp("necklace") ) return 0;
        command("blush");
        command("kiss"+who->query("id"));
        command("say �A�n�Q����...���§A.�ڦn������~basic~");
        return 1;
}
