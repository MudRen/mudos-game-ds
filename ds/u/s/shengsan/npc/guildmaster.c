// /std/char/guildmaster.c		Edit by shengsan@SD	1999.04.23
// ����: V1.04.00
// �`�N�ƶ�:
// 0. �ק惡�ɮ�, ���g Shengsan �P�N, ���o�R���έק惡��.
// 1. V1.02.00 ���H��, �u�|�ɮv�i�H�����~�Ӧ���, �u�n�αN�A���禡�ޥΧY�i.
// 2. �u�|�ɮv�n�ϥΦ��ɤ����禡, ���u�|�ɮv�����n�����㪺¾�~���{�O��
//    �]�N�O��, ���a���W����¾�~���, NPC�@�ˤ]�����, �䤤�]�A:
//    a. adv_class: x	x = �ƭ�(1~2)
//       ���ѼƬO���������a��NPC�ثe��¾�~�O�ĴX��, 1 �N�O�Ĥ@��, �]�N�O�̪�
//       ��¾�~����, 2 �N�O�ĤG��, �̦�����...
//    b. class1: x       x = ¾�~�r��(�^��)
//       �o�O�Ĥ@��¾�~��¾�~�^��W��, ���ަ����a��NPC�ثe���ĴX�Ū�¾�~, �o
//       �ӰѼƤ@�w�n�w�q, �_�h�{���N���|���`�u�@... �O��, ¾�~���{�n����...
//    c. class2: x  x = ¾�~�r��(�^��)
//       �o�O�ĤG��¾�~��¾�~�^��W��...
//
// 3. �u�|�ɮv�i�H�бª��ޯ�C��
//    ��榡�d�Ҧp�U:
//        set("guild_skills",([	// ����, ����1�i�Ǩ쪺�ޯ൥�ŭ��v, �W��
//            "dodge"    : ({32,2,50}), //������׬O32, ��Ǫ����ŬO2*����, �̰��ǲߤW��200
//            "sword"    : ({40,2,50}),
//            "makefood" : ({40,2,50}),
//        ]) );
//
// 4. �p�G�Q�����u�|�ɮv�u����ª��u�O�����a�ǲߧޯ�, �ӨS���[�J�u�|���\
//    �઺��, �Х[�J�U�C�]�w�ܵ{����:
//        set("no_join", 1);
//    �S�O����: �p�G�] set("no_join",1) ����, ����H���i�H�Ǧ��ɮv���ޯ�
//              ��!!
//
// 5. �p�G���u�|�ɮv���[�J�u�|���\��, �b���a���\�[�J�u�|���ɭ�, �u�|�ɮv
//    �|�o�X�T�������������a�ݨ�, �p�G�n�ϥιw�]�ȴN�����A�[�J�䥦�Ѽ�; 
//    ���O, �p�G�Q�n�ۤv�g�����зN���T������, ���~���ɤ��\�A�[�J�̦h�T��
//    �T��, �H���N��w�]��, ��k�p�U:
//    set("msg_guildclass0","�T�����e");
//    set("msg_guildclass1","�T�����e");
//    set("msg_guildclass2","�T�����e");
//    �ܤ֭n�� msg_guildclass0  ���]�w, ���U�Ӫ���ӥi���i�L, �������ӧA
//    ���ݭn, �ȱo�@�����O�T�����e, �T�����e�p�G���H $  ���}�Y���r, ���~
//    ���ɷ|�ξA���r��Ө��N��, �ЬݥH�U����:
//    $N	: �[�J�u�|�̪��W�r
//    $n	: �u�|�ɮv���W�r
//    $c	: �u�|�W��(����)
//    �ثe�u���T�ئr��i�H���N, �p�G�ݭn��h�����N�r��гq�� Shengsan 
//
// 6. �p�G�n�ݰѦҽd�ҽ� more /u/s/shengsan/guild/bluemaster.c
//
// 7. ���� V1.01.05 �s�\��:
//    a. �p�G no_join ���]�D 0 ����, ����H���i�H�Ǧ��ɮv���W���ޯ�
//    b. �i�H�����������a�[�J�u�|, �Ϊk�p�U:
//       1. ���n�[�J set("no_join",1);
//       2. �[�J�������:
//          set("jointerm","����r�y");
//          ����l�y��: xx>�ƭ�    ��    xx=�ƭ�    ��    xx<�ƭ�
//          �p�G���󦨥ߴN���� join
//       3. �p�G���󤣲�, �A�i�H�ۭq�n��ܪ����e, �Υιw�]�Ȥ]��.
//          �ۭq����k:
//          set("jointerm_msg","�T�����e");
//       4. �аѦҽd�� /u/s/shengsan/guild/bluemaster.c
//
// 8. ���� V1.03.00 �s�W�\��:
//    a. �W�[�k�N(spell)�C��
//    b. �V�ɮv�ǲߧޯ�Ϊk�N�n����
//
// 9. V1.04.00 ���ᤣ�A����W�٬��u�|...¾�~�t�ΥH��´���D...�s�W�[�F
//    do_guild_join_with_no_message() �禡...�o�Ө禡�u�O��H�e
//    do_guild_join() �̪��T�������h���אּ�Ǧ^�@�ӾA���ƭ�...
//    �Ǧ^�Ȫ��N�q�p�U:
//     1: ���\	0: �ɮv���{���g��
//    -1: ���a�w�g�[�J��L��´
//    -2: ���a�w�g�[�J�F�P�ɮv�P�ũΧ󰪯Ū���´
//    -3: ���a�ثe����´�ä��A�X�[�J����´
//    -4: ���a���Ť���
//    -5: ���a�� termstr �èS���j�� termnum ��
//    -6: ���a�� termstr �èS������ termnum ��
//    -7: ���a�� termstr �èS���p�� termnum ��
//    -8: ���a��J����´���~�ΨS����J�n�[�J����´�W
//    �@��...�d�Ҽg�b /u/s/shengsan/npc/bluemaster.c
//
#include <dbase.h>
#include <mudlib.h>
#include <ansi.h>

