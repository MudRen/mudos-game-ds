inherit NPC;
void create()
{
        set_name("����",({ "villager" }) );
        set("long","�@�ө~��b�y�����������A�ݨӨõL����L�H���B�C\n");
        set("race","�H��");
        set("title","�y����");
        set("age",30);
        set("level",7);
        set("attitude","friendly");
        set_skill("dodge",5);
        set_skill("unarmed",5);
        set_skill("parry",5);
        set("chat_chance",20);
        set("chat_msg", ({"������A��:�p�S�̧A����H�K�N���J�O�H���a�̩O?\n",
                        (:command("sigh"):),
        }));
   setup();
add_money("silver",8);           
}

