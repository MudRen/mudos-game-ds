#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѱ��u��",({"guard",}));
 set("long",@LONG
�A�ݤF�@�ݳo�@�ө���j�Ъ��u�áA�u���L���Ӷ��޷L�L��
�_�A��M�ҭ׽m�����\�ä��`�p�A���@����x�o���W�L��A
�Q�ӥ~�a�\�Ҥ��e�p��E
LONG
     );
 set("attitude","peaceful"); 
 set("age",28);
 set("gender","�k��");
 set("level",33);  
 set("max_hp",8000+random(3000)); 
 set("max_ap",8000); 
 set("str",80); 
 set("dex",80);  
 set("Merits/bar",8); 
  set_skill("sky-dagger",75);
 set_skill("dagger",70);
 set("chat_chance",3);
 set("chat_msg", ({"�ѱ��u�èⲴ���n�ۧA��.... .\n",
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