string sol_class(object ob, int adv);
void guild_shout(object ob, object me, string msg);
int exp_count(int base,int degree);
int guildgift_count(int ppllv,int value);
int total_guildgift(int *guildgift);

void create()
{
	seteuid(getuid());
}
int do_advance(object ob, object me, string arg)
{
	int *ppl_guildgift;
	int needexp, maxgift, gift_type;

	if( !me->query("adv_class") && me->query("level") > 2 )
	{
		write("�A�S��¾�~�N����ɯũΥ[�ݩ��o�I\n");
		return 1;
//		return notify_fail("�A�S��¾�~�ٷQ�A�ɯŤW�h���H\n");
	}

	if( !arg || arg == "level" )
	{
		if( !me->query("adv_class") && me->query("level") > 2 )
		{
			write("�A�S��¾�~�ٷQ�A�ɯŤW�h���H\n");
			return 1;
//			return notify_fail("�A�S��¾�~�ٷQ�A�ɯŤW�h���H\n");
		}
		if( me->query("adv_class") <= 1 && me->query("level") >= 25 )
		{
			write("�A�|����¾���e�A�N�u��o�ˤF�C\n");
			return 1;
//			return notify_fail("�A�|����¾���e�A�N�u��o�ˤF�C\n");
		}
		if( me->query("level") >= 50 )
		{
			write("�A�����Ťw�g��F�W���F�I\n");
			return 1;
//			return notify_fail("�A�����Ťw�g��F�W���F�I\n");
		}

		needexp = exp_count(me->query("level"),14);	// needexp = ((level+1)*14)^2

		tell_object(me,"needexp= "+needexp+"\n");

		if( me->query("exp") < needexp )
		{
			write("�A���g����٤�����I\n");
			return 1;
//			return notify_fail("�A���g����٤�����I\n");
		}
		me->set("exp",me->query("exp")-needexp);
		me->add("level",1);
		
		tell_object(me,"�A�N���Ŵ��@�� ��"
			+ CHINESE_D->chinese_number(me->query("level")) +"�šI\n");
		me->set("heart_modify",1);
		me->heart_beat();
		return 1;
	}
	if( arg == "str" || arg == "con" || arg == "int" || arg == "dex" )
	{
		if(  ( me->query(arg) >= me->query("level")*2 )
		  || ( me->query_total_gift() > me->query("level")*5 + 8 ) )
		{
			write("�o���ݩʥ[���W�h�o�I\n");
			return 1;
//			return notify_fail("�o���ݩʥ[���W�h�o�I\n");
		}

		if( me->query("level")>2 )
		{
			switch(arg)
			{
				case "str" : gift_type = 0; break;
				case "con" : gift_type = 1; break;
				case "int" : gift_type = 2; break;
				case "dex" : gift_type = 3; break;
			}
			ppl_guildgift = me->query("guild_gifts");
			if( total_guildgift(ppl_guildgift) != 20 )
			{
				write("�A�������ݩʤ��t����~�A���p���u�W�Ův�I\n");
				return 1;
//				return notify_fail("�A�������ݩʤ��t����~�A���p���u�W�Ův�I\n");
			}
			maxgift = guildgift_count(me->query("level"),ppl_guildgift[gift_type]);
			if( me->query(arg) >= maxgift )
			{
				write("�A��"+to_chinese(arg)+"�w�g��F�A�������F�I\n");
				return 1;
//				return notify_fail("�A��"+to_chinese(arg)+"�w�g��F�A�������F�I\n");
			}
		}
		needexp = exp_count(me->query(arg),7);	// (needexp = (attribut+1)*7)^2
		if(me->query("exp") < needexp)
		{
			write("�A�ݭn "+needexp+" �I�g��Ȥ~�ണ�@"+to_chinese(arg)+"�I\n");
			return 1;
//			return notify_fail("�A�ݭn "+needexp+" �I�g��Ȥ~�ണ�@"+to_chinese(arg)+"�I\n");
		}
		me->add("exp",-needexp);
		me->add(arg,1);
		me->set("heart_modify",1);
		me->heart_beat();
		tell_object(me,"�A��"+to_chinese(arg)+"���ɤF�C\n");
	}
	else
	{
		write("�S���o���ݩʡI�I\n");
		return 1;
//		return notify_fail("�S���o���ݩʡI�I\n");
	}
	return 1;
}

