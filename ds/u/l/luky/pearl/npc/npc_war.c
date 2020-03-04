#include <ansi.h>
inherit NPC;

void create()
{
// �]�wNPC�W�٤�ID
set_name(HIY"���t����"NOR,({"turtle father","turtle","father"}) );
set("long", "�@���­����j���t�A�I�W�٦��@�Ǥp�աC\n");
set("title","���S");
// NPC �ݩ�
set("gender", "�k��");
set("level",40);
set("age",31);
// �����P���m�O
add_temp("apply/armor",340);
add_temp("apply/damage",200);
// NPC���𳡦�
set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"}));
// NPC�����ʧ@����
set("verbs", ({ "bite"}));
setup();
// NPC��a����
add_money("coin",1000);
set_heart_beat(1);
}

void heart_beat()
{
object *enemy;
object me;
int damage;
int i;
me=this_player();
enemy = me->query_enemy();
enemy[i]=present(enemy[i],environment(me));

//�ܨ�����
if(me->query("hp")<8000&& me->query_temp("change")<1) 
{
message_vision(HIR"\n\n�n�å�!!! �ݨӤ����X�u���ƬO����F..\n\n"
+HIB+" �j �� �t �� �I �W �� �M �� �X �\ �h �r �� !!! \n "NOR,enemy[i]);
me->set_temp("change",1);

//�ܨ��ᤧ�W�٤αԭz
me->set_name(HIM"���t"NOR,({"needle turtle","turtle"}));
me->set("long","�@���I�W�����r�몺���t�C"HIR"(�e���G�D�`�ͮ�)\n"NOR);

//�ܨ��ᤧ�ݩ��ܤ�
me->add("str",100);
me->add("dex",100);
me->set("max_hp",8000);
me->set("hp",8000);
me->add("exp",20000);
me->add_temp("apply/damage",300);
me->add_temp("apply/armor",360);
}

//�ܨ��ᤧ�S��]�w
if(me->query_temp("change")==1)
{
 if( me->is_fighting() )
 if(random(300)>200)
    {
damage=700+random(300)-enemy[i]->query_temp("apply/armor");
if(damage<300)
damage=200+random(100);
if(random(100)>50)
message_vision("$N"HIC"��M���A����V�ĹL��,�������V$n�@��,�y��"HIR+damage+HIC"�ˮ`!\n"
NOR,me,enemy[i]);
enemy[i]->receive_damage("hp",damage,me);
COMBAT_D->report_status(enemy[i],1);
     }
 }
if(me->query("hp")<0)
command("begin war");
::heart_beat();
if(me->query("hp")<0)
 {
  me->die();
 }
}

//���`�ɤ��s�z
void die()
{
object ob;
if( !ob = query_temp("last_damage_from") )
ob = this_player(1);
ob->set_temp("kill_turtle",1);
if( !ob ) return;

shout(HIC"\n\n\n          �j�����ǨӤ@�}�s�z����\n\n"
+HIR"              �ڡ�ڡ����\n\n"
HIB"        ���R�������Ȱ_�F�}�}���g�ܥ��� \n\n"NOR);
shout(HIW"�j���t�h�W���j�s: �A��� �M����"HIY+ob->query("name")+HIW"��!! �����O���|��L�A��!!!"+
HIR"\n\n      �گ����J�O���ڡ������ڦu�@�o���j���a!!! \n\n"NOR);
::die();
}
