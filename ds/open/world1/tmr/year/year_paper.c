inherit ITEM;

void create()
{
	set_name("�~�~����",({"year paper","paper"}) );
	set_weight(100);
	set("long",@long
�@�i����A�Ѧ~�~�D�����~�ש�����ʤ���Ӫ��C	
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","�i");
		set("value",1);
	        set("volume",1);
                set("material","paper");
	}
	setup(); 
}

void set_level(int i)
{
	string arg;
	arg ="�@�i����A�Ѧ~�~�D�����~�ש�����ʤ���Ӫ��C\n";
	arg+="�W�Y�L�F"+chinese_number(i)+"�Ӳ���j���L�C\n";
	this_object()->set("long",arg);
	this_object()->set("level",i);

	return;
}