int exp_count(int base,int degree)
{
	int exp;
	exp = (base+1)*degree;
	exp = exp*exp;	
	return exp;
}

int guildgift_count(int ppllv,int value)	// (ppllv*10+ppllv*wizstr)/10
{
	int gift;
	gift = ppllv*10+ppllv*value;
	gift /= 10;
	return gift;
}

int total_guildgift(int *guildgift)		// �p���ݩʤ��t���`�M
{
	int i;
	i = guildgift[0]+guildgift[1]+guildgift[2]+guildgift[3];
	return i;
}

int set_guildgift(object me,int *guildgift)
{
	me->set("guild_gifts",guildgift);
	return 1;
}


int do_skill_list(object ob, object me, string arg)                     
{
        mapping skills;
        mixed cost1;
        string playerclass, guildclass, list, *name;
        int i,cost,level,maxlv,price;

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

        if( !mapp(skills = ob->query("guild_skills")) )
	{
		write("�o��ɮv�S���ޯ�C��I\n");
		return 1;
	}
        name = keys(skills);
        cost1 = values(skills);

	if( playerclass != guildclass && !ob->query("no_join"))
	{
		if( !me->query("no_check_class") )
		{
			write(HIW"�o�䪺�ޯ�"+to_chinese(guildclass)+"�~��d�ݡC\n"NOR);
			return 1;
		}
	}
	list = HIR"\n�ݢ�����������������������������������������������������������������������������\n"NOR;
	list += HIR"��"HIC"��  ��  �W  ��                   "HIG"�g��ȻݨD   "HIB"�ǶO�ݨD  "HIY"�ثe���� / �̰�����"HIR" ��\n"NOR;
	list += HIR"�㢤����������������������������������������������������������������������������\n"NOR;
        for(i=0; i<sizeof(name); i++)
	{
		if(cost1[i][1]<1) cost1[i][1]=2;	// �]�w maxlv ������(������n�T�w2�O? ����..)
		maxlv = me->query("level")*cost1[i][1];  // maxlv=level������
		if(maxlv >= cost1[i][2]) maxlv=cost1[i][2];
		level = me->query_skill(name[i],1);
			// �᭱����1(�D0) �O��ܭ�Ӫ���,���]��ȷ|��2
		cost =(level*level*cost1[i][0])/30;
		price=(level*level*cost1[i][0])/40;
		list += sprintf("  "HIC"%-34s"HIG"%-9d   "HIB"%-9d      "HIY"%3d / %-3d\n"NOR,
		to_chinese(name[i])+"("+name[i]+")",cost,price,level,maxlv);
	}
        write(list);
        return 1;
}


