#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�s��" , ({"drinker"}) );
set("long", "�@�Ӥ��~���k�l�A�L�C�Ѥ]�Ө�o�̳ܰs�C\n");       
        set("race", "�H��");
        set("gender", "�k��"); 
      set("title",WHT"�y���¦��s���¾K�z"NOR);
        set("age",45); 
        set("attitude", "friendly");
        set("level", 15);
        set("evil", -10);
        set("combat_exp",300);
    set("chat_chance", 2 );  
  set("chat_msg", ({       
(:command("say �n�s~~~�n�s~~~"):),  
"�s�����_�F�@�~�¤h�ҡA�@�f�K�ܤU�h\n",
}) );
        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
        "�s���j�s�G�ϩR~~~~���H�Q����\n",
        }) );
        setup();
        
}

