#include <ansi.h>
inherit SELLMAN;
inherit NPC; 
void normal_ai();
void combat_ai();void create()
{
        set_name( "����", ({ "tao chaung","tao","chaung"}));
set("long", 
"�o�O�@�Ӥw�g�h�����򪺦���ǤH�A�ڻ��L�����쳺�M�O���@��\n"
"�p�c�H�I�p���L�]�h����ѱ������h�ӨӹL�L�L�~�L�{���s���\n"
"���C�A�i�H�ݬݥL�쩳�b�椰��I�ġK�K\n");

        set("level",35);
        set("gender", "�k��");
        set("race", "�H��"); 
        set("age", 56);
        set("evil",-20);

        set("str",70+random(10));
        set("dex",70+random(10));
        set("Merits/bar",6+random(3));
        set("max_hp",6000+random(2000)); 
        set("max_ap",15000+random(2000));
        set_temp("apply/damage",180+random(50));
        set_temp("apply/armor",180+random(50));
        set_skill("unarmed",100);   
        set_skill("bagi_fist",100);  
        set_skill("force",100); 
        set_skill("bagi_force",100); 
        set_skill("parry",100); 
        set_skill("dodge",100);       

   set("attitude", "peaceful");   
/*
   set("sell_list",([   
           __DIR__"obj/bag"    : 25, 
           __DIR__"obj/dump"   : 10, 
           __DIR__"obj/pill1"  : 30,  
      ]) );
*/ 
  set("chat_chance", 30);
  set("chat_msg", ({       
  "�������G�֦b�s�椤�K�K\n",
  (:command("smile"):),
  (: normal_ai :),
  }));
  set("chat_chance_combat",1000);
  set("chat_msg_combat", ({
  (: combat_ai :),
  }));
      setup();
      add_money("coin", 4000+random(1500));       
      carry_object(__DIR__"obj/pill1");
}

/*
void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
*/

void normal_ai()
{
        /* �S��exert ,�hexert */
        if( !this_object()->query_skill_mapped("unarmed") )
                command("exert bagi_fist");       
        if( !this_object()->query_temp("skill_active/bagi_force"))
                command("exert bagi_force power_up");      
        return;
}
 
void combat_ai()
{
        int i;
        object *target;

        target = all_inventory(environment(this_object()));
        
        if(random(5)>3){        command("say �ѤҴN���A���D�K�������O�n�۷S���I�I");
        }
        if( !this_object()->query_temp("skill_active/bagi_force"))
                command("exert bagi_force power_up");      

        /* �Z���Q�����A�h�˦^�h */
        if( !this_object()->query_temp("weapon") ) 
                command("wield fist");

        /* �ĤH->attack */
        command("exert bagi_fist");
        this_object()->start_busy(-2); 
        this_object()->add_temp("exert_mark/bagi-power",100);
        return;
}