int do_skill_train(object ob, object me, string argx)
{
	mapping skills,myskl;
	mixed cost1;
	string playerclass, guildclass, list, *name,*skil;
	int i,cost,level,maxlv,value;

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

	if(!mapp(skills = ob->query("guild_skills")) )
	{
		write("�o��ɮv�S���ޯ�C��I\n");
		return 1;
	}
	if(!argx)
	{
		write(HIC"�Q�V�mԣ�ޯ�??\n"NOR);
		return 1;
//		return notify_fail(HIC"�Q�V�mԣ�ޯ�??\n"NOR);
	}
	if( playerclass != guildclass && !ob->query("no_join"))
	{
		write(HIW"�o��O"+to_chinese(guildclass)+"�M�Ϊ��V�m���C\n"NOR);
		return 1;
//		return notify_fail(HIW"�o��O"+to_chinese(guildclass)+"�M�Ϊ��V�m���C\n"NOR);
	}
	if(!ob->query("guild_skills/" +argx) )
	{
		write("�ݲM���T�o�̨S���اޯ�C\n");
		return 1;
//		return notify_fail("�ݲM���T�o�̨S���اޯ�C\n");
	}
	name = keys(skills);
	cost1 = values(skills);
	for(i=0; i<sizeof(name); i++)
	{
	  if(argx==name[i])
	    {
		if(cost1[i][1]<1) cost1[i][1]=2;	// �]�w maxlv ������
	    	maxlv = me->query("level")*cost1[i][1];  // maxlv=level������
		level = me->query_skill(argx,1);
		if(level >= maxlv || level >= cost1[i][2])
		{
			write("�A��"+to_chinese(argx)+"�w�g��o�̪��̰��ŤF\n");
			return 1;
//			return notify_fail("�A��"+to_chinese(argx)+"�w�g��o�̪��̰��ŤF\n");
		}
		cost =level*level*cost1[i][0]/30;
		if(me->query("exp") < cost)
		{
			write("�A�g�礣���F\n");
			return 1;
//			return notify_fail("�A�g�礣���F\n");
		}
		value = level*level*cost1[i][0]/40;
		if( me->can_afford(value)!=1 )
		{
			write("�A�a����������I\n");
			return 1;
//			return notify_fail("�A�a����������I\n");
		}
		if(level >= SKILL_D(argx)->improve_limite(me) )
		{
			write("�o�ӧޯ�A�u��Ǩ즹���šI\n");
			return 1;
//			return notify_fail("�o�ӧޯ�A�u��Ǩ즹���šI\n");
		}
		me->receive_money(-value);
		message_vision("$N��F"+F_VENDOR->price_string(value,me->money_type())+"�ǲ�"+to_chinese(argx)+"�C\n",me);
		me->add_skill(argx);
		me->add("exp",-cost);
	    }
	}
	return 1;
}
/*
 *
 *
 */
