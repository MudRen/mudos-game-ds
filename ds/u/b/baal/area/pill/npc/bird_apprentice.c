#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѱ��Q�K�N�̤l",({"apprentice",}));
 set("long","�A�s�y�ݤF�@�ݳo�Ӧ��G�u���Q���j���̤l, �Q�ӥL�@�w\n"
            "�O��L�ѱ��̤l���a��, ���L�a���k�a��, �ݥL�⤤�P��\n"
            "���Ӵ��h�ˤ]�ᦳ���k, ��M�ä��n�ۭt.\n"
     );
 set("attitude","peaceful"); 
 set("age",12);
 set("gender","�k��");
 set("level",10);
 set_skill("unarmed",20);
 set_skill("dagger",20);
 set_skill("sky-dagger",10);
 set("chat_chance",5);
 set("chat_msg", ({"�ѱ��̤l��۪Ť����T�P! \n",
                    "�ѱ��̤l���ʤP��, �f����������...\n"
}));
setup(); 
carry_object(__DIR__"eq/owl_cloth")->wear();
carry_object(__DIR__"eq/owl_armor")->wear();
carry_object(__DIR__"eq/grass_boots")->wear();
carry_object(__DIR__"eq/dagger")->wield();}

