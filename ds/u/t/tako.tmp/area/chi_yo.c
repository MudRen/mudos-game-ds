#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"�E��"NOR,({"tsz joaur","joaur"}) );
        set("title", HIC"�ӥj"HIY"�Ҥ�"NOR);
        set("long",
   "���j�ӫ� �E�סv���@���j�ͪ��A���b�L�j�}���P�a���P�� \n"   
   ",�E�״N�s�b�F,�������@�N�Q��,����� ��z ���M ���L\n"
   "���H�Ѧa�٬ӡC\n"); 
        set("level",60);
        set("age",6542879);
        set("attitude", "heroism");

        set("combat_exp",30000);
            //set("max_hp",25000);
        set("chat_chance_combat",10);
        set("chat_msg_combat",({
  (: command("wield blade") :),
  "�E�׻�:�A�̦n���n���ڥX�h,�n���M.........\n",
  "�E�׻�:�A�N���F....!!\n",
}) );
        set("title",HIC"�ӥj�Ҥ�"NOR);
        set("nickname",HIY"��z�٬�"NOR);
        set_skill("blade",130);
        set_skill("dodge",160); 
        set_skill("combat",100);
        set_skill("parry",101);
        set_skill("unarmed",120);
        setup();
        carry_object("/u/t/tako/tiger^^blade.c")->wield();
        carry_object("/u/t/tako/chiyo surcoat.c")->wear(); 
        carry_object("/u/t/tako/chiyo waist.c")->wear();
        carry_object("/u/t/tako/chiyo hold.c")->wear();
        carry_object("/u/t/tako/chiyo boots.c")->wear();
        carry_object("/u/t/tako/chiyo armor.c")->wear(); 
        carry_object("/u/t/tako/chiyo cloth.c")->wear(); 
        carry_object("/u/t/tako/chiyo pants.c")->wear();
}


void die()
{
        object ob,obj;
        if( !ob = query_temp("last_damage_from") )
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision", HIY"\n�i�Z�L�����j"+HIW "�ӥj�Ҥ��u�E�סv���b"+ob->name(1)+"���⤤�C\n\n"+NOR ,users());
        ob->add("popularity", 4);         ::die();
        return;
}