int do_spell_list(object ob, object me, string arg)                     
{
        mapping spells;
        mixed cost1;
        string playerclass, guildclass, list, *name;
        int i,cost,level,maxlv,price;

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

        if( !mapp(spells = ob->query("guild_spells")) )
	{
		write("�o��ɮv�S���k�N�C��I\n");
		return 1;
	}
        name = keys(spells);
        cost1 = values(spells);
	if( playerclass != guildclass && !ob->query("no_join"))
	{
		if( !me->query("no_check_class") )
		{
			write(HIW"�o�䪺�k�N�O"+to_chinese(guildclass)+"�~��d�ݡC\n"NOR);
			return 1;
//			return notify_fail(HIW"�o��O"+to_chinese(guildclass)+"�~��d�ݡC\n"NOR);
		}
	}
	list = HIR"\n�ݢ�����������������������������������������������������������������������������\n"NOR;
	list += HIR"��"HIC"�k  �N  �W  ��                   "HIG"�g��ȻݨD   "HIB"�ǶO�ݨD  "HIY"�ثe���� / �̰�����"HIR" ��\n"NOR;
	list += HIR"�㢤����������������������������������������������������������������������������\n"NOR;
       for(i=0; i<sizeof(name); i++)
	{
		if(cost1[i][1]<1) cost1[i][1]=2;	// �]�w maxlv ������
		maxlv = me->query("level")*cost1[i][1];  // maxlv=level������
		if(maxlv >= cost1[i][2]) maxlv=cost1[i][2];
		level = me->query_spell(name[i],1);
			// �᭱����1(�D0) �O��ܭ�Ӫ���,���]��ȷ|��2
		cost =level*level*cost1[i][0]/30;
		price=(level*level*cost1[i][0])/40;
		list += sprintf("  "HIC"%-34s"HIG"%-9d   "HIB"%-9d      "HIY"%3d / %-3d\n"NOR,
		to_chinese(name[i])+"("+name[i]+")",cost,price,level,maxlv);
	}
        write(list);
        return 1;
}


int do_spell_train(object ob, object me, string argx)
{
	mapping spells,myskl;
	mixed cost1;
	string playerclass, guildclass, list, *name;
	int i,cost,level,maxlv,value;

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);
	if(!mapp(spells = ob->query("guild_spells")) )
	{
		write("�o��ɮv�S���k�N�C��I\n");
		return 0;
	}
	if(!argx)
	{
		write(HIC"�Q�V�mԣ�k�N??\n"NOR);
		return 1;
//		return notify_fail(HIC"�Q�V�mԣ�k�N??\n"NOR);
	}
	if( playerclass != guildclass && !ob->query("no_join"))
	{
		write(HIW"�o��O"+to_chinese(guildclass)+"�M�Ϊ��V�m���C\n"NOR);
		return 1;
//		return notify_fail(HIW"�o��O"+to_chinese(guildclass)+"�M�Ϊ��V�m���C\n"NOR);
	}
	if(!ob->query("guild_spells/" +argx) )
	{
		write("�ݲM���T�o�̨S���تk�N�C\n");
		return 1;
//		return notify_fail("�ݲM���T�o�̨S���تk�N�C\n");
	}
	name = keys(spells);
	cost1 = values(spells);
	for(i=0; i<sizeof(name); i++)
	{
	  if(argx==name[i])
	    {
		if(cost1[i][1]<1) cost1[i][1]=2;	// �]�w maxlv ������
	    	maxlv = me->query("level")*cost1[i][1];  // maxlv=level������
		level = me->query_spell(argx,1);
		if(level >= maxlv || level >= cost1[i][2])
		{
			write("�A��"+to_chinese(argx)+"�w�g��o�̪��̰��ŤF\n");
			return 1;
//			return notify_fail("�A��"+to_chinese(argx)+"�w�g��o�̪��̰��ŤF\n");
		}
		cost =level*level*cost1[i][0]/30;
		if(me->query("exp") < cost)
		{
			write("�A�g�礣���F�I\n");
			return 1;
//			return notify_fail("�A�g�礣���F�I\n");
		}
		value = level*level*cost1[i][0]/40;
		if( me->can_afford(value)!=1 )
		{
			write("�A�a����������I\n");
			return 1;
//			return notify_fail("�A�a����������I\n");
		}
		if(level >= SPELL_D(argx)->improve_limite(me) )
		{
			write("�o�Ӫk�N�A�u��Ǩ즹���šI\n");
			return 1;
//			return notify_fail("�o�Ӫk�N�A�u��Ǩ즹���šI\n");
		}
		me->receive_money(-value);
		message_vision("$N��F"+F_VENDOR->price_string(value,me->money_type())+"�ǲ�"+to_chinese(argx)+"�C\n",me);
		me->add_spell(argx);
		me->add("exp",-cost);
	    }
	}
	return 1;
}


