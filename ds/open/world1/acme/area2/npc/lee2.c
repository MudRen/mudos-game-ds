#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����",({"wen don lee","lee"}) );
        set("long","�L�O�K�����@�k���@�A�L�@�ܤj���A������Z�A�ݰ_�ӫ­������C\n");
        set("age",33);
        set("race","�H��");
        set("level",25);
        set("title","�q�K�����r�@�k");
        set("gender", "�k��" );
        set("chat_chance",5);
        set("chat_msg",({
            "�������ۻy�a���D�G�o�ӬI�������⨸�Ф@�z�H�è���h�F�C\n",
            "�������ۻy�a���D�G�L�|���|�⨸�Ф@���H�è���̥h�F�C\n",
        }) );
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set_skill("parry",40);
        set_skill("bagi_fist",60);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert bagi_fist"):),
                  (: random_move :),
        }) );
        setup();
}
