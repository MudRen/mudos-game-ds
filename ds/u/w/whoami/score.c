// score.c
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
string attribute_color(int current, int value);
string attitude_report(int evil_value);
string status_color(int current, int max);
string query_element_chinese(string elm);
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob,weapon,horse;
        mapping my;
        string line, skill_type, model,*apply_id;
        int attack_points, dodge_points, parry_points;
	int str1,con1,dex1,int1,bio1,bar1,wit1,sou1,tec1;
        seteuid(getuid(me));

        if(!arg) ob = me;
        else
        {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("�A�n��ݽ֪����A�S\n");
         	if(!wizardp(me))
         	{
         		if(ob->query("creater")!=me)
			return notify_fail("�u���Ův���ݧO�H�����A�C\n");
          	}
        }
/*--------------------------------------------------------------------------*/
        my = ob->query_entire_dbase();  //������ഫ.
line = "";
  //CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60)
str1= ob->query_str();
con1= ob->query_con();
dex1= ob->query_dex();
int1= ob->query_int();
bio1= ob->query_bio();
bar1= ob->query_bar();
sou1= ob->query_sou();
wit1= ob->query_wit();
tec1= ob->query_tec();
/*-------------------------------------------------------------*/
if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else skill_type = "unarmed";
// ��������������������
switch(ob->money_type())
{

case 1:
model=
"�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�x  %12s  " HIW " %-52s"NOR"\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�~�w�w�w�w�w�w�w�w�w�w��  ���� "HIY"%3d "NOR"��   �~�� "HIM"%2d "NOR"��   �ر� "HIG"%-6s"NOR"  �ʧO "HIC"%-2s"NOR"   �x\n"
"�x"HIW"�ڤۤC��"NOR" �� "HIY"�j�N�ɪ�"NOR"�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�u�w�w�w�w�w�w�w�w�w�w���ͪ�(BIO)�G%s%2d"NOR"(%2d)   �ͩR�I��(HP)�G%s%5d"NOR" / %-5d       �x\n"
"�x�O�q(STR)�G%s%3d"NOR"(%3d)   �~��(BAR)�G%s%2d"NOR"(%2d)   �]�k�I��(MP)�G%s%5d"NOR" / %-5d       �x\n"
"�x���(CON)�G%s%3d"NOR"(%3d)   �]�k(WIT)�G%s%2d"NOR"(%2d)   ���l�I��(AP)�G%s%5d"NOR" / %-5d       �x\n"
"�x���z(INT)�G%s%3d"NOR"(%3d)   ���F(SOU)�G%s%2d"NOR"(%2d)   �԰����m��  �G %-10d         �x\n"
"�x�ӱ�(DEX)�G%s%3d"NOR"(%3d)   ���(TEC)�G%s%2d"NOR"(%2d)   �g �� ��    �G %-10d         �x\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�x���z�����O�G %-4d     �����R���v�G +%3d%%  �� �� �A �� �G %14s"NOR"     �x\n"
"�x���z���m�O�G %-4d     �{���j�ײv�G +%3d%%  �� �� �� �� �G "HIY"%-10d"NOR"     �z�w�t\n"
"�x���F��ܤO�G %-4d     �n      ��G %-5d  �� �� �� �a �G "HIR"%-10d"NOR"     �x%s�x\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w���w��\n";
	break;
case 2:
model=
"���áááááâ�"NOR"���w���w���w���w���w���w"HIY"�i"HIW"�ڤۤC��"HIY"�j"NOR"�w���w���w���w���w���w��\n"NOR
"�j%12s " HIW "     %-52s"NOR"\n"
"���ġġġġġĢ�      ������������������������������������������������������\n"
"������������������������ ���� "HIY"%3d "NOR"��  �~�� "HIM"%2d "NOR"��   �ر� "HIG"%-6s"NOR" �ʧO "HIC"%-2s"NOR"  ��\n"
"��    "HIG"�{ �N �� ��"NOR"     ������������������������������������������������������\n"
"�������������������������ͪ�(BIO)�G%s%2d"NOR"(%2d) �x�ͩR�I��(HP)�G%s%5d"NOR" / %-5d   �x\n"
"�x�O�q(STR)�G%s%3d"NOR"(%3d) �x�~��(BAR)�G%s%2d"NOR"(%2d) �x�]�k�I��(MP)�G%s%5d"NOR" / %-5d   �x\n"
"�x���(CON)�G%s%3d"NOR"(%3d) �x�]�k(WIT)�G%s%2d"NOR"(%2d) �x���l�I��(AP)�G%s%5d"NOR" / %-5d   �x\n"
"�x���z(INT)�G%s%3d"NOR"(%3d) �x���F(SOU)�G%s%2d"NOR"(%2d) �x�԰����m��  �G %-10d     �x\n"
"�x�ӱ�(DEX)�G%s%3d"NOR"(%3d) �x���(TEC)�G%s%2d"NOR"(%2d) �x�g �� ��    �G %-10d     �x\n"
"���w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�����z�����O�G %-4d     �����R���v�G +%3d%%  �� �� �A �� �G %14s"NOR" ��\n"
"�����z���m�O�G %-4d     �{���j�ײv�G +%3d%%  �� �� �� �� �G "HIY"%-10d"NOR" ������\n"
"�����F��ܤO�G %-4d     ��  �W  �סG %-5d  �� �� �� �a �G "HIR"%-10d"NOR" ��%s��\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w���w��\n";
	break;
case 3:
model=
"�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�x  %12s  " HIW " %-52s"NOR"\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�~�w�w�w�w�w�w�w�w�w�w��  ���� "HIY"%3d "NOR"��   �~�� "HIM"%2d "NOR"��   �ر� "HIG"%-6s"NOR"  �ʧO "HIC"%-2s"NOR"   �x\n"
"�x"HIW"�ڤۤC��"NOR" �� "HIC"���Ӯɪ�"NOR"�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�u�w�w�w�w�w�w�w�w�w�w���ͪ�(BIO)�G%s%2d"NOR"(%2d)   �ͩR�I��(HP)�G%s%5d"NOR" / %-5d       �x\n"
"�x�O�q(STR)�G%s%3d"NOR"(%3d)   �~��(BAR)�G%s%2d"NOR"(%2d)   �]�k�I��(MP)�G%s%5d"NOR" / %-5d       �x\n"
"�x���(CON)�G%s%3d"NOR"(%3d)   �]�k(WIT)�G%s%2d"NOR"(%2d)   ���l�I��(AP)�G%s%5d"NOR" / %-5d       �x\n"
"�x���z(INT)�G%s%3d"NOR"(%3d)   ���F(SOU)�G%s%2d"NOR"(%2d)   �԰����m��  �G %-10d         �x\n"
"�x�ӱ�(DEX)�G%s%3d"NOR"(%3d)   ���(TEC)�G%s%2d"NOR"(%2d)   �g �� ��    �G %-10d         �x\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�x���z�����O�G %-4d     �����R���v�G +%3d%%  �� �� �A �� �G %14s"NOR"     �x\n"
"�x���z���m�O�G %-4d     �{���j�ײv�G +%3d%%  �� �� �� �� �G "HIY"%-10d"NOR"     �z�w�t\n"
"�x���F��ܤO�G %-4d     �n      ��G %-5d  �� �� �� �a �G "HIR"%-10d"NOR"     �x%s�x\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w���w��\n";
	break;
default:
model=
"�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�x  %12s  " HIW " %-52s"NOR"\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�~�w�w�w�w�w�w�w�w�w�w��  ���� "HIY"%3d "NOR"��   �~�� "HIM"%2d "NOR"��   �ر� "HIG"%-6s"NOR"  �ʧO "HIC"%-2s"NOR"   �x\n"
"�x"HIW"�ڤۤC��"NOR" �� "HIW"�ڤۮɪ�"NOR"�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�u�w�w�w�w�w�w�w�w�w�w���ͪ�(BIO)�G%s%2d"NOR"(%2d)   �ͩR�I��(HP)�G%s%5d"NOR" / %-5d       �x\n"
"�x�O�q(STR)�G%s%3d"NOR"(%3d)   �~��(BAR)�G%s%2d"NOR"(%2d)   �]�k�I��(MP)�G%s%5d"NOR" / %-5d       �x\n"
"�x���(CON)�G%s%3d"NOR"(%3d)   �]�k(WIT)�G%s%2d"NOR"(%2d)   ���l�I��(AP)�G%s%5d"NOR" / %-5d       �x\n"
"�x���z(INT)�G%s%3d"NOR"(%3d)   ���F(SOU)�G%s%2d"NOR"(%2d)   �԰����m��  �G %-10d         �x\n"
"�x�ӱ�(DEX)�G%s%3d"NOR"(%3d)   ���(TEC)�G%s%2d"NOR"(%2d)   �g �� ��    �G %-10d         �x\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
"�x���z�����O�G %-4d     �����R���v�G +%3d%%  �� �� �A �� �G %14s"NOR"     �x\n"
"�x���z���m�O�G %-4d     �{���j�ײv�G +%3d%%  �� �� �� �� �G "HIY"%-10d"NOR"     �z�w�t\n"
"�x���F��ܤO�G %-4d     �n      ��G %-5d  �� �� �� �a �G "HIR"%-10d"NOR"     �x%s�x\n"
"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w���w��\n";
}

