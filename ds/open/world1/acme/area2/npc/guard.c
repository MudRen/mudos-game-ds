#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�a�B", ({ "guard" }) );
        set("gender", "�k��" );
        set("long",
            "�@�Ӭݺ޵۬I���j�����a�B�C\n"
           );
        set("age",45);
        set("level",10);
        set("chat_chance", 2);
        set("chat_msg", ({
                "�a�B���D�G�o�X�ѳ\\�h�H�ӧ�ѷݡA�����Ҭ���ơH\n"
                "�a�B���D�G�O�ڡI�N�s�U�����Ѥ]�ӤF�I\n"
        }));

        set("chat_chance_combat",90);
        set("chat_msg_combat", ({
                "�a�B�H���D�G�c��I�h���a�I\n",
         }) );
        setup();
}
