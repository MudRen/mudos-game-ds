// mt.c		材質試算器	by Shengsan@DS	1999/11/07

#include <ansi2.h>
#include <weapon.h>
#define List_row	7	// 設定列數

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
	if ( arg == "all" )	// 列出目前所有材質資訊
		list_type = 2;
	else if (!arg || sscanf(arg, "%s %d", material, weight)!=2 )
		list_type = 0;	// 語法不對
	else
		list_type = 1;	// 計算目標材質與重量搭配的結果
		
	switch(list_type)
	{
		case 1:	output = acc(material,weight);
			break;
		case 2: output = listall();
			break;
		default:
			return	notify_fail("指令格式: mt [材質名稱(英文)] [重量]\n"
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
		"== 材質基本資訊 ============================================================\n"
		"材質: %s%s\n"
		"密度: %-3d 硬度: %-3d 耐用: %-3d 價值: %-3d\n"
		"============================================================================\n"
		"您設定的搭配重量為: %d Dsg\n"
		"運算結果: 所佔空間: %d\n\t  耐用度: %d\n"
		"\t  價值: %d\n\t  傷害力(武器): \n%s\n"
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
	
	output =HIY"◎"HIC" 夢幻七域材質資料庫 "HIY"◎\n"NOR
		"=====================================================================\n"
		" 中文材質  英文材質         "HIR"密度 "HIG"硬度 "HIY"耐用 "HIC"價值\n"NOR
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
	
	output = "╭────";
	for(j=0;j<List_row-1;j++)
	{
		output += "┬────";
	}
	output += "╮\n";
	
	for(k=0;k<sizeof(__WEAPON_TYPE_Table__);k=k+List_row)
	{
		if( k+List_row > sizeof(__WEAPON_TYPE_Table__) )
		{
			lim = sizeof(__WEAPON_TYPE_Table__);
			sp = List_row - ( lim - k );
		}
		else
			lim = k+List_row;
			
		output += "│";
		for(i=k;i<lim;i++)
		{
			output += sprintf(BYEL"%-8s"NOR"│",__WEAPON_TYPE_Table__[i]);
		}
		
		if(sp)
		{
			for(j=0;j<sp;j++)
				output += "        │";
		}
		output += "\n├────";
		for(j=0;j<List_row-1;j++)
		{
			output += "┼────";
		}
		
		output += "┤\n│";
		for(i=k;i<lim;i++)
		{
			output += sprintf("%-8d│",this_object()->Eq_Damage(material,weight,__WEAPON_TYPE_Table__[i]));
		}
		
		if(sp)
		{
			for(j=0;j<sp;j++)
				output += "        │";
		}
		if(k+List_row<sizeof(__WEAPON_TYPE_Table__))
		{
			output += "\n├────";
			for(j=0;j<List_row-1;j++)
			{
				output += "┼────";
			}
			output += "┤\n";
		}
	}
	
	output += "\n╰────";
	for(j=0;j<List_row-1;j++)
	{
		output += "┴────";
	}
	output += "╯\n";
	
	return output;
}

int help(object me)
{
	write(@HELP
指令格式 : mt [材質名稱(英文)] [重量]
           mt all
           
即可幫你求出 所佔空間, 耐用度, 傷害力(武器), 防禦力(防具)
參數 all : 列出目前材質的特性資料
HELP
	);
	return 1;
}
 
