inherit ITEM;

void set_warname(string id)
{
	set("long",query("long")+"\n����̡G"+id +"    �����p");
        set("owner_user",id);
}

void create()
{
	set_name("��Y�߸g",({"bore book","book","_BUDDHA_WAR_BOOK_"}) );
	set_weight(80);
	set("long",@long
�@����Y�߸g�A�A½�F½�X���A�����O���g�����g��A�A�@�Ӧr�]
�ݤ����C
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",0);
	}
	setup();
}
