#include <ansi.h>

inherit NPC;

void create()
{
          set_name(HIY"�E"HIW"��"NOR,({ "tsz joaur","joaur" }));
          set("long","���f�ɤ�,�y�L�U��,������������\n", );
             
              set("level",60);
              set("age",1452687);
              set("combat_exp",30000);
            //set("max_hp",25000);
              set("chat_chance_combat",10);
              set("chat_msg_combat",({
              ( :command("wield blade"):),
                "�E�׻�:�A�̦n���n���ڥX�h,�n���M.........\n",
                "�E�׻�:�A�N���F....!!\n",
                }) );
              set("title","�ӥj�Ҥ�");
              set("nickname",HIY"��z�٬�"NOR);
              set_skill("blade",100);
              set_skill("dodge",100);
              set_skill("combat",100);
              set_skill("parry",100);
              set_skill("unarmed",100);
              setup();
              carry_object("/u/t/tako/tiger^^blade.c")->wield();
              

}

