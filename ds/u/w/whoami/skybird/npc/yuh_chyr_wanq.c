#include <ansi.h>
inherit NPC;
void normal_ai();
void combat_ai();
void heal();
void create()
{
  set_name("�s��k",({"yuh chyr wanq","yuh","chur","wanq"}));
  set("long",@LONG
���H���W���o�X�@�ص±�����A�����p�N�A�������o�۸޲�����
�~�A�����C�ئ��l�A�L�N�O�ѱ��T�t���@�y�s��k�z�E���򤤶�
�D���H���\�w���ܶǩ_���ҡA�A�t�W�@���ѼS�P�k��O�ҦV�L��
�E�G�Q�G�����~�N���g�@�H�W�����R���١A�q���¦W�����E�b�L
�T�Q���������~�A�]���N�����X�ӾɭP�ѱ������A��O�M�ۤ@��
���j�\�O�A���a�����A�ѱ���Z�@���N���ϥ͡E
LONG
    );
  set("attitude","peaceful"); 
  set("age",48);
  set("gender","�k��");
  set("level",45);
  set("title",HIR"�ѱ��T�t"NOR);
  set("Merits/wit", 5+random(5)); 
  set("Merits/bar", 9+random(5));
  set("str",85+random(15)); 
  set("dex",85+random(15)); 
  set_temp("apply/armor",135+random(18));
  set_temp("apply/damage",135+random(30));
  set("combat_experience",2000000);
  set("max_hp",23500+random(1500));
  set("max_ap",8500+random(1500));
  set("class2", "skyowl_military");
  set_skill("unarmed",88);
  set_skill("dagger",100);
  set_skill("force",98);
  set_skill("parry",87); 
  set_skill("dodge",100);
  set_skill("sky-dagger",100);

  set("chat_chance", 300);
  set("chat_msg", ({
(: normal_ai :),
}));
  set("chat_chance_combat",300);
  set("chat_msg_combat", ({
(: combat_ai :),
(:command,"say ��I�I�̧A�]�Q�ʧڤ@�ڴH��H�I":),
}));
 setup();
 carry_object(__DIR__"eq/dragon_dagger")->wield();
 carry_object(__DIR__"eq/sky_cloth")->wear();
 carry_object(__DIR__"eq/sky_boots")->wear();
 carry_object(__DIR__"eq/sky_helm")->wear();
} 

void init()
{
  object me;
 
  ::init();
  if( interactive(me = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  } 
  add_action("do_join","join");
  add_action("do_no_ask","ask");
}

void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  command("hmm");
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
CYN"\n  �Z�L�ǥX�F�@�h��H������:\n\n\t"HIR"�ѱ��T�t"NOR+CYN"���@��"HIR"�s��k"NOR+CYN"�~�M�Ѧb"+ob->name(1)+"����W�C\n\n"+NOR
        ,users());
        ob->add("popularity",3); 
        tell_object(ob,HIW"(�]���A�����F�s��k�A�ҥH�o��F 3 �I�n��C)"NOR);
        ::die();
        //destruct(this_object());
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
        if( this_object()->query("hp") < (this_object()->query("max_hp")/3) )
                heal();

        /* �ĤH->attack */

        command("ex sky-dagger");
        this_object()->start_busy(-2);

        return;
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

varargs int receive_damage(string type, int damage, object who)
{
        int val;
        if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
                if(random(100)<70){
                   damage/=10;
                   message_vision(HIR"\n$N�N�⤤�Z���@��A�פU�F�o�r�P���@���I\n" NOR,this_object());
                }
                }
                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();

     if(me->query("class2")=="skyowl_military") return notify_fail("�A�w�O�ѱ��ЪZ���в��F�C\n");
     if(arg!="skyowl") return notify_fail("�A�n���J���@�Ӫ���?\n");
     if(me->query("class1") != "skyowl" || me->query("class2") ) return notify_fail("�A�ä��O�ѱ��бв��C\n");
     command("say ����..�S���H�Q�n�J�ڪZ���A�M��ѱ��Ф��Z�ǤF..");
     command("say ���L�o�T���E�]�ߪk�i�S�A�Q����������..�S�@�I�Z�Ǯڰ򪺤H�O�Ǥ��Ӫ�..");
     command("say �o�˧a�A�p�G�A�����ѯe���������@�k�A�ڴN�i�H���A�J�ڭ̪Z��.."); 
     me->add_temp("skyowl/military", 1);
        return 1;   
}
