#include <ansi.h>
inherit NPC;

void create()
{
       set_name("��l��",({"tsai tsi yuin","tsai","yuin"}));
       set("long",@LONG
    ��l���A��l�¥S�f�Ҭ��K�������Ѥ媺�o�N�̤l�C�䤤��l��
�өʯժ��A�������A�M��K�����Q�Ʀ~�ש󦨴N���Z���Z���C�Z�L
���H���٨�G�u�������s��|���A�_�L�p�p�e�E�ѡC�v�o�����v����
�O���F��f���W���J�e�A���O���G�D�J�F����x���A���o��w�\�Z�L
���L�Ȧb�o�̫s�n�Į�A���Y��դ����ұ��C
LONG);
       set("gender","�k��");
       set("age", 30);
       set("level", 30);
       create_family("�K���� ",7,"�̤l");


       set("str", 70);
       set("con", 70);
       set("guild_gifts",({10,7,0,3}));

       set_skill("unarmed", 90);
       set_skill("parry", 70);
       set_skill("dodge", 50);
       set_skill("bagi_fist",97);
       set_skill("horse-steps",97);


       set("chat_chance", 20);
       set("chat_msg", ({
            (:command("sigh"):),
        (:command("exert bagi_force power up "):),
        (:command("exert bagi_force armor "):),
            (:command("exert bagi_fist"):),
            (:command("exert horse-steps down-power "):),
            (:command("exert horse-steps ten-power "):), 
            (:command("exert horse-steps twine-power "):),
        (:command("exert bagi_force heal "):),
            "��l���b�o�̨��L�ӡ��S���L�h���N�o�ˤ@�����Ө��h�C\n",
            (:command("say �w�g��F�o�B�Цa�A���|��M�o�ˡH�o�Ӧp��O�n�� "):),                  
             }));


        set("chat_chance_combat",30);
        set("chat_msg_combat", ({
                  (:command("exert bagi_fist"):),
        }) );

    
        setup(); 

      carry_object(__DIR__"wp/fire-bird_craw")->wield();
}
int special_attack()
{
        int hp ,max_hp ,ppl_hp,ppl_maxhp;
        hp=this_object()->query("hp");
        max_hp=this_object()->query("max_hp");
        ppl_hp=this_player()->query("hp");
        ppl_maxhp=this_player()->query("max_hp");
/*
      if(environment(this_player())!=environment(this_object())) 
      {
      say ("��l�����F�U�ӦR�ǤF�X�f�A�ݰ_�ӥL����O��_�F����");
      this_object()->receive_heal("hp",700);
      this_object()->receive_heal("ap",700);
      this_object()->receive_heal("mp",700);
       return 0;
      }
*/
        if(hp<max_hp/2 )
      {
      if(this_object()->query("mp")<70) return 0;
      if(random(7)) return 0;
      this_object() -> receive_damage("mp", 70);      
      say (HIY"��l�����W�����j�ܤ@�n�I�y�ɥL���W�u��y�ʡA�ݥL�i�}������G����󦳺믫�F�C\n"NOR); 
      this_object()->receive_heal("hp",500);
      this_object()->receive_heal("ap",300);
       return 1 ;
      }
        
        if(ppl_hp<ppl_maxhp/7)
      {
         command("exert bagi_fist");
         return 1;  
      }
}

