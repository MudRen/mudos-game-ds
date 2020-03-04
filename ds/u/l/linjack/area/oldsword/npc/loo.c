#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�c��",({"loo shang","shang","loo"}));
	set("long" ,
    "�L�N�O�������۰�D���ѵ��B�z�󤤤j�p�ưȪ��H, ���H�Z�\\���j, ���g\n"
    "�O�@�Ӥs�몺��D, ���O�L���y�W���@�S���Q��. ť���b�\\�h\�~�e, �L���g�M\n"
    "���ѵ���W�L, �g�L�ƤQ�۫�, �ש�Ѱ}, �]�ӳQ���ѵ����A, ���ѵ����]\n"
    "�b�ХߦV���󤧪�, �ӿc��K�����ư�D�F.\n"
    );
	set("attitude", "friendly"); 
	set("level",35);
	set("age", 48);
	set("title",HIC"�V����"NOR"�ư�D");
	set("class1","�V����");
	create_family("�V����",1,"�ư�D");
	set("chat_chance",5);
	set("chat_msg",({"�c��C���Y, �����D�b�I�䤰��.",
			 (:command,"hmm":),
			 (:command,"say �o��B��...�c.":),
			 (:command,"exert cloudblade":),
			 (:command,"exert cloudsteps":),
			 (:command,"exert cloudfist":)}));
	set("chat_chance_combat",80);
	set("chat_msg_combat",({(:command,"exert cloudblade":),
				(:command,"exert cloudforce refresh":)}));
	set_skill("unarmed",70);
	set_skill("blade",80);
	set_skill("dodge",85);
	set_skill("force",70);
	set_skill("parry",60);
	set_skill("cloudblade",85);
	set_skill("cloudfist",80);
	set_skill("cloudforce",60);
	set_skill("cloudsteps",80);
	set("guild_gifts",({3,4,6,7}));
	setup();
	carry_object(__DIR__"eq/boots")->wear();
	carry_object(__DIR__"eq/s_blade")->wield();
	carry_object(__DIR__"eq/cloth")->wear();
	carry_object(__DIR__"eq/gloves")->wear();
	set_heart_beat(1);
}
void heart_beat()
{
 object *enemy;
 object me;
 int damage,roll,a,b,d;
 int i,c,hp,max_hp;
 me=this_player();
 roll = random(16);
 if(me->is_fighting())
 {
  enemy = me->query_enemy();
  i = random(sizeof(enemy));
  enemy[i]=present(enemy[i],environment(me));
  c=enemy[i]->query_temp("apply/armor");
  max_hp=me->query("max_hp");
  hp=me->query("hp");
  if( me->is_fighting() && hp < (max_hp/2) && roll < 4)
  {
   if( roll > 2 )
   {
    damage=200+random(50)-c;
    if(damage < 50) damage=40+random(20);
    this_player()->add("ap",-30-random(10));
    message_vision(HIC"\n$N�j��: �ݨӧA�u�O���n�R�F! ���ڦ��W���� ------ \n\n"NOR+
                   "    �y  "+HIY+"�p    "+HIC+"�p    "+HIR+"�e    "+HIM+"��    "+NOR+"  �z�I�I\n\n"+
                   HIW"     ��ѤM�𪽦V$n�g�A�ӥh!!"+HIR+"  �y��$n�@�B�D�`�Y�����A��!\n"NOR,me,enemy[i]);
    damage = COMBAT_D->Merits_damage(me,enemy[i],damage,"bar");
    enemy[i]->receive_damage("hp",damage,me);
    COMBAT_D->report_status(enemy[i],1);
    enemy[i]->add_busy(1);
    me->add_busy(2);
   }
   else if( roll < 3 )
   {
    this_player()->add("ap",-30-random(10));
    message_vision(HIC"\n$N�j��: �ݨӧA�u�O���n�R�F! ���ڦ��W���� ------ \n\n"NOR+
                   "    �y  "+HIY+"�p    "+HIC+"�p    "+HIR+"�e    "+HIM+"��    "+NOR+"  �z�I�I\n\n"+
                   HIW"     ��ѤM�𪽦V$n�g�A�ӥh!!"+CYN+"  ���O$n½���@��, �׶}�F������.\n"NOR,me,enemy[i]);
    me->add_busy(1);
   }
  }
 }
 ::heart_beat();
}