int do_guild_join(object ob, object me, string arg)
{
	int *master_guildgift;
	int clevel, termnum;
	string playerclass, guildclass, msg, termstr, str;

	if(!ob->query("adv_class"))
	{
		write("�o��NPC�èS����¾���ŰO���A�гq���Ův���A�ѨM�C\n");
		return 0;
	}
	if(!me->query("adv_class"))
	{
//		write("�A�èS����¾���ŰO���A�гq���Ův���A�ѨM�C\n");
//		return 0;
		me->set("adv_class",0);
	}

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

	master_guildgift = ob->query("guild_gifts");
	if( total_guildgift(master_guildgift) != 20 )
	{
		write("�o��ɮv���ݩʤ��t����~�A���p���u�W�Ův�I\n");
		return 1;
	}
	
	switch(ob->query("adv_class")) {
	    case 1   : clevel = 1;  break;
	    default  : clevel = 25; break;
	}


	if( arg && arg == guildclass )
	{
	    if( playerclass == guildclass )
	    {
		write(HIY"�A�w�g�[�J"+to_chinese(guildclass)+"��L��´�F�I\n"NOR);
		return 1;
//		return notify_fail(HIY"�A�w�g�[�J"+to_chinese(guildclass)+"��L��´�F�I\n"NOR);
	    }
	    if( me->query("adv_class") >= ob->query("adv_class")
	    && playerclass != guildclass)
	    {
		write(HIY"��p�A�A�w�g�[�J�P�ڭ̦P�ũΧ󰪯Ū�"+to_chinese(playerclass)+"��´�F�I\n"NOR);
		return 1;
//		return notify_fail(HIY"��p�A�A�w�g�[�J�P�ڭ̦P�ũΧ󰪯Ū�"+to_chinese(playerclass)+"��´�F�I\n"NOR);
	    }
	    if( playerclass != sol_class(ob,ob->query("adv_class")-1)
		&& me->query("adv_class")!=0 )
	    {
		write(HIY"�u��"
                      +to_chinese(sol_class(ob,ob->query("adv_class")-1))
                      +"��[�J"+to_chinese(guildclass)+"�I\n"NOR);
		return 1;
//	        return notify_fail(HIY"�u��"
//                      +to_chinese(sol_class(ob,ob->query("adv_class")-1))
//                      +"��[�J"+to_chinese(guildclass)+"�I\n"NOR);
	    }
	    if( me->query("level") < clevel)
	    {
		write(HIY"�H�A�ثe�����Ũä���b��´����¾�A�ЧA�ɨ�"
	              +clevel+"�ū�A�ӧa�I\n"NOR);
		return 1;
//		return notify_fail(HIY"�H�A�ثe�����Ũä���b��´����¾�A�ЧA�ɨ�"
//	              +clevel+"�ū�A�ӧa�I\n"NOR);
	    }
	    // 
	    if( !ob->query("no_join") && ob->query("jointerm") )
	    {
	        if( sscanf(ob->query("jointerm"),"%s>%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)<=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				write(HIY"�A��"+termstr+"�Ȥ����H�[�J����´��I\n"NOR);
				return 1;
//				return notify_fail(HIY"�A��"+termstr+"�Ȥ����H�[�J����´��I\n"NOR);
			 }
	        }
	        else if( sscanf(ob->query("jointerm"),"%s=%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)!=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				write(HIY"�A��"+termstr+"�Ȥ����H�[�J����´��I\n"NOR);
				return 1;
//				return notify_fail(HIY"�A��"+termstr+"�Ȥ����H�[�J����´��I\n"NOR);
			 }
	        }
	        else if( sscanf(ob->query("jointerm"),"%s<%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)>=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				write(HIY"�A��"+termstr+"�Ȥ����H�[�J����´��I\n"NOR);
				return 1;
//				return notify_fail(HIY"�A��"+termstr+"�Ȥ����H�[�J����´��I\n"NOR);
			 }
	        }
	        else { write(HIY"���u�|�ɮv���{���y�k���~�I\n"NOR); return 1; }
	    }

	    me->set("adv_class",ob->query("adv_class"));

	    switch(ob->query("adv_class")) {
	        case 1 : me->set("class1",guildclass);
			 set_guildgift(me,master_guildgift);// �u���b�[�J�Ĥ@�Ŷ��Τ~���]�w�ݩʤ��t��
			 break;
	        case 2 : me->set("class2",guildclass); break;
	        default  :
	    }

	    if( !stringp(msg = ob->query("msg_guildclass0")) )
	    {
	        shout("\n"
		    HIW"�w��"+me->query("name")+"�[�J"+to_chinese(guildclass)+"��´�T�T�T\n"NOR
		    HIC"�q����_�A"+me->query("name")+"�Y�O"+to_chinese(guildclass)+"��´���@���l�C\n"NOR
		    HIC"�Ʊ�A�H���W���ѤU...���ڭ�"+to_chinese(guildclass)+"��´�����C\n"NOR,me);
	        message("msg",
		    HIW"�w��"+me->query("name")+"�[�J"+to_chinese(guildclass)+"��´�T�T�T\n"NOR
		    HIC"�q����_�A"+me->query("name")+"�Y�O"+to_chinese(guildclass)+"��´���@���l�C\n"NOR
		    HIC"�Ʊ�A�H���W���ѤU...���ڭ�"+to_chinese(guildclass)+"��´�����C\n"NOR,me);
	    }
	    else
	    {
	        guild_shout(ob,me,msg);
	        if( stringp(msg = ob->query("msg_guildclass1")) )
		    guild_shout(ob,me,msg);
	        if( stringp(msg = ob->query("msg_guildclass2")) )
		    guild_shout(ob,me,msg);
	        msg = "\n";
	        guild_shout(ob,me,msg);
	    }

	}
	else
	{
		write(HIY"�A�쩳�n�[�J��´�ܡH�ݲM���ڬO"+to_chinese(guildclass)+"�C�I\n"+NOR
	              +HIM+"�p�G�n�[�J�ڭ̪��ܽ� join "+guildclass+"�C\n"NOR);
	}

        return 1;
}

int do_guild_join_with_no_message(object ob, object me, string arg)
{
	int *master_guildgift;
	int clevel, termnum;
	string playerclass, guildclass, msg, termstr, str;

	if(!ob->query("adv_class"))
	{
		write("�o��NPC�èS����¾���ŰO���A�гq���Ův���A�ѨM�C\n");
		return 0;
	}
	if(!me->query("adv_class"))
	{
//		write("�A�èS����¾���ŰO���A�гq���Ův���A�ѨM�C\n");
//		return 0;
		me->set("adv_class",0);
	}

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

	master_guildgift = ob->query("guild_gifts");
	if( total_guildgift(master_guildgift) != 20 )
	{
		write("�o��ɮv���ݩʤ��t����~�A���p���u�W�Ův�I\n");
		return 0;
	}


	switch(ob->query("adv_class")) {
	    case 1   : clevel = 1;  break;
	    default  : clevel = 25; break;
	}


	if( arg && arg == guildclass )
	{
	    if( playerclass == guildclass )
	    {
		// ���a�w�g�[�J��L��´
		return -1;
	    }
	    if( me->query("adv_class") >= ob->query("adv_class")
	    && playerclass != guildclass)
	    {
		// ���a�w�g�[�J�F�P�ɮv�P�ũΧ󰪯Ū���´
		return -2;
	    }
	    if( playerclass != sol_class(ob,ob->query("adv_class")-1)
		&& me->query("adv_class")!=0 )
	    {
		// ���a�ثe�ҥ[�J����´�ä��O�Ӳ�´�{�i����´
		// �]�N�O���L�ثe����´�ä��A�X�[�J�Ӳ�´
	        return -3;
	    }
	    if( me->query("level") < clevel)
	    {
		// ���a���Ť���
		return -4;
	    }
	    // 
	    if( !ob->query("no_join") && ob->query("jointerm") )
	    {
	        if( sscanf(ob->query("jointerm"),"%s>%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)<=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				// ���a�� termstr �èS���j�� termnum ��
				return -5;
			 }
	        }
	        else if( sscanf(ob->query("jointerm"),"%s=%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)!=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				// ���a�� termstr �èS������ termnum ��
				return -6;
			 }
	        }
	        else if( sscanf(ob->query("jointerm"),"%s<%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)>=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				// ���a�� termstr �èS���p�� termnum ��
				return -7;
			 }
	        }
	        else { write(HIY"���u�|�ɮv���{���y�k���~�I\n"NOR); return 0; }
	    }

	    me->set("adv_class",ob->query("adv_class"));

	    switch(ob->query("adv_class")) {
	        case 1 : me->set("class1",guildclass);
			 set_guildgift(me,master_guildgift);// �u���b�[�J�Ĥ@�Ŷ��Τ~���]�w�ݩʤ��t��
			 break;
	        case 2 : me->set("class2",guildclass); break;
	        default  :
	    }

	}
	else
	{
		// ���a��J����´���~�ΨS����J�n�[�J����´�W
		return -8;
//		write(HIY"�A�쩳�n�[�J�u�|�ܡH�ݲM���ڬO"+to_chinese(guildclass)+"�C�I\n"+NOR
//	              +HIM+"�p�G�n�[�J�ڭ̪��ܽ� join "+guildclass+"�C\n"NOR);
	}

        return 1;
}

string sol_class(object ob, int adv)
{
	string guildclass;
	
	if( adv > ob->query("adv_class") )
	    return "";
	if(!ob->query("adv_class"))
	    return "";
	if((ob->query("adv_class") == 1 && !adv) || adv == 1)
	    return guildclass = ob->query("class1");
	if((ob->query("adv_class") == 2 && !adv) || adv == 2)
	    return guildclass = ob->query("class2");
	return "";
}

void guild_shout(object ob, object me, string msg)
{
	string my_name, master_name, master_class;
	string str1;

	my_name      = me->query("name");
	master_name  = ob->query("name");
	master_class = to_chinese(sol_class(ob,0));

	// N: �ۤv���W�r n: �ɮv���W�r c: �ɮv��¾�~
	str1 = replace_string(msg,  "$N", my_name);
	str1 = replace_string(str1, "$n", master_name);
	str1 = replace_string(str1, "$c", master_class);

	message("guild_shout", str1, users(), me);
	message("guild_shout", str1, me);

}