inherit ITEM;
void create()
{
	set_name("�t��",({"mixture","nine ti pill"}) );
	set_weight(200);
	set("long",@long
�@���ħ��t��A�|���һs����(prepare)�A�ҥH�ݤ��X�ӬO���ؤ�������C
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
	set("value",50);
	set("unit","��");
	set("pill",100);  //�N�ҩһݤ���
	}	
	setup();
}

void init()
{
	add_action("do_prepare","prepare");
}

int do_prepare()
{
	object pill,me,ob;
	int a,b;
	me=this_player();
	ob=this_object();
	pill=new(__DIR__"nine-pill.c");

	a=ob->query("fire");
	b=ob->query("pill");
	if(!a || !b || a < b)
		return notify_fail("�o���t���٥��N�ҦܤQ�����ԡA����s���C\n");
	message_vision("$N��$n�s���@��"+pill->query("name")+"�C\n",me,ob);
	pill->move(me);
	destruct(ob);
	return 1;
}