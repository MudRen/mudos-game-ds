#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѱ��@���",({"wood guard","guard"}));
 set("long",
"���e�o�ǰ��j���ު��j�Ӥl�O�Ѥѱ��бЦʤ���@���̤l\n"
"�ҥ��L�̳��O�g�L�Ż}�@�@�N�N����u�o�ʯ���, �åB��\n"
"���D�ѱ��Ъ��~�H�a��, ���ѱ��������ϥL�̤��A�ӻ{��\n"
"��, �]�i���F�L�̲{�b�o�ب��H�N�����ߩ�.....\n"
     );
 set("attitude","aggressive"); 
 set("age",31+random(5));
 set("gender","�k��");
 set("level",35); 
 set("max_hp",12000+random(8000));
 set("max_mp",12000); 
 set("max_ap",12000);

 set("str",80+random(15));
 set("dex",125+random(30)); 
 set("int",85+random(5));
 set("con",85+random(5));
 set("Merits/bar",6+random(5));
 set("Merits/wit",4+random(5));

 set_temp("apply/armor",95+random(18));
 set_temp("apply/damage",85+random(22));
 set("combat_experience",1500000);

 set_skill("unarmed",100);  
 set_skill("dodge",100); 
 set_skill("parry",100); 
 set_skill("gun",100);
 set_skill("combat",100);
 set("chat_chance_combat",200);
 set("chat_msg_combat", ({
      (:command("say ��! �ѱ��Z�O�A�n��?"):),
      (:command("shoot"):), 
      (:command("reload bolt"):),
                         }));
 setup();
 carry_object(__DIR__"eq/owl_pants")->wear();
 carry_object(__DIR__"eq/owl_cloth")->wear();
 carry_object(__DIR__"eq/owl_bow")->wield();
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
}
 
void init()
{       
        ::init();
        command("reload bolt");
}

