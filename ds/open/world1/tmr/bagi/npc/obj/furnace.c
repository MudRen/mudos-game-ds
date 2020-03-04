#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("���l",({"furnace"}) );
	set_weight(15000);
	set("long",@long
�@�ӫC�ɰ������l�A�h�O��h�Ψӽm��������A�h�b������촡�b�a
�W(setup)�A�]�i�ް_(dispose)�C
long
);
         set_max_encumbrance(10000);
         set_max_capacity(50);

	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",300);
	}
	setup();
}

void init()
{
	add_action("do_setup","setup");
	add_action("do_dispose","dispose");

}

int do_setup(string arg)
{
	object me,ob;
	string what;
	int flag=0;
	me=this_player();
	ob=this_object();

        if( !arg || sscanf(arg, "furnace on %s", what)!=1 )
		return notify_fail("���O�����Gsetup furnace on [���] \n");

	if(ob->query("setup_down") ) 
		return notify_fail("�����l�w�����w�M���b�g�̤F�C\n");
        switch(what)
        {
         case "east":
         ob->set_name("���l["HIG +"���"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "west":
         ob->set_name("���l["HIG +"�I��"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "south":
         ob->set_name("���l["HIG +"����"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "north":
         ob->set_name("���l["HIG +"����"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "southeast":
         ob->set_name("���l["HIG +"�S��"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "southwest":
         ob->set_name("���l["HIG +"�[��"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "northeast":
         ob->set_name("���l["HIG +"�_��"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

         case "northwest":
         ob->set_name("���l["HIG +"����"+ NOR"]",({"furnace"}) );
	 flag =1;
	 break;

	 default:
	 flag =0;
	 break;
	}
	if(flag==0) return notify_fail("�S���o�ؤ��\n");

	message_vision("$N�b�a�W���F�Ӭ}�ޡA�⤦�l���Ӥ���\\�n�C\n",me,ob);
	ob->move(environment(me) );
	ob->set("no_sac",1);
	ob->set("no_get",1);
	ob->set("setup_down",1);

	return 1;
}

int do_dispose(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();

	if(!ob->query("setup_down") ) return notify_fail("�����l�èS���Q���b�g�̡C\n");

	message_vision("$N���\\�b�a�W��$n�ޤF�X�ӡC\n",me,ob);
	ob->move(environment(me) );
	ob->set("no_sac",0);
	ob->set("no_get",0);
	ob->set("setup_down",0);
	ob->set_name("���l",({"furnace"}) );
	return 1;
}

void fire_pill(object ob)
{
	object *inv,ash;
	int i,a,b,p;
	p=ob->query("fire_power");

	inv = all_inventory(this_object() );
	if( sizeof(inv) )
	{
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id")=="mixture" )
		{
		inv[i]->add("fire",p+random(p/2) ); 
		a=inv[i]->query("pill");
		b=inv[i]->query("fire");
		inv[i]->set_name("�t��["+chinese_number(b*10/a )+"������]",({ "mixture" }) );
		inv[i]->set("pill",a);
		if(b > (a+a/10) )  //�W�L�Q�����ԡA�ন�J��
		{
			ash=new(__DIR__"ash");
			ash->move(environment(inv[i]) );
			destruct(inv[i]);
		}
		}
	}
}

}