line += sprintf(model
,
RANK_D->query_rank(ob), sizeof(apply_id=ob->query_temp("apply/id"))? ob->short(1)+"  �y " +apply_id[sizeof(apply_id)-1]+" �z" : ob->short(1),
ob->query("level"),ob->query("age"),to_chinese(ob->query("race")),ob->query("gender"),
attribute_color(bio1,my["Merits"]["bio"]),bio1,my["Merits"]["bio"],
status_color(my["hp"], my["max_hp"]), my["hp"], my["max_hp"],
attribute_color(str1,my["str"]),str1,my["str"],	//�Ѧ� /feature/attribute.c
attribute_color(bar1,my["Merits"]["bar"]),bar1,my["Merits"]["bar"],
status_color(my["mp"],my["max_mp"]),my["mp"],my["max_mp"],
attribute_color(con1,my["con"]),con1,my["con"],
attribute_color(wit1,my["Merits"]["wit"]),wit1,my["Merits"]["wit"],
status_color(my["ap"],my["max_ap"]),my["ap"],my["max_ap"],
attribute_color(int1,my["int"]),int1,my["int"],
attribute_color(sou1,my["Merits"]["sou"]),sou1,my["Merits"]["sou"],
ob->query("combat_exp"),
attribute_color(dex1,my["dex"]),dex1,my["dex"],
attribute_color(tec1,my["Merits"]["tec"]),tec1,my["Merits"]["tec"],
my["exp"],
ob->query_damage(),
COMBAT_D->attack_factor(ob,skill_type)*10/15,
attitude_report(ob->query("evil")),
ob->query_armor(),
-COMBAT_D->dodge_factor(ob,"dodge")*10/15,
my["MKS"] + my["PKS"],
ob->query_shield(),
my["popularity"],
my["PKS"],
query_element_chinese(ob->query_element())
);
if(mapp(my=ob->query("wound")))
{
	apply_id=keys(my);
	for(str1=0;str1<sizeof(apply_id);str1++)
	{
		if(ob->query("wound/"+apply_id[str1])>0)
		line += sprintf(HIW"  "+to_chinese(apply_id[str1])+"���˵{��:%s%3d%%\n"NOR,status_color(100-ob->query("wound/"+apply_id[str1]),100),ob->query("wound/"+apply_id[str1]));
	}
}

