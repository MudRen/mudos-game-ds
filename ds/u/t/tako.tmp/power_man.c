#include <ansi.h>
inherit NPC; 
void create()
{
        set_name(HIC"�F�C"HIW"��"NOR, ({ "shura-sword king","king" }) );
        set("long","�F�ɪ���ɪ̡C\n");
        set("level",50);
        set("age",300);

        set("combat_exp", 16047);  
      //set("max_hp",25000);        set("chat_chance_combat",10);
        set("chat_msg_combat",({ 
            (:command("wield sword"):),
            "�F�C�����D:�m��Ʈ� �m��Ư� ....\n",
          }) );  
          set("title","�C�F�ɸt��");
          set("nickname",HIC"�C�F"NOR);                set_skill("combat", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100 );
        setup();
        carry_object("/u/t/tako/power=sword")->wield();
        }

