// jiang-yaoting.c ��ģ�F  �B�z���a���B
// by llm 99/06
#include <ansi.h>
inherit NPC;
int do_unmarry(string arg);
int zou(object me);
int do_kill();
int do_chat();

void create()
{
	set_name("��ģ�F", ({ "jiang yaoting", "jiang" }));
	set("title", "���{����");
   set("gender", "�k��");
   set("age", 43);
   set("str", 20);
   set("dex", 20);
   set("long", "�L�N�O��ģ�F�A���{�{�������A�]���Q�ܦb���ҹҡA�ˤ�t�d���a���B���ơC\n");
   set("combat_exp", 30000);
   set("shen_type", 0);
   set("attitude", "heroism");

   set_skill("unarmed", 50);
   set_skill("force", 50);
   set_skill("sword", 50);
   set_skill("dodge", 50);
   set_skill("parry", 50);
   set_temp("apply/attack", 150);
   set_temp("apply/defense", 150);
   set_temp("apply/armor", 150);
   set_temp("apply/damage", 150);

   set("neili", 500);
   set("max_neili", 500);
   set("jiali", 10);

   setup();
//   carry_object("/clone/weapon/gangjian")->wield();
   carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
   add_action("do_chat", "chat");
   add_action("do_chat","chat*");
   add_action("do_unmarry","unmarry");
   add_action("do_kill",({"kill","fight","hit","touxi"}));
}

int accept_object(object me, object ob)
{
   if (!ob->query("money_id"))
     	return notify_fail("��ģ�F�N�N�a�ݤF�A�@���D�G���O���O���o���@�ФF�A�����������}�����H�I��\n");
  	if(ob->value() < 1000000)
	      return notify_fail("��ģ�F�K�F�K���Y���D�G���A�O�ʤ��n�٬O��\�ۡH100 gold�A�֤@��]�O�Q��I��\n");
	message_vision("��ģ�F���L���I�I���G���n�a�I�ڭ̨ӿ�z�a�I��\n",me);
	this_object()->set_temp("money",me->name());
  	return 1;
}

int do_chat()
{
   object me;
   me=this_player();

   message_vision(HIW "�������y��@�I�A����@��ܹD�G���j�󤧤W�A�����ټM�I�ӤH�r�I��\n"
   "���b�I������ŧл��n���D�C��ģ�F�@��$N�ܹD�G����L���ڭ����G�Q�j�O�I��\n"NOR,me);
   call_out("zou",1,me);
   return 0;
}

int zou(object me)
{
   message_vision(HIW"�@�s�ŧШR�W�e�ӡA���Ѥ����A��$N��½�b�a�A�@�}�j�O�H�Y��W�K�K\n"NOR,me);
   tell_object(me,HIR"�A��o�{����A�|�Ϥw�g�Q���c�b�a�A�uı�@�O�O���o�A�h�J����K�K\n"NOR);
	if((int)me->query("combat_exp")>10000
   	&&(int)me->query("qi")>20)
   {
		me->receive_damage("qi", 20);
		me->receive_wound("qi",  20);
   }
   else
      me->unconcious();
  	return 1;
}

int do_kill()
{
	object ob;
	int i;

	command("say �j�x�A�����b����W�ʪZ�A�ӤH�r�I");
	message_vision("�|�P���ŧХߨ�s�_��$N�o�ʧ����I\n", this_player());

	for(i=0; i<4; i++)
   {
		if( objectp( ob = present("ya yi " + (i+1), environment(this_object())) ) )
			ob->kill_ob(this_player());
		else
      	this_object()->kill_ob(this_player());
	}
	return 1;
}

