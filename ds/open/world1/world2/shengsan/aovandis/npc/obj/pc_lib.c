// �Ϯ��]�q��
#include <path.h>
inherit ITEM;

object bookroom;

void create()
{
	set_name("�Ϯ��]�q��",({"library computer","computer"}) );
	set("long",@LONG
	�A�i�H�z�L�o�x�q���d�ߨì��z���X�A�n�����y�C

	seek [�ѦW][-k ���O][-n �s��][-a �@��]
	getbook [�s��]
LONG
	);
	set_weight(15000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",75000);
		set("unit","�x");   //luky
	}
	set("no_get",1);
	set("no_sac",1);
	set("bookroom",SHENGSAN2"aovandis/bookroom");
	setup();
}

void init() 
{
//	::init();
	add_action("do_seek","seek");
	add_action("do_getbook","getbook");

}

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}

int seek_name(string name)
{
	object *books;
	int i,gotit;
	string line,tmp,tmp2;

	if(!bookroom) return 0;
	books = all_inventory(bookroom);
	books = sort_array(books, "sort_item", this_object());

	line = sprintf(	"�j�M�ѦW��: %s\n"
			"=============================================================\n"
			"= �s �� = ��                          �W = �@    �� = �� �q =\n"
			"=============================================================\n",
			name);
	for(i=0;i<sizeof(books);i++)
	{
		if(sscanf(books[i]->query("name"),"%s"+name+"%s",tmp,tmp2)==2)
		{
			line += sprintf(
				"= %5d = %-30s = %-8s = %5d =\n",
				books[i]->query("bookno"),
				books[i]->query("name"),
				books[i]->query("bookauthor"),
				1);
			gotit++;
		}
	}
	if(gotit)
		line += sprintf("=============================================================\n");
	line += sprintf("�@�j�M�� %d ���ŦX���󪺸��...\n",gotit);

	this_player()->start_more(line);

	return 1;
}

int seek_kind(string kind)
{
	object *books;
	int i,j,gotit;
	string line,*kindarry;

	if(!bookroom) return 0;
	books = all_inventory(bookroom);
	books = sort_array(books, "sort_item", this_object());

	line = sprintf(	"�j�M�ϮѺ�����: %s\n"
			"=============================================================\n"
			"= �s �� = ��                          �W = �@    �� = �� �q =\n"
			"=============================================================\n",
			kind);
	for(i=0;i<sizeof(books);i++)
	{
		kindarry = books[i]->query("bookkind");
		for(j=0;j<sizeof(kindarry);j++)
		{
			if(kindarry[j] == kind)
			{
				line += sprintf(
					"= %5d = %-30s = %-8s = %5d =\n",
					books[i]->query("bookno"),
					books[i]->query("name"),
					books[i]->query("bookauthor"),
					1);
				gotit++;
			}
		}
	}
	if(gotit)
		line += sprintf("=============================================================\n");
	line += sprintf("�@�j�M�� %d ���ŦX���󪺸��...\n",gotit);

	this_player()->start_more(line);

	return 1;
}

int seek_bookno(int bookno)
{
	object *books;
	int i,gotit;
	string name,line,author;

	if(!bookroom) return 0;
	books = all_inventory(bookroom);
	for(i=0;i<sizeof(books);i++)
	{
		if(books[i]->query("bookno") == bookno)
		{
			name = books[i]->query("name");	
			author = books[i]->query("bookauthor");
			gotit++;
		}
	}
	if(gotit)
	{
		line = sprintf(
			"�j�M�Ϯѽs����: %d\n"
			"=============================================================\n"
			"= �s �� = ��                          �W = �@    �� = �� �q =\n"
			"=============================================================\n"
			"= %5d = %-30s = %-8s = %5d =\n"
			"=============================================================\n",
			bookno,bookno,name,author,gotit);
	}
	else line = "Sorry...���j�M��z�n�䪺�Ϯ�...�i��w�g�Q�O�H�ɨ��o�C\n";
	write(line);
	return 1;
}

int seek_author(string author)
{
	object *books;
	int i,gotit;
	string line;

	if(!bookroom) return 0;
	books = all_inventory(bookroom);
	books = sort_array(books, "sort_item", this_object());

	line = sprintf(	"�j�M�Ϯѧ@�̬�: %s\n"
			"=============================================================\n"
			"= �s �� = ��                          �W = �@    �� = �� �q =\n"
			"=============================================================\n",
			author);
	for(i=0;i<sizeof(books);i++)
	{
		if(books[i]->query("bookauthor") == author)
		{
			line += sprintf(
				"= %5d = %-30s = %-8s = %5d =\n",
				books[i]->query("bookno"),
				books[i]->query("name"),
				books[i]->query("bookauthor"),
				1);
			gotit++;
		}
	}
	if(gotit)
		line += sprintf("=============================================================\n");
	line += sprintf("�@�j�M�� %d ���ŦX���󪺸��...\n",gotit);

	this_player()->start_more(line);

	return 1;
}

int do_seek(string arg)
{
	int seekno,bookno;
	string kind,name,author;
	if(!arg) return notify_fail("seek [�ѦW][-k ���O][-n �s��][-a �@��]\n");
	if(!bookroom=load_object(this_object()->query("bookroom"))) return 0;
	if(sscanf(arg,"-%s",kind))
	{
		if(sscanf(arg,"-k %s",kind)==1)
			seekno = 2;
		else if(sscanf(arg,"-n %d",bookno)==1)
			seekno = 3;
		else if(sscanf(arg,"-a %s",author)==1)
			seekno = 4;
		else return notify_fail("seek [�ѦW][-k ���O][-n �s��][-a �@��]\n");
	}
	else
	{
		seekno = 1;
		name = arg;
	}

	switch(seekno)
	{
		case 1: seek_name(name);break;
		case 2: seek_kind(kind);break;
		case 3: seek_bookno(bookno);break;
		case 4: seek_author(author);break;
		default: return notify_fail("seek [�ѦW][-k ���O][-n �s��][-a �@��]\n");
	}
	return 1;
}

int do_getbook(string arg)
{
	int gotit,bookno;
	object *books,me,ob;

	if(!arg) return notify_fail("getbook [�s��]\n");
	if(sscanf(arg,"%d",bookno)!=1) return notify_fail("getbook [�s��]\n");
	if(!bookroom=load_object(this_object()->query("bookroom"))) return 0;
	me = this_player();

	if(ob=present("book"+bookno,bookroom))
	{
		gotit++;
		if(!me) return 0;
	 	ob->move(me);
	 	bookroom->save();
		me->save();
		message_vision("\n$n����Ϯ��]���۰ʤƳ]�ơA�ֳt���N�y"+ob->query("name")+"�z�����F$N�C\n",me,this_object());
	}
	else
		write("Sorry...�Ϯ��]���ثe�èS���s���� "+bookno+" ���ϮѡC\n");

	return 1;
}