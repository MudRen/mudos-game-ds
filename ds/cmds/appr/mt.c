// mt.c		����պ⾹	by Shengsan@DS	1999/11/07

#include <ansi2.h>
#include <weapon.h>
#define List_row	7	// �]�w�C��

inherit F_CLEAN_UP;
inherit F_MATERIAL;
string *__WEAPON_TYPE_Table__ =	({"axe","blade","dagger","fork","hammer",
				"sword","staff","throwing","whip","gun",
				"bow","fist","claw","parasite"});

string acc(string material, int weight);
string listall();
string list_wp_damage(string material,int weight);

int main(object me, string arg)
{
	string material,c_material,output;
	int volume,weight,list_type;
	
	seteuid(geteuid(me));
	if ( arg == "all" )	// �C�X�ثe�Ҧ������T
		list_type = 2;
	else if (!arg || sscanf(arg, "%s %d", material, weight)!=2 )
		list_type = 0;	// �y�k����
	else
		list_type = 1;	// �p��ؼЧ���P���q�f�t�����G
		
	switch(list_type)
	{
		case 1:	output = acc(material,weight);
			break;
		case 2: output = listall();
			break;
		default:
			return	notify_fail("���O�榡: mt [����W��(�^��)] [���q]\n"
					    "          mt all\n");
	}
	me->start_more(output);
	
	return 1;
}

string acc(string material, int weight)
{
	string output;
	int volume;
	
	volume = this_object()->Eq_Volume(material,weight);
	output = sprintf(
		"== ����򥻸�T ============================================================\n"
		"����: %s%s\n"
		"�K��: %-3d �w��: %-3d �@��: %-3d ����: %-3d\n"
		"============================================================================\n"
		"�z�]�w���f�t���q��: %d Dsg\n"
		"�B�⵲�G: �Ҧ��Ŷ�: %d\n\t  �@�Ϋ�: %d\n"
		"\t  ����: %d\n\t  �ˮ`�O(�Z��): \n%s\n"
		"============================================================================\n",
		this_object()->M_chinese(material),
		"("+material+")",
		this_object()->M_density(material),
		this_object()->M_hardness(material),
		this_object()->M_durable(material),
		this_object()->M_prize(material),
		weight,
		volume,
		this_object()->Eq_Durable(material,volume),
		this_object()->Eq_Prize(material,weight),
		list_wp_damage(material,weight)

		);
		
	return output;
}

string listall()
{
	string output,*materials;
	mapping mmap;
	int i;
	
	mmap = this_object()->M_mapping();
	materials = keys(mmap);
	
	output =HIY"��"HIC" �ڤۤC������Ʈw "HIY"��\n"NOR
		"=====================================================================\n"
		" �������  �^�����         "HIR"�K�� "HIG"�w�� "HIY"�@�� "HIC"����\n"NOR
		"=====================================================================\n";
	for(i=0;i<sizeof(materials);i++)
	{
		output += sprintf("  %-8s %-16s "HIR"%-4d "HIG"%-4d "HIY"%-4d "HIC"%-4d\n"NOR,
			this_object()->M_chinese(materials[i]),
			materials[i],
			this_object()->M_density(materials[i]),
			this_object()->M_hardness(materials[i]),
			this_object()->M_durable(materials[i]),
			this_object()->M_prize(materials[i])
			);
	}
	output += "=====================================================================\n";
	
	return output;
}

string list_wp_damage(string material,int weight)
{
	string output;
	int i,j,k,l,lim,sp;
	
	output = "�~�w�w�w�w";
	for(j=0;j<List_row-1;j++)
	{
		output += "�s�w�w�w�w";
	}
	output += "��\n";
	
	for(k=0;k<sizeof(__WEAPON_TYPE_Table__);k=k+List_row)
	{
		if( k+List_row > sizeof(__WEAPON_TYPE_Table__) )
		{
			lim = sizeof(__WEAPON_TYPE_Table__);
			sp = List_row - ( lim - k );
		}
		else
			lim = k+List_row;
			
		output += "�x";
		for(i=k;i<lim;i++)
		{
			output += sprintf(BYEL"%-8s"NOR"�x",__WEAPON_TYPE_Table__[i]);
		}
		
		if(sp)
		{
			for(j=0;j<sp;j++)
				output += "        �x";
		}
		output += "\n�u�w�w�w�w";
		for(j=0;j<List_row-1;j++)
		{
			output += "�q�w�w�w�w";
		}
		
		output += "�t\n�x";
		for(i=k;i<lim;i++)
		{
			output += sprintf("%-8d�x",this_object()->Eq_Damage(material,weight,__WEAPON_TYPE_Table__[i]));
		}
		
		if(sp)
		{
			for(j=0;j<sp;j++)
				output += "        �x";
		}
		if(k+List_row<sizeof(__WEAPON_TYPE_Table__))
		{
			output += "\n�u�w�w�w�w";
			for(j=0;j<List_row-1;j++)
			{
				output += "�q�w�w�w�w";
			}
			output += "�t\n";
		}
	}
	
	output += "\n���w�w�w�w";
	for(j=0;j<List_row-1;j++)
	{
		output += "�r�w�w�w�w";
	}
	output += "��\n";
	
	return output;
}

int help(object me)
{
	write(@HELP
���O�榡 : mt [����W��(�^��)] [���q]
           mt all
           
�Y�i���A�D�X �Ҧ��Ŷ�, �@�Ϋ�, �ˮ`�O(�Z��), ���m�O(����)
�Ѽ� all : �C�X�ثe���誺�S�ʸ��
HELP
	);
	return 1;
}
 
