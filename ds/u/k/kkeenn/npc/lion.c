#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIY"�K��E�ɬ��n"NOR,({"iron-lion ue-lin-lon","lion"}) );
  set("long",@LONG
�e�O�u�@���n�����W�d�~�w�[���N����A�����^�����K���_�ҡA
����U�c�����w�g����A�L�ê��O�n�O�@�e�Ҧu�@�������A�K��
�~�w���۰d�A�o�˪��믫�A�`�`���s�b���n�����W�U�A�N�O�q��
�o�˪��믫�A�ҥH���n���W�U�@��F������A�K��U���䪺�u�@
�A�@�۪������C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",1032);
  set("level",42);
  set("attitude", "heroism");
  set("limbs", ({ "�Y��", "����","�ݳ�","�~��","�~�}","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  add("addition_armor",90);
  add("addition_damage",80);
  setup();
 /*
  carry_object(__DIR__"eq/lion_armor.c")->wear(); 
  carry_object(__DIR__"eq/lion_waist.c")->wear();
  carry_object(__DIR__"eq/lion_ring.c")->wear();
  carry_object(__DIR__"wp/lion_claw.c")->wield();
*/
}
void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }
message("world:world1:vision",
        HIY"\n\n    �K��E�ɬ��n���G\n\n"NOR
        HIR"            ���n�����Ѥ֡A�ڵL�k�u�@�A�̡A�u�O��p�A�çO�F�I\n\n"NOR, 
        HIW"            "+ob->name(1)+"�u�O�F�`�A�N�Ӥ@�w�O�Z�L�����_�~���\n\n"NOR,
        users());
        ob->add("popularity", 2); //�n��
        tell_object(ob,HIC"�A���ѤF"HIY"�K��E�ɬ��n�A�A�i�o��2�I�n��I�I\n"NOR);
        ::die();
        return;

  }

