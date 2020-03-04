#include <ansi.h>
inherit NPC;
void normal_ai();
void combat_ai();
void heal();
void create()
{
 set_name("���M�y",({"chiang chin liu","chiang","chin","liu"}));
 set("long","�L�N�O�L��k���j�̤l�w���M�y�E�@���Z�\\�ҨӦ۱L��k���u��\n"
            "�A���~�\\���\\�O�۵M���b�ܤU�A�A�[�W�L����L�M�q���@���A�]\n"
            "���LĹ�o�F�y�Q�U�L���z���ʸ��E���L�A�ݥL���Y�`��A��M�O\n"
            "�J��F���j���x���E\n");
 set("attitude","peaceful"); 
 set("age",33);
 set("gender","�k��");
 set("level",38);
 set("title",HIR"�Q�U�L��"NOR); 
 set("str",75+random(10));
 set("dex",75+random(10));
 set("Merits/bar",5+random(3)); 
 set("Merits/wit",3+random(3));
 set("max_hp",6000+random(3000)); 
 set("max_ap",6000+random(3000));
 set("evil",-350);
 set_temp("apply/armor",75+random(18));
 set_temp("apply/damage",75+random(30));
 set_skill("dagger",100);
 set_skill("sky-dagger",100);
 set_skill("unarmed",100);
 set_skill("dodge",100);
 set_skill("parry",100);

 set("chat_chance",5);
 set("chat_msg", ({"���M�y�ĤF�f����.... \n",
                   "���M�y�Ĥf��:�u�O�@�����N��½�@��H��....\n",
                   "���M�y���ۻ�:�i�O�ڭ̭��̨S�j�L?....\n",
                   "���M�y���M���D:���D�S�^��Ѥѥj��W���N�ޤF?....\n",
                   (: normal_ai :),  }));
 set("chat_chance_combat",300);
 set("chat_msg_combat", ({
 (: combat_ai :),
 }));
setup(); 
carry_object(__DIR__"eq/cloth")->wear();
carry_object(__DIR__"eq/sob_dagger")->wield();
}

void heal()
{
    object me=this_object();
    message_vision(HIC"$N�q�h���ǥX�@�~�p�~�l�A�N�~���G���٦b�ˤf�B�A�ˤf�K���_��¡�X�F�E\n"NOR, me);              
    me->receive_heal("hp",random(800));
    me->receive_heal("mp",random(1000));
    me->receive_heal("ap",random(1000));
    return;
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
CYN"\n  �Z�L�ǥX�F�@�h��H������:\n\n\t�y"HIR"�Q�U�L��"NOR+CYN"�z"HIR"���M�y"NOR+CYN"�~�M�Ѧb"+ob->name(1)+"����W�C\n\n"+NOR
        ,users());
        ob->add("popularity",2); 
       tell_object(ob,HIW"(�]���A�����F���M�y�A�ҥH�o��F 2 �I�n��C)"NOR);
        ::die();
        return;
}

void normal_ai()
{
        /* �S��exert ,�hexert */
        if( !this_object()->query_skill_mapped("dagger") )
                command("exert sky-dagger");       

        /* ���ˮɦۧ����� */ 
        if( this_object()->query("hp") < (this_object()->query("max_hp")/2) )
                heal();

        return;
}
 
void combat_ai()
{
        int i;
        object *target;

        target = all_inventory(environment(this_object()));

        /* �Z���Q�����A�h�˦^�h */
        if( !this_object()->query_temp("weapon") ) 
                command("wield dagger");

        /* ���ˮɷ|�ۧ�����  */
        if( this_object()->query("hp") + 1000 < (this_object()->query("max_hp")/4) )
                heal();

        /* �ĤH->attack */

        command("exert sky-dagger");
        this_object()->start_busy(-2);

        return;
}
 
int accept_object(object who,object ob)
{
        object obj=this_object();
        if(ob->name()!="�N��"){
           command("? "+who->query("id"));
           command("say �b�U�ä��ݭn�o�ӪF��C");
           return 0;
        } else {
           if( obj->is_busy() || obj->query_temp("meet_eagle") ){
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C");
             return 0;
           }
           
        message_vision("$N���F���M�y�@��"+ob->query("name")+"�C\n",who);
//             obj->start_busy(10);
             obj->set_temp("meet_eagle",1);
             destruct(ob);
             call_out("meet_eagle",1,obj);
             return 1;
        }

}

void meet_eagle()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("meet_eagle");
      switch( i ) {
          case 1:
            command("say ��! �o���O���N���N�ж�?");
            command("say �o��"+RANK_D->query_respect(me)+"�O�q��o���N�Ъ��H");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 2:
            message_vision(YEL"$N�N�o���N�Ъ��L�{�i�D���M�y�C\n"NOR,me);
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 3:
            command("nod");
            command("soga");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 4:
            if(me->query_skill("sky-dagger") == 0) 
            {
            command("say �v���`���ѼS�P�k�i�¦��t���H");
            command("say �p�o��"+RANK_D->query_respect(me)+"������, �N�гo��"+RANK_D->query_respect(me)+"�@�[!");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            } else {
              command("say �u�i���b�U�L�H���� ..�Ш��b�U�@��!");
              command("bow");
              obj->delete_temp("meet_eagle");
            }
            break;
          case 5:
            message_vision(YEL"���M�y�N�ѼS�P�k���򥻤߳Z���ѵ�$Nť.\n"NOR,me);
//            message_vision(HIY"(~~~~~�@~~~~~��~~~~~��~~~~~��~~~~~�L~~~~~�h~~~~~�F~~~~~)\n"NOR,me);      
            message_vision(HIY"���M�y���D:�j�L�G�M�O�_�H, �o�ѼS�P�k����p���֪��⮩!!\n"NOR,me);
            command("smile");
            for(int x=0;x<5;x++)
            me->add_skill("sky-dagger");
            obj->delete_temp("meet_eagle");
            break;
            }
} 


