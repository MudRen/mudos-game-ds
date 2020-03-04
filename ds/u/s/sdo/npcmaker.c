// roommaker.c
// for ESLib

#define RMK_VERSION "(v1.1)"

inherit ITEM;
inherit F_AUTOLOAD;

string *special_props = ({
	"short", "long" });
int check_legal_id(string id);
int check_legal_name(string name);
int save_npc_file(string yn, string file, string str, object obj);
object npc;
string file;
void create()
{
	set_name("NPC�s�边" + RMK_VERSION, ({ "npcmaker", "maker" }) );
	set_weight(100);
	set("unit", "��" );
	set("long", @LONG
�o�O�@�ӥΨӡu�ֳt�v�s�yNPC���u��M���U�ɶ����h�Φ��Y��  lag ���Ův
�Q�νu�W��J�s�y²�檺�ж��M���L�p�G�A�Q�����ۤv�ϰ�NPC���~��M�̦n
���n�Ө̿�o�ӪF��M�A�i�H�ϥΥH�U�X�ӫ��O�R

mknpc    �y�X�@�ӷs��NPC.

by Luky.2.23.1999
LONG
	);
}

int query_autoload() { return 1; }

void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("do_mknpc", "mknpc");
	}
}

int do_mknpc(string arg)
{
	string id, path;
        int i;
        
        seteuid(geteuid(this_player()));
        i=1;
        id=geteuid(this_player());
	path = user_path(id);
	file = sprintf("%snpc/%d.c",path,i);


	while( file_size(file)!=-1 )
	{
	 i++;
	 file = sprintf("%snpc/%d.c",path,i);
	}
	if( !write_file(file, 
@NPC_CODE
// This is a npc made by npcmaker.

inherit NPC;

void create()
{
	set_name( "�ܢޢ�", ({ "npc" }));
	set("long", "�o�O�@�ӼзǪ�NPC�C\n");
	set("age", 1);
	set("level",1);
	set("race", "�H��");
	setup();
}
NPC_CODE
	) ) return notify_fail("�A�S���g�J�ɮ�(" + file +")���v�Q�C\n");
	message_vision("�uť��$N��NPC�s�边�u�͡v���@�n�M�Aı�o�o�ӥ@�ɪ��Ǫ��S�ܦh�F�@�I�C\n", this_player());
        npc=new(file);
        npc->move(environment(this_player()));
        write("\nNPC���^��W�r�R");
	input_to("get_id", npc);
	return 1;
}
void get_id(string arg, object obj)
{
 	if( arg=="" )
 	{
		write("NPC���^��W�r�R");
		input_to("get_id", obj);
		return;
	}
	
	if( !check_legal_id(arg))
	{
		write("NPC���^��W�r�R");
		input_to("get_id", obj);
		return;
	}
	obj->set("id",arg);
        write("NPC������W�r�R");
	input_to("get_name", obj);
}
void get_name(string arg, object obj)
{
 	if( arg=="" )
 	{
		write("NPC������W�r�R");
		input_to("get_name", obj);
		return;
	}
	
	if( !check_legal_name(arg))
	{
		write("NPC������W�r�R");
		input_to("get_name", obj);
		return;
	}
	obj->set("name",arg);
        write("NPC���ԭz�R");

	input_to("get_long", obj);
}

void get_long(string arg, object obj)
{
 	if( arg=="" )
 	{
		write("NPC���ԭz�R");
		input_to("get_long", obj);
		return;
	}
	
	obj->set("long",arg);
        write("NPC���رڡR(1)�H��  (2)���~:");
	input_to("get_race", obj);
}

void get_race(string arg, object obj)
{

 	if( arg=="1" )
 	{
		write("NPC���رڡR�H�� \nNPC���~�֡R");
		obj->set("race","�H��");
		input_to("get_age", obj);
		return;
	} else
 	if( arg=="2" )
 	{
		write("NPC���رڡR���~ \n���~�}�o�� \n");
		return;
	} else
	{
        write("NPC���رڡR(1)�H��  (2)���~:");
	input_to("get_race", obj);
        }
 return ;
}

void get_age(string arg, object obj)
{
 int age;

 	if(sscanf(arg,"%d",age)!=1)
 	{
		write("NPC���~�֡R");
		input_to("get_age", obj);
		return;
	}	

	obj->set("age",age);
        write("\nNPC�����šR");
	input_to("get_level", obj);
}

int get_level(string arg, object obj)
{
 int level;
	string str, *name;
 	mapping prop;
	int i;
  	if(sscanf(arg,"%d",level)!=1)
 	{
		write("NPC�����šR");
		input_to("get_level", obj);
		return 1;
	}
	

 
	obj->set("level",level);
	write("�s�b�ɮ� " + file + "?[y/n]");
	
	
	str = "// Npc: " + file + 
@ROOM_CODE


inherit NPC;

void create()
{
ROOM_CODE
;
	str += sprintf("\tset_name(\"%s\", ({\"%s\"}) );\n", obj->query("name"),obj->query("id") );
	str += sprintf("\tset(\"long\", \"%s\\n\");\n", obj->query("long") );
	str += sprintf("\tset(\"race\", \"%s\");\n", obj->query("race") );
	str += sprintf("\tset(\"age\", %d);\n", obj->query("age") );
	str += sprintf("\tset(\"level\", %d);\n", obj->query("level") );
//	prop = obj->query_entire_dbase();
//	name = keys(prop);
//	for(i=0; i<sizeof(name); i++) {
//		if( member_array(name[i], special_props)!=-1 ) continue;
//		str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]] );
//	}
	str += "\n\tsetup();\n\n}\n";


//	if( file_size(file)!=-1 ) {
//		write("�s�b�ɮ� " + file + " �ܡS[y/n]");
		input_to("save_npc_file", file, str, obj);
//		return 1;
//	}

//	return save_npc_file("y", file, str, obj);

}

int save_npc_file(string yn, string file, string str, object obj)
{
 object ob;
	if( strlen(yn)<1 || yn[0]!='y' ) return 1;

	rm(file);
	write("�s�� " + file + "....");
	if( write_file(file, str) )
	{
		write("Ok.\n");
		ob = find_object(file);
		destruct(obj);
		destruct(ob);
		
		ob=new(file);
		ob->move(environment(this_player()));
		return 1;
	} else
		return notify_fail("�A�S���g�J�o���ɮ�(" + file + ")���v�Q�C\n");
}

void owner_is_killed() { destruct(this_object()); }

int check_legal_id(string id)
{
	int i;

	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
		write("�藍�_�M�^��W�r�����O 3 �� 12 �ӭ^��r���C\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("�藍�_�M�^��W�r�u��έ^��r���C\n");
			return 0;
		}
	return 1;
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	
	if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
		write("�藍�_�M����W�r�����O 1 �� 6 �Ӥ���r�C\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("�藍�_�M����W�r����α���r���C\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�藍�_�M�бz�Ρu����v���W�r�C\n");
			return 0;
		}
	}

	return 1;
}
