#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p��", ({ "child" }) );
        set("gender", "�k��" );
        set("long",
            "�@�Ӫ��o����ż�������p�Ĥl�C\n"
           );
        set("age",5);
        set("level",3);
        set("chat_chance", 2);
        set("chat_msg", ({
                "�p�Ļ��D�G�H�H��ӧr�I�ӧ�ڧr�I\n",
                "�p�Ļ��D�G�i�c�I�S�Q�A�k�F�I\n",
        }));

        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                "�p�Ĥj�s�G�ϩR�ڡI�ϩR�ڡI���H�n�����ڰڡI\n",
         }) );
        setup();
}
