//�i���b�g�s��new skill,�ҥH�ɥίe������sorgi_sword�Mmoon_force 
//�M�wQC�L��skill-[cloudsteps]�Ӱ����U,��sk [Sorgi_sword 70,Moon_force 100,cloudsteps 100]
//��mob���S���O�����,�ޥ�Tmr���@�~ 
//�S�\��[�R�C���j],����v��30%,����delay 2��
//Edit by Promise@DS 04/1/31
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�h�֯u",({"huai shao zhen","huai","shan","zhen"}));
        set("long" ,
"�x�ޤѦa�ܤƤ��H�A�㦳���a�۵M�Ѿܯ��O���H�C�O���Z�L
�A�M��e�P�N������˳˳�̡C\n");
        set("nickname", HIY"��Ѳ�"NOR );
        set("attitude", "friendly"); 
        set("age", 30);
        set("gender","�k��");
        set("combat_exp", 1200000);
        set("level", 45);
        set("title","�m"HIW"���{ "HIG"��"NOR"�n" );
        set("max_ap",4000); 
        set("max_mp",4000);
        set("max_hp",10000);
        set_temp("apply/armor",20);
        set("str",300);
        set("dex",300);
        set_skill("cloudsteps",100);
        set_skill("unarmed", 70);
        set_skill("sword",100);
        set_skill("moon_force",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("sorgi_sword",70);
        map_skill("sword","sorgi_sword");
        map_skill("dodge","cloudsteps");
        set("chat_chance",8);
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command,"exert sorgi_sword":),
  (:command,"exert sorgi_sword":),
  (:command("exert moon_force recover"):),
}));
        setup();
        carry_object(__DIR__"wp/sky-rainbow-sword")->wield();
        carry_object(__DIR__"eq/ghost-cloth")->wear(); 
        carry_object(__DIR__"eq/cloud-boots")->wear();
}
varargs int receive_damage(string type, int damage, object who)
{
        int val;

                if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who); 


                if(random(100)<50)
                {
                                damage/=2;
                                message_vision(HIG"\n$N�ߩ��@��A����R�C��¶�b$N�ǡA�����ɱ��F�ֳ\\���ˮ`�I�I\n" NOR,this_object());
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);

                return damage;
} 
 int special_attack(object me,object target,int hitchance)
{
  int tdex,tcon,damage;  
  damage = random(me->query_skill("sword") + 600);       
  if(!me || !target) return 0;
  if(random(10)) return 0;
  tdex=target->query_dex();
  tcon=target->query_con();
  if( random(hitchance*30) > tdex+tcon )
  {
message_vision(HIW"\n�h�֯u�f�����ۻy�G"HIG"�I�R���R�C�A���X�¤O�����A����R�C���H�����I�I\n
"HIM"                             ��  "NOR+MAG"������������������"HIM"  ��           "NOR"
"HIM"                           ���i  "NOR+MAG"����������������"HIM"    �i��         "NOR"
"HIY"                         ���i�i  "HIW"������������������"HIY"  �i�i��       "NOR"
"HIY"                         ���i�i   "HIW"���������~������"HIM"   �i�i��       "NOR"
"HIM"                           ���i  "NOR+MAG" �����~����������"HIM"   �i��         "NOR"
"HIM"                             ��   "NOR+MAG"  ����      ��"HIM"     ��           "NOR"

"RED"                           ���i "HIR"�~������������  ��"NOR+RED"  �i��          "NOR" 
"BLU"                         ���i�i "HIB"�� �������� ������"NOR+BLU"  �i�i��        "NOR" 
"BLU"                         ���i�i "HIB"�� �������� ������"NOR+BLU"  �i�i��        "NOR"       
"RED"                           ���i "HIR" �~�����~����   ��"NOR+RED"  �i��          "NOR" 
"RED"                             �� "HIR" ��  ����  �� ����"NOR+RED"  ��            "NOR" 
"HIR"$n�b�@�}�}�C�B�̡A�Q�Ƭ��u"HIW"�L�W"HIR"�v�B�u"HIM"��B"HIR"�v�B�u"HIY"�妽"HIR"�v�B�u"HIG"�C��"HIR"�v�B�u"HIB"�R�v"HIR"�v�����"HIW"�R"HIR"�C�A�C�C�����n�`�A���h�L��I�I"NOR"("HIR +damage+ NOR")\n"NOR,me,target);
       target->receive_damage("hp",damage, this_object()); 
       target->add_busy(2);    return 1; 
  }
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

        message("world:world1:vision",CYN"
�j���Ĥ@�h�ǥX�F�}�}���s���n�G"HIW+ob->query("name")+HIW"�G�M�O����A�b�U�̫��U���I�I\n
"HIC+ob->query("name")+HIC"���ˤF"HIC"���a�U���Ѿܪ�"HIM"�h�֯u"HIC"��A�~�򩹥j���G���ڶi�I�I\n"NOR        ,users());
        ob->add("popularity", 3); 
        ::die();
        //destruct(this_object());
        return;
}

