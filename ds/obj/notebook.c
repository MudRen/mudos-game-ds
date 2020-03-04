// notebook.c
// �W���ק���: 2000.4.15 0:51
// �W���ק��: Luky
// �ק鷺�e: �إ�����
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;
// pages =([ "page0":([ "note":({""}), "memo":"", ]), .. ])
mapping pages = ([ ]);
// quests = ([ "QuestID": 0(������) or 1(�w����) ,...]);
mapping quests = ([ ]);
int index=0;
void create()
{
	set_name("�_�I�⥾", ({ "adventure notebook","notebook","quest_ob" }) );
	set("long",@LONG

�o�O�@���p��U�A�Ψ����U�_�I�a�̰O���g���L���U�بƥ�A�H��
�|�����������Ƚu���A�z�i�H�ΥH�U�����O�Өϥγo���⥾:

readmenu        	�[�ݤ�U�ؿ��C
turn page <���X>	½��Y�@���C
readnote <���X>		�[�ݤ⥾����C
write <��r>		�N<��r>�g�J�⥾�ťճB�C
erase			�����ۤv�[�W����r�C

LONG
	);
	set("unit", "��");
	set("no_drop", 1);
	set("no_put", 1);
	set("no_insert", 1);
	set("no_steal", 1);
	seteuid(getuid());

}
string long()
{
	string out;
	out = @LOOK

�o�O�@���p��U�A�Ψ����U�_�I�a�̰O���g���L���U�بƥ�A�H��
�|�����������Ƚu���A�z�i�H�ΥH�U�����O�Өϥγo���⥾:

readmenu        	�[�ݤ�U�ؿ��C
turn page <���X>	½��Y�@���C
readnote <���X>		�[�ݤ⥾����C
write <��r>		�N<��r>�g�J�⥾�ťճB�C
erase			�����ۤv�[�W����r�C

LOOK;
	if(index == 0) out+="�ثe�⥾½��F�ؿ����C\n";
	else out+="�ثe�⥾�w�g½��F��"+index+"���C\n";
	return out;
}
int set_owner(string id)
{
	set("owner_id", id);
	index = 0;
	return restore();
}

int clear_pages()
{
	pages = ([ ]);
	QUEST_D->do_save(this_object());
	return 1;
}
int clear_quests()
{
	quests = ([ ]);
	QUEST_D->do_save(this_object());
	return 1;
}
mapping query_quests()
{
	return quests;
}
mapping query_pages()
{
	return pages;
}
int set_quests(string which,int info)
{
	quests[which] = info;
	QUEST_D->do_save(this_object());
	return 1;
}
// �W�[�����O��
varargs int add_quests_note(string questid,string note)
{
	string pagekey;
	pagekey = QUEST_D->find_quest_page(questid);
	if(pagekey=="") return 0; //�S��������
	if(!undefinedp(quests[pagekey]) && quests[pagekey]>0) return 0; //�����Ȥw����
	if(undefinedp(pages[pagekey]))
	{
		pages[pagekey] = ([ "note":({note}), "memo":"", ]);
	}
	else if(undefinedp(pages[pagekey]["note"]))
	{
		pages[pagekey]["note"]=({note});
	}
	else if(member_array(note,pages[pagekey]["note"])==-1)
	{
		pages[pagekey]["note"]+=({note});
	}
	else return 0;
	if(environment()) tell_object(environment(),"[ �_�I�⥾��s�F ]\n");
	QUEST_D->do_save(this_object());
	return 1;
}

string *query_quest_note(string questid)
{
	string pagekey,*msg=({});
	pagekey = QUEST_D->find_quest_page(questid);
	if(pagekey=="") return msg;
	if(undefinedp(pages[pagekey])) return msg;
	else if(undefinedp(pages[pagekey]["note"])) return msg;
	else msg = pages[pagekey]["note"];
	return msg;
}

void init()
{

	if( this_player() && environment()==this_player() )
	{
		set_owner( (string)this_player()->query("id") );
		this_player()->set_temp("notebook", this_object());
		set_name(this_player()->name(1) +"���_�I�⥾", ({ "adventure notebook","notebook","quest_ob" }) );
		add_action("do_readmenu", "readmenu");
		add_action("do_readnote", "readnote");
		add_action("do_turn", "turn");
		add_action("do_write", "write");
		add_action("do_erase", "erase");
	}
}
int query_index()
{
	return index;
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return DATA_DIR + "note/" + id[0..0] + "/" + id;
}

int do_readmenu(string arg)
{
	string str="";
	str = QUEST_D->show_page(0,this_object());
	this_player()->start_more(str);
	return 1;
}

int do_readnote(string arg)
{
	string str="",indexpage,*notes;
	int i,num,max;
	if(arg)
	{
		if( sscanf(arg, "%d", num)!=1 ) return notify_fail("readnote <���X>�C\n");
		max = QUEST_D->query_maxpage(this_object());
		if(num < 0 || num>max) return notify_fail("�n���S���o�@���a�C\n");
	} else num = index;
	str = QUEST_D->show_page(num,this_object());
	indexpage = "page"+sprintf("%d",num);
	if(!undefinedp(pages[indexpage]) && !undefinedp(pages[indexpage]["note"]))
	{
		notes = pages[indexpage]["note"];
		str+="========== �ثe���o������ ==========\n";
		for(i=0;i<sizeof(notes);i++) str+="["+(i+1)+"] "+notes[i]+"\n";
	}
	this_player()->start_more(str);
	return 1;
}

int do_turn(string arg)
{
	int num,maxpage;
	if( !arg || sscanf(arg, "page %d", num)!=1 ) return notify_fail("�A�n�N�⥾½����@���S\n");
	maxpage = QUEST_D->query_maxpage(this_object());
	if(num < 0 || num > maxpage) return notify_fail("�n���S���o�@���a�C\n");
	if(num == index) return notify_fail("�A���⥾�w�g½���"+index+"���F�C\n");
	index = num;
	tell_object(this_player(),"�A�N��U½���"+index+"���C\n");
	return 1;
}

int do_write(string arg)
{
	write("�ثe�٤���ϥγo�ӫ��O�C\n");
	return 1;
}

int do_erase(string arg)
{
	write("�ثe�٤���ϥγo�ӫ��O�C\n");
	return 1;
}
int query_step(string questid)
{
	if(undefinedp(quests[questid])) return 0;
	return quests[questid];
}
//void owner_is_killed() { destruct(this_object()); }