int do_unmarry(string arg)
{
	object me, obj,ob;
	me = this_player();

	if (me->is_busy())
		return notify_fail("���������Y�@�K���D�G���A�ݬݧA�ۤv���Ӧ��ˡI��\n");

	if( me->is_fighting() )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me);
		return notify_fail("��ģ�F������N�G���j�x�f��A�ӨӨӡA���x�e�A�h�����h���B�I��\n");
	}

	if( this_object()->is_fighting() )
		return notify_fail("���������D�G���A���h�U�A�����x�B�z�F�o���o�ê��H�A���I��\n");

	if( !living(this_object()) )
		return notify_fail("�A�٬O���Q��k�⪾���j�H�Ͽ��a�C\n");

	if( !environment()||base_name(environment()) != query("startroom") )
		return notify_fail("������F�@�n���D�G���椰�\�H�����x�ɰ�F�A���I��\n");

   if(me->query_temp("unmarry"))
   	return notify_fail("��ģ�F�µ��y�ݬݧA�G�����x���O������A�̿�L���B����H�٨ӷЧڡI�H��\n");

	if( !mapp( me->query("couple") ) || !me->query("couple/have_couple") )
	{
		if ((string)me->query("gender") == "�k��")
			say("��ģ�F�y�@�I�ܹD�G���j�x�N���A�A�����S���V�ҡA�ٴ����˥��x�A�ӤH�r�I���o�G�Q�j�O�I��\n");
		else
			say("��ģ�F�y�@�I�ܹD�G���j�x�N���A�A�����S���d�ǡA�ٴ����˥��x�A�ӤH�r�I���L�G�Q�j�O�I��\n");
      call_out("zou",1,me);
      return 1;
	}
   if(!arg||arg!=(string)me->query("couple/couple_id"))
   	return notify_fail("�������K�F�K���Y�G�A�n�M�����B�H\n");
//   ob = new(LOGIN_OB);
//	ob->set("id",(string)me->query("couple/couple_id"));
//	if( !ob->restore() )
	seteuid(getuid());
	if( file_size(DATA_DIR + "login/" + arg[0..0] + "/" + arg + ".o")<0 )
   {
       message_vision("��ģ�Fť�F$N�����z�A�J�Ӭd�ݤF�ר��A�I�I�Y�D�G���J�M�A���R�H�w�g���b�H�@�A�ڴN���A\n"
       "��W��z���B����A���]�����n��F�I���M�Z�b�ר��W�@�F�O���Z�A�\�W�F�x�L�A��v�ݩۤ�\n"
       "�D�G���e�@�������Q�ܡI���M�Z�S��$N���G���A���a�A�A�w�g�O�樭�F�I��\n",me);
		CHANNEL_D->do_channel(this_object(), "mudnews",
		sprintf( "�g�������d�G�Ѥ_%s���t���w�g�h�@�A�L�̪��B�����t�۵M�Ѱ��I\n", me->name()));
		me->add("couple/unmarried", 1);
		me->set("couple/have_couple",0);
      return 1;
   }
	else if( !objectp(obj = present((string)me->query("couple/couple_id"), environment(me)))
                 || !find_player(me->query("couple/couple_id")) )
		return notify_fail("�������i�i�a�ݤF�ݧA�D�G���A���R�H�{�b���b���A�n��H�@�_�Ӥ~������B�C��\n");

   if(query_temp("money")!=me->name()
   	&&query_temp("money")!=obj->name())
   	return notify_fail("��������F���l�G�����B������O100 gold�A�٨S��A�S���N�^�h��X�۹L��l�A���n�ӷХ��x�I\n");

	if( (object)obj->query_temp("pending/unmarry")!=me )
	{
		me->set_temp("pending/unmarry", obj);
		message_vision(MAG "\n$N�ݤF��$n���Ĥ@�f��D�G���}�}�}�K�K�ڭ��٬O�n�E�n���a�I?��\n"
			"��ģ�F�N�_�����ݰ�$n�G���A�@���@�N���B�O�H���X�ӡA���x���A�@�D�I��\n"NOR,me,obj);
      tell_object(obj,"�p�G�A�P�N���B�A�ЧA�]��"+me->name()+ "("+(string)me->query("id")+
                       	")"+ "�U�@�� unmarry "+(string)me->query("id")+"  �����O�C\n");
		write(MAG "�{�b�A�����ݵۧA����Q���^��...\n" NOR);
		return 1;
	}
	message_vision(MAG "\n$N���$n��F�@�n���D�G���Ƥw�ܤ��A�J�M�L�t�A���̴N�U���U�����a�C��\n\n"NOR, me,obj);
   me->set_temp("unmarry",1);
   obj->set_temp("unmarry",1);
	message_vision(HIY "��ģ�F�ݤF���I�I�Y���D�G��$N�M$n�A�J�M�A�̳��P�N���B�A�����x�]�N���A�̿�F�I��\n"
   	"�����A�b�ýtï�W�����a�E�h�F��ӦW�r�C\n" NOR, obj, me);
	CHANNEL_D->do_channel(this_object(), "mudnews",
	sprintf( "�g�����ŧP�G�q���Ѱ_�A%s�M%s���B�����t�Ѱ��I\n", me->name(), obj->name()));

	me->add("couple/unmarried", 1);
	me->set("couple/have_couple",0);

	obj->add("couple/unmarried", 1);
	obj->set("couple/have_couple",0);
	return 1;
}
