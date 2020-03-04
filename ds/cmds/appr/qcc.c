// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target, msg, output, *type,*exits,*files, material;
	mapping apply;
	int i,*value,flag,times;
	object obj,*ob;

	if (!arg) return notify_fail("���O�榡 : qc <���󤧦W�٩��ɦW>\n" );
	flag=0;
	if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;
	if( option == "-r" && (string)SECURITY_D->get_status(me)=="(admin)" )
			seteuid(ROOT_UID);
		else
			seteuid(geteuid(me));

	if(arg=="here") obj=environment(me);
	else obj = present(target, me);
	if (!obj) obj = find_object(target);
	if (!obj) obj = present(target, environment(me));
	if (!obj && file_size( resolve_path(me->query("cwd"), target))>0 )
	 obj = load_object( resolve_path(me->query("cwd"), target) );
	if (!obj && file_size( resolve_path(me->query("cwd"), target)+".c")>0 )
	 obj = load_object( resolve_path(me->query("cwd"), target)+".c" );
	if (!obj) return notify_fail("�S���o�˪���....�C\n");

	if( environment(me)==environment(obj) )
	if( !stringp(msg = me->query("env/msg_qc")) )
		msg = "$N���_�@�ө�j��, �J�Ӫ��ˬd$n�C\n";
	else
		message_vision(msg + "\n", me, obj);

	if(obj->is_character())
	{
		output = "NPC�W��: "+obj->short()+"\n";
		output += "����: "+obj->query("level")+"\n";
		if(obj->query("race")!="�H��")
		{
			output += "�}�l�ˬd�����覡�]�w: ";
			if(obj->query("verbs")) output+= "�q�L!!\n";
				else output+= "�S���]�w verbs! \n";
			output += "�}�l�ˬd���𳡦�]�w: ";
			if(obj->query("limbs")) output+= "�q�L!!\n";
				else output+= "�S���]�w limbs! \n";
		}
		if(mapp(apply=obj->query("apply")))
		{
		 type=keys(apply);
		 value=values(apply);
		 for(i=0;i<sizeof(apply);i++)
		 {
		  output+=sprintf("���[ %s : %d \n",type[i],value[i]);
		 }
		}
		output+=sprintf("\n���ݩ�:\n  �O�q: %-4d ���: %-4d �t��: %-4d ���z: %-4d\n  �̤jHP: %-5d\n  �̤jMP: %-5d\n\n",
			obj->query("str"),obj->query("con"),obj->query("dex"),obj->query("int"),
			obj->query("max_hp"),obj->query("max_mp"));
		if(ob=all_inventory(obj))
		{
		 	output += "��a���~: \n";
		        for(i=0; i<sizeof(ob); i++)
        		{
				output+=sprintf("  %s (%s) \n",ob[i]->short(),base_name(ob[i]));
        		}
		}
		
		output+="\n��l�Х�score�d��.\n";
	} else
	{
	 material = obj->query("material");
	 output = "����W��: "+(obj->short()? obj->short() : obj->query("short"))+"\n";
	 output += "�������: ";
	 if(obj->query("armor_type"))
	 {
	  output+= "����("+obj->query("armor_type")+")   ���: "+material+"("+obj->M_chinese(material)+")\n";
	  output += "=============================== �����T ================================\n";
	  output += "�K��: "+obj->M_density(material)+"\t";
	  output += "�w��: "+obj->M_hardness(material)+"\t";
	  output += "�@��: "+obj->M_durable(material)+"\t";
	  output += "�U�Q: "+obj->M_sharp(material)+"\t";
	  output += "����: "+obj->M_prize(material)+"\n";
	  output += "=========================================================================\n";
	  output+= sprintf("���q: %-5d\t����: %-5d\t���: %s\t��n: %-5d\t�@��: %-5d\n",
	  		obj->query_weight(),obj->query("value"),obj->query("unit"),obj->query("volume"),obj->query_temp("durable"));
	  if(obj->query("female_only") ) output += "�k�ʱM��\n";
	  if(obj->query("limit_lv")) output+=sprintf("�����: %d \n",obj->query("limit_lv"));
	  if(obj->query("limit_str")) output+=sprintf("����O�q: %d \n",obj->query("limit_str"));
	  if(obj->query("limit_con")) output+=sprintf("�����髬: %d \n",obj->query("limit_con"));
	  if(obj->query("limit_dex")) output+=sprintf("����ӱ�: %d \n",obj->query("limit_dex"));
	  if(obj->query("limit_int")) output+=sprintf("����z: %d \n",obj->query("limit_int"));
		if(mapp(apply=obj->query("armor_prop")))
		{
		 type=keys(apply);
		 value=values(apply);
		 for(i=0;i<sizeof(apply);i++)
		 {
		  output+=sprintf("���[ %s : %d \n",type[i],value[i]);
		 }
		}
	 }
	 else if(obj->query("skill_type"))
	 {
	  output+= "�Z��("+obj->query("skill_type")+")   ����: "+material+"("+obj->M_chinese(material)+")\n";
	  output += "=============================== �����T ================================\n";
	  output += "�K��: "+obj->M_density(material)+"\t";
	  output += "�w��: "+obj->M_hardness(material)+"\t";
	  output += "�@��: "+obj->M_durable(material)+"\t";
	  output += "�U�Q: "+obj->M_sharp(material)+"\t";
	  output += "����: "+obj->M_prize(material)+"\n";
	  output += "=========================================================================\n";
	  output+= sprintf("���q: %-5d\t����: %-5d\t���: %s\t��n: %-5d\t�@��: %-5d\n",
	  		obj->query_weight(),obj->query("value"),obj->query("unit"),obj->query("volume"),obj->query_temp("durable"));
	  if(obj->query("female_only") ) output += "�k�ʱM��\n";
	  if(obj->query("limit_lv")) output+=sprintf("�����: %d \n",obj->query("limit_lv"));
	  if(obj->query("limit_str")) output+=sprintf("����O�q: %d \n",obj->query("limit_str"));
	  if(obj->query("limit_con")) output+=sprintf("�����髬: %d \n",obj->query("limit_con"));
	  if(obj->query("limit_dex")) output+=sprintf("����ӱ�: %d \n",obj->query("limit_dex"));
	  if(obj->query("limit_int")) output+=sprintf("����z: %d \n",obj->query("limit_int"));
		if(mapp(apply=obj->query("weapon_prop")))
		{
		 type=keys(apply);
		 value=values(apply);
		 for(i=0;i<sizeof(apply);i++)
		 {
		  output+=sprintf("���[ %s : %d \n",type[i],value[i]);
		 }
		}
	 }
	 else if(obj->is_room()) 
	 {
	  output+= "�ж�("+base_name(obj)+")\n\n";
	  if(obj->query("light")) output+="�ө�: ��\n";
	  	else output+="�ө�: �L\n";
	  if(obj->query("outdoors")) output+="�ǥ~: "+obj->query("outdoors")+"\n";
	  	else output+="�Ǥ�\n";
	  if(mapp(apply=obj->query("exits")))
	  {
	  	output+="\n�o�̪��X�f��:\n";
	   	exits=keys(apply);
		files=values(apply);
		for(i=0;i<sizeof(apply);i++)
		{
		  output+=sprintf("  %s : %s \n",exits[i],files[i]);
		}
	  }
	  if(mapp(apply=obj->query("item_desc")))
	  {
	  	output+="\n�ж����i�ݪ��B�~�ԭz��:\n";
	   	exits=keys(apply);
		for(i=0;i<sizeof(apply);i++)
		{
		  output+=sprintf("  %s \n",exits[i]);
		}
	  }
	  if(mapp(apply=obj->query("objects")))
	  {
	  	output+="\n�o�̪�����:\n";
	   	exits=keys(apply);
		value=values(apply);
		for(i=0;i<sizeof(apply);i++)
		{
		  output+=sprintf("  %s : %d \n",exits[i],value[i]);
		}
	  }
	 }
	 else
	 {
	  if(obj->value())
	  {
	   output+= "�f��\n";
	   output=sprintf("%s���q: %d ���J\n",output,obj->weight());
	   output=sprintf("%s����: %d \n",output,obj->value());
	   write(output);
	   return 1;
	  }
	  if(obj->is_food())
	  {
	   output+= "����\n";
	   flag=1;
	   times=obj->query("food_remaining");
	  }
	  else if(obj->is_water())
	  {
	   output+= "����\n";
	   times=obj->query("water_remaining");
	   flag=1;
	  }
	  else if(obj->is_pill())
	  {
	   output+= "����\n";
	   flag=1;
	   times=1;
	  }
	  else output+= "�D��\n";
	  output=sprintf("%s���q: %d ���J\n",output,obj->weight());
	  output=sprintf("%s����: %d \n",output,obj->query("value"));
	  if(flag)
	  {
	    if(times) output=sprintf("%s�i�Φ���: %d \n",output,times);
	    if(obj->query("heal_hp")) output=sprintf("%s�ɥRHP: %d \n",output,obj->query("heal_hp"));
	    if(obj->query("heal_mp")) output=sprintf("%s�ɥRMP: %d \n",output,obj->query("heal_mp"));
   	    if(obj->query("heal_ap")) output=sprintf("%s�ɥRAP: %d \n",output,obj->query("heal_ap"));
	  }
	 }
	}
	write(output);
	return 1;
}

int help(object me)
{
	write(@HELP
���O�榡 : qc <���󤧦W��||�ɦW||here>

�Q�Φ����O�i�H���Ův�ֳt�ˬd�@�Ӫ�����ɮת��]�w�O�_���T.

HELP
    );
    return 1;
}
