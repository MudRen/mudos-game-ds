#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѱ��в�",({"apprentice",}));
 set("long","�A�s�y�ݤF�@�ݳo�Ӧ��G�u���Q���j���̤l�A�Q�ӥL�@�w\n"
            "�O��L�ѱ��̤l���a���A���L�a���k�a���A�ݥL�⤤�P��\n"
            "���Ӵ��h�ˤ]�ᦳ���k�A��M�ä��n�ۭt.\n"
     );
 set("attitude","peaceful"); 
 set("age",12);
 set("gender","�k��");
 set("level",15);
 set("max_hp",6000);
 set("str",40);
 set("Merits/bar",2);
 set("title", "�ѱ��вĤE�N�в�");
 set_skill("unarmed",80);
 set_skill("dagger",40); 
 set_skill("dodge",40);
 set_skill("parry",40);
 set_skill("sky-dagger",40);
 set("chat_chance",5);
 set("chat_msg", ({"�ѱ��̤l��۪Ť����T�P�I\n",
                   "�ѱ��̤l���ʤP���A�f�����������K�K\n"
 }));
setup(); 
carry_object(__DIR__"eq/owl_cloth")->wear();
carry_object(__DIR__"eq/owl_armor")->wear();
carry_object(__DIR__"eq/grass_boots")->wear();
carry_object(__DIR__"eq/dagger")->wield();
}