if(str1=ob->query_temp("conditions/poison")) line += sprintf("�餺�r���t�q%d%%\n"NOR,str1);
if(horse=ob->query_temp("ride"))
 line += sprintf("\n  �A�����b%s�W�C\n"NOR,horse->name());
line +="\n";
write(line);
return 1;

}
string attitude_report(int evil_value)
{
 string outcome;
 outcome = "";
 if(!evil_value) evil_value = 0;
	if( evil_value > 800 ) outcome += HIR "�p�P�c�]�머�c";
	else if( evil_value >= 600 ) outcome += HIM"���פ���      ";
	else if( evil_value >= 400 ) outcome += HIM"�Q�����c      ";
	else if( evil_value >= 200 ) outcome += HIY"�D�`�x�H      ";
	else if( evil_value >= 50 ) outcome += HIY"���I�c�H      ";
	else if( evil_value >= -50 ) outcome += "�w���u�v      ";
	else if( evil_value >= -200 ) outcome += HIG"�������}      ";
	else if( evil_value >= -400 ) outcome += HIG"�۷��}      ";
	else if( evil_value >= -600 ) outcome += HIW"�ֵ��n�I      ";
	else if( evil_value >= -800 ) outcome += HIW"�L�q�߸z      ";
	else outcome += HIC "���p�Ѩϯ믫�t";

 outcome += NOR;
 return outcome;
}
string attribute_color(int current, int value)
{
        if( current > value ) return HIW;
        if( current == value ) return NOR;
        if( current < value ) return HBK;
}
string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 80 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return HIM;
        return HIR;

}
string query_element_chinese(string elm)
{
	if(!elm) return "�H";
	switch(elm)
	{
		case "none" : return "�L";
		case "wind" : return "��";
		case "fire" : return "��";
		case "water" : return "��";
		case "plant" : return "��";
		case "ground" : return "�g";
		case "metal" : return "��";
		default: return "�H";
	}
	return "�H";
}

int help(object me)
{
        write(@HELP
���O�榡 : sc
	   sc �ۤv���۳�ͪ�
           sc <��H�W��>                   (�Ův�M��)

�o�ӫ��O�i�H��ܧA(�p)�Ϋ��w��H(�t�Ǫ�)���򥻸�ơC

see also : hp
HELP
    );
    return 1;
}

