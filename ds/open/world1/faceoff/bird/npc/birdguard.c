#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѱ��u��",({"guard",}));
 set("long","             �A�ݤF�@�ݳo�@�ө���j�Ъ��u��, �u���L���Ӷ��޷L
             �L��_, ��M�ҭ׽m����\�\\��\��\�`\�p\, ���@����x�o��
             �W�L��, �Q�ӥ~�a\�\\��\��\�e\�p\��\."
     );
 set("attitude","peaceful"); 
 set("age",35);
 set("gender","�k��");
 set("level",40);
 set_skill("sky-dagger",30);
 set_skill("dagger",40);
 set("chat_chance",4);
 set("chat_msg", ({"�ѱ��u�èⲴ�n�ۧA��.... .\n",
 }));
 set("chat_chance_combat",20);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say ���D�ѱ��H�H�i��!!  ":),
 }));
 setup();
 carry_object(__DIR__"eq/owl_cloth")->wear();
 carry_object(__DIR__"eq/dagger")->wield();
 carry_object(__DIR__"eq/owl_armor")->wear();
 carry_object(__DIR__"eq/grass_boots")->wear();
}

