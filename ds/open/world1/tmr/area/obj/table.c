//table.c
inherit  ITEM;
void  create()
{
	set_name("�ۮ�",({"table"}));
	set_weight(200000);
        set("long","�o�O�i�j�z�ۻs����l�C\n");
	if(clonep()) set_default_object(__FILE__);
	else
	{
		set("unit",  "�i");
		set("material",  "stone");
		set("value",  2000);
		set("no_get",  1);
		set("amount",30);
	}
	setup();
}

string long()
{
	string str,temp;
    str="�o�O�i�j�z�ۻs����l�C\n\n";
	if(environment()) temp=environment()->show_game();
	if(strlen(temp)>2) str+=temp;
	return str;
}
