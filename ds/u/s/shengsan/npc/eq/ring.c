#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIC"���Ū��ѱM�Χ٫�"NOR,({"bluesky ring","ring"}) );
	set("long","�o�T�٫��W���^�F�@�����R�����Ū��ѡC\n");
	set_weight(280);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "�T");
//		set("value",3980);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }

void init()
{
	add_action("do_show","show");
}

int do_show(string arg)
{
	object me,ob;
	string line,material;
	
	me = this_player();
	
	if(!arg)
		return notify_fail("�A�n����ܤ���F�誺��ƪ�?\n");
		
	ob = present(arg, environment(me));
	if (!ob) ob = present(arg, me);
	if(!ob) return notify_fail("�A�B�����Ҥ��L�k��즹����: "+arg+"�C\n");
	
	material = ob->query("material");
	if(!material)
	{
		ob->set("material","plant");
		write("�S������...�ҥH�w�]�� plant\n");
	}
	line = "";
	line += "���~�W: "+ob->query("name")+"("+arg+")\t";
	line += "����: "+ob->query("material")+"("+ob->M_chinese(material)+")\n";
	line += "=============================== �����T ================================\n";
	line += "�K��: "+ob->M_density(material)+"\t";
	line += "�w��: "+ob->M_hardness(material)+"\t";
	line += "�@��: "+ob->M_durable(material)+"\t";
	line += "�U�Q: "+ob->M_sharp(material)+"\t";
	line += "����: "+ob->M_prize(material)+"\n";
	line += "=========================================================================\n";
	line += "���q: "+ob->weight()+"\t";
	line += "��n: "+ob->query("volume")+"\t";
	line += "����: "+ob->query("value")+"\t";
	line += "�@��: "+ob->query_temp("durable")+"\n";
	line += "�ˮ`: "+ob->query("weapon_prop/damage")+"\t";
	line += "���m: "+ob->query("armor_prop/armor")+"\n";	
	
	write(line);
	return 1;
}