#include <ansi.h>.
#include <command.h>
#include <path.h>
#include <weapon.h>
inherit WAND;
inherit SSERVER;
inherit F_CLEAN_UP;
void create()
{
set_name("�����Q�r�[",({"crystal cross","cross","wand"}));
set_weight(21000);
 if( clonep() )
                set_default_object(__FILE__);
	else {
		set("unit", "��");
set("long",@LONG
�o�O�@��I�k�̱M�Ϊ��Q�r�[,���Y�������_���]�k,�i�H�Ѱ��ʦL(invoke �ؼ�)
,��Q�r�[�S�k�O�ɥi�H��J�k�O(recharge)��Q�r�[(cross)���C\n
LONG
);
set("oldlong","�o�O�@��I�k�̱M�Ϊ��Q�r�[,���Y�������_���]�k,�i�H�Ѱ��ʦL(invoke �ؼ�)"
+",��Q�r�[�S�k�O�ɥi�H��J�k�O(recharge)��Q�r�[(cross)���C\n");
set("value",9800);
set("wand",200);
		set("material", "crystal");
	}
init_wand(500);

// These properties are optional, if you don't set them, it will use the
// default values.

 set("wield_msg", "$N�q�y����X�@��$n���b�⤤�C\n");
 set("unwield_msg", "$N�N�⤤��$n��^�y���h�C\n");

// The setup() is required.

	setup();
}

int fail_eq(object me)
{
  if(!me=this_player()) return 0;

  if(me->query("class")!="caster") 
  {
     write("�o�O�I�k�̱M�Ϊ��Q�r�[\n");
     return 1;
  }
  return 0;
}

void init()
{
 add_action("do_invoke","invoke");
 add_action("do_recharge","recharge");
}

int do_invoke(object target)
{                                           
	object me, ob, ob2;
	int damage, lv, in, time;
	string arg;
        
if(!this_player())
return 0;
me=this_player();
 in=me->query("int");  
arg="cross";

if (!target) return notify_fail(HIW"�A�n���H�ΤQ�r�[����\n"NOR);

ob=present(arg,me);

if(!ob) return notify_fail("�A�䤣��ؼ�!!\n");

if(me->query_skill("invoke",1)<100)
	return notify_fail(HIW"�A���Ѱ��ʦL�n100�H�W�~��ϥ�\n");

if(! me->is_fighting() )  return notify_fail("�u���b�԰����~��invoke\n");

if (me->query_temp("invoke")==1)
	return notify_fail(HIW"�A���b�Ѱ��ʦL��\n"NOR);

if( (string)ob->query("equipped")!="wielded" )
	return notify_fail("�A�èS���˳Ƴo�˪F��@���Z���C\n");

if (ob->query_temp("time")==0)
	return notify_fail(HIW"�A���Q�r�[�w�g�S���k�O�F\n"NOR);

if( ob->query("bad")==10)
 {
	ob2=new(LUKY+"pearl/npc/wp/badcross");
	ob2->move(me);
	ob2->wield();
	destruct(ob);
	return notify_fail(HIW"�A���Q�r�[�w�g�a�F�C\n");
 }
 
if(ob->query("bad")==11)
	return notify_fail("�A���Q�r�[�w�l���L�k�A�ϥ�\n");

if(me->query_skill("invoke",1)<random(130))
{
 ob->add("bad",1);
 ob->set("long",sprintf("%s\n"HIW"(�Q�r�[�|�l%2d�o��q, �ӥB�W����%2d�D���㪺����.)\n\n",
 ob->query("oldlong"),ob->query_temp("time"),ob->query("bad") ) );
 return notify_fail(HIW"�A���Q�r�[���͵��_\n"NOR);
}

if(!target) return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

if(target==me) return notify_fail("�A�����ۤv�ϥ�\n");

else if(!objectp(target = present(target, environment(me))) )
             return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

if(!living(target) ) return notify_fail(HIY"�o���O�ͪ���\n"NOR);

ob->add_temp("time",-1);
ob->set("long",sprintf("%s\n"HIW"(�Q�r�[�|�l%2d�o��q, �ӥB�W����%2d�D���㪺����.)\n\n",
ob->query("oldlong"),ob->query_temp("time"),ob->query("bad") ) );

damage=900+random(in*8);

message_vision(HIY"$N�R�U�ߨӪ`���]�k��,�C�C�Ѱ��Q�r�[���ʦL\n\n"+
HIW"$N"HIW"����ߪ����~�C�C���@���p�����t���u..\n\n"+"������@�n�V$n���h\n\n"
+"�y��$n"+damage+"�ˮ`�O\n\n",me,target);
target->receive_damage("hp",damage, me);
if( me->is_fighting() )
{
 me->kill_ob(target);
}
else if(target) target->kill_ob(me);

me->add_temp("invoke",1);
call_out("delay",3,me);
return 1;
}

int do_recharge(string arg)                     
{                                           
object me,ob,ob2;
int time;
me = this_player();              
if(!me) return 0;
if(!arg) return 0;
if(arg=="wand" || arg=="cross")
{
ob = present(arg, me);
if(!ob) return 0;
if( me->is_fighting() )
	return notify_fail(HIW"�԰�������ʦL�k�N\n"NOR);
if(me->query_skill("recharge",1)<120)
	return notify_fail(HIW"�A���]�k�ʦL�n�Ǩ�120�H�W�~��ϥ�\n");
if (me->query_temp("delay")==1)
	return notify_fail(HIW"�A���b��k�O���Q�r�[\n"NOR);
if( (string)ob->query("equipped")!="wielded" )
	return notify_fail("�A�èS���˳Ƴo�˪F��@���Z���C\n");
if (ob->query("bad")==11)
	return notify_fail("�A���Q�r�[�w�l���L�k�A�ϥ�\n");
if( ob->query("bad")==10)
 {
	ob2=new(LUKY+"pearl/npc/wp/badcross");
	ob2->move(me);
	ob2->wield();
	destruct(ob);
	return notify_fail(HIW"�A���Q�r�[�w�g�a�F�C\n");
 }

if (ob->query_temp("time")==10)
	return notify_fail(HIW"�A���Q�r�[�L�k�A��J�k�O�F\n"NOR);
if(me->query("mp")<100)
	return notify_fail(HIW"�A�S���������k�O��J�Q�r�[��\n"NOR);
me->add("mp",-100);
ob->add_temp("time",1);
ob->set("long",sprintf("%s\n"HIW"(�Q�r�[�|�l%2d�o��q, �ӥB�W����%2d�D���㪺����.)\n\n",
ob->query("oldlong"),ob->query_temp("time"),ob->query("bad") ) );
write(HIY"�A���k�O�}�}���C�C��J�Q�r�[����\n"NOR);
if(me->query_skill("recharge")<random(130))
 {
	ob->add("bad",1);
	ob->set("long",sprintf("%s\n"HIW"(�Q�r�[�|�l%2d�o��q, �ӥB�W����%2d�D���㪺����.)\n\n",
	ob->query("oldlong"),ob->query_temp("time"),ob->query("bad") ) );
	return notify_fail(HIW"�A���Q�r�[���͵��_\n"NOR);
 }
write(HIW"�Q�r�[�C�C�l���A��J���k�O\n"NOR);
me->start_busy(2);
me->set_temp("delay",1);
call_out("delay",3,me);
}
else 
 {
 write(HIW"�A�n recharge ����??\n"NOR);
 }
return 1;                        
}                                

int delay(object me)
{
	if(!me) return 0;
	me->delete_temp("delay");
	me->delete_temp("invoke");
	return 1;
}
