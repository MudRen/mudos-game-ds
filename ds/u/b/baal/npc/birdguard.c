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
 set("combat_exp",124753+random(38358));
 set("level",15);
 set_skill("unarmed",50);
 set_skill("force",30);
 set("guild_gifts",({10,4,0,6}));
 set("chat_chance",10);
 set("chat_msg", ({"�ѱ��u�èⲴ�n�ۧA��.... .\n",
}));
 set("chat_chance_combat",200);
                         (:command,"say ���D�ѱ��H�H�i��!!  ":),
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
