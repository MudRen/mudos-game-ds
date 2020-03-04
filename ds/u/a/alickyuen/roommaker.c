#define RMK_VERSION "(v2.0.Lsr.FF Alpha)"

#include <ansi.h>
 
inherit ITEM;
inherit F_AUTOLOAD;
 
int show_table(string arg);
int get_main_choice(string choice);
int make_room(string arg);
int show_room_item();
int get_room_item(string arg);
int set_room_item(string arg,string item);
int show_room_flag();
int set_room_flag(string flag);
int show_room_all();
int get_delete_item(string item);
int save_room(); 
int save_room_file(string yn, string file, string str);
int do_read(string arg);
string *special_props = ({ "short" , "long" });
 
mapping tmp;
 
mapping room_flag =  ([
	"1" : (["cname": "�T��I�k",  "name" : "no_magic", "set" : 0 ]),
	"2" : (["cname": "�T��԰�",  "name" : "no_fight", "set" : 0 ]),
        "3" : (["cname": "����", "name" : "resource/water", "set" : 0 ]),
	"4" : (["cname": "�ǥ~", "name" : "outdoors", "set" : 0 ]),
	"5" : (["cname": "�x�s�I (�q�`�O�}�۪�)", "name" : "valid_startroom", "set" : 1 ])
]);
 
mapping room_item = ([
	"short" : "�ж��W",
	"long"  : "���ԭz",
	"outdoors" : "�ݩ���ϰ�(�ǥ~�~�ݳ])",
	"detail/" : "���~�y�z",
	"objects of file" : "����",
	"exits/dir"	: "�X�f",
	"others" : "��L"
]);
 
void create()
{
	set_name("�ж��s�y��" + RMK_VERSION, ({ "new_maker", "maker" }) );
	set_weight(100);
	set("unit", "��" );
	set("long", @LONG
    �o�O�@�ӥΨӻs�y�έק�ж����u��M���U�Ův��b�u�W�ק��
�гy�ж��C���L�u�ണ�Ѱ򥻪��]�w�C�Y�Q���D���s�y���ԲӥΪk�M
�Х� read maker�C

��ĳ�ϥΫe�Х��ݤ@�ݪ`�N�ƶ�, �ݪ`�N�ƶ�����k: �Х� read note�C

�Ъ`�N ! �Ф��n�b�w�g�g�n���ӥB�� set  �H�~��ƪ��ж��ϥ�
saveroom  ���\��. �_�h�|�}�a�z�����W�W�g�n����ƤίS��\��.
LONG
	);
}
 
void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("show_table", "run");
		add_action("do_read", "read");
		
	// modify by Lsr �H�U�o�ǬO�Ӧ�v1.1 ����
		add_action("xdo_make_room", "mkroom");
		add_action("xdo_rset", "rset");
		add_action("xdo_connect", "connect");
		add_action("save_room", "saveroom");
	}
}
 
 
int show_table(string arg)
{
	write("
 
");
	write("1. �гy�s�ж�(create room)		\n");
	write("2. �]�w�ж�����(set room item)		\n");
	write("3. �]�w�ж����ݩ�(set default flag)	\n");
	write("4. �M���ж�����(delete room item)	\n");
	write("5. �x�s�ж����(save room)		\n");
	write("�� �`�N�G�Y�L�x�s�h�ק�L�Į@�C ��	\n");
 	write("�п�J�Ʀr���(1-5)�M�ο�J quit ���}�C	\n");
	write("=>");
	input_to("get_main_choice");
	return 1;
}
 
int get_main_choice(string choice)
{
	switch(choice)
	{
		case "1":
			write("
 
�п�J�ж��ɦW:");
			input_to("make_room");
			return 1; break;
			
		case "2":
			return show_room_item();
			break;
 
		case "3":
			return show_room_flag();
			break;
 
		case "4":
			return show_room_all();
			break;
 
		case "5":
			return save_room();			
			break;
 
		case "quit":	
			tmp = ([]);
			return 1; break;
		default:
			write("�L���ﶵ�C\n");
			call_out("show_table",1);			
	}
	return 1;
}

int xdo_make_room(string arg)
{
        string file, dir, code;

        if( !arg ) return notify_fail("���O�榡�Rmkroom <�ж��ɦW> \n");
        if( sscanf(arg, "%s %s", file, dir)!=2 )
                file = arg; 
	make_room(arg);   
	return 1;
}
 
int make_room(string arg)
{
	string file, room;
 
	seteuid(geteuid(this_player()));
// Modified by Spock...:D
	if( sscanf( arg, "%s.c", room) == 1)
		file = resolve_path(this_player()->query("cwd"), room) + ".c";
	else file = resolve_path(this_player()->query("cwd"), arg) + ".c";

	if( file_size(file)!=-1 )
	{	
		write("�ɮ� " + file + " �w�g�s�b�F.\n");
		call_out("show_table",1);
		return 1;
	}
 
	if( !write_file(file, @ROOM_CODE
// room by Lsr@FSS

#include <ansi.h>
#include <room.h>

inherit ROOM;

//02____05________10________15________20________25________30________35________40__(����r)

void create()
{
	set("short", "short");
	set("long",@LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	setup();
}
ROOM_CODE
	) ) return notify_fail("�A�S���g�J�ɮ�(" + file +")���v�Q�C\n");
	message_vision(CYN"�uť��$N"NOR+CYN"���ж��s�边"HIW"�u�͡v"NOR+CYN"���@�n�M�Aı�o�o�ӥ@�ɤS�ܤj�F�@�I�C\n"NOR, this_player());
 
	call_out("show_table",1);	
	return 1;
}

int xdo_connect(string arg)
{
        mapping exits;
        string dir, file;

        if( !arg || sscanf(arg, "%s %s", dir, file)!=2 )
                return notify_fail("���O�榡�Rconnect <��V> <�ж��ɦW>\n");
        file = resolve_path(this_player()->query("cwd"), file);
        exits = environment(this_player())->query("exits");
        if( mapp(exits) )
                exits[dir] = file;
        else
                environment(this_player())->set("exits", ([ dir: file ]) );
        write(HIW"Ok.\n"NOR);
        return 1;
}

int xdo_rset(string arg)
{
        string prop, str;
        mixed data;

        if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
                return notify_fail("���O�榡�Rrset <�ж��ݩ�> <�ݩʤ��e>\n");

        if( sscanf(str, "%d", data)!=1 )
                data = str;

        environment(this_player())->set(prop, str);
        write(HIW"Ok.\n"NOR);
        return 1;
} 

 
int show_room_item()
{
	int i;
	string *items;
	
	write("
 
== �п�ܭn�]�w���ж����� ==\n");
	items = keys(room_item);
	for(i = 0; i< sizeof(items); i++)
		write(room_item[items[i]]+"("+items[i]+")\n");	
		
	write(HIW"=>"NOR);
	input_to("get_room_item");
	return 1;
}
 
int get_room_item(string arg)
{
	string dir;
 
	write("
 
== �]�w "+ arg +" ��( �� . ���� ) ==�G\n");
 
	if( strsrch(arg,"objects") != -1 )
	{
		sscanf(arg,"objects of %s",dir);
		if( !find_object(dir) )
		{
			write("�L������M���ˬd���|���L�]���C\n");
			call_out("show_table",2);
			return 1;
		}	
	}
 
	input_to("set_room_item",arg);
	return 1;
}
 
int set_room_item(string arg,string item)
{
	string dir;
	int num;
	if(arg == ".") {
		write(HIW" OK!!\n"NOR);
		if( strsrch(item,"objects") != -1 )
		{
			sscanf(item,"objects of %s",dir);
			sscanf(tmp[item],"%d",num);
			environment(this_player())->set("objects", ([ dir:num ]));				
 
		} else if( !undefinedp(tmp[item]) ){
			environment(this_player())->delete(item);
			environment(this_player())->set(item,tmp[item]);
		}
		call_out("show_table",1);
		return 1;
	}
	if(!mapp(tmp))
		tmp = ([ item : arg ]);
	else
	{		
		if( !undefinedp(tmp[item]) )
			tmp[item] += arg + "\n";
		else if(item == "long")	
			tmp[item] = arg + "\n";	
		else 	tmp[item] = arg;
	}
	
	input_to("set_room_item",item);
	return 1;
}
 
int show_room_flag()
{
	string str,j,*flags;
	int i;
	str = "
 
";
	
	if(sizeof(room_flag) )
	{
		for(i=1;i<=sizeof(room_flag);i++)
		{
			
			j = sprintf("%d",i);
			if(environment(this_player())->query(room_flag[j]["name"]) )
				room_flag[j]["set"] = 1;
			else	room_flag[j]["set"] = 0;	
 
			str += sprintf("%s. [%s]  %s(%s)\n",j,
			(room_flag[j]["set"])? "��":"  ",
			room_flag[j]["cname"],room_flag[j]["name"]);
		}	
		str += "�п�ܷQ�]�w���ݩ�(1 - 5 ,���� enter ����D���)�G";
		write(str);
		input_to("set_room_flag");
		return 1;
	}		
}
 
int set_room_flag(string flag)
{
	object me = this_player();
	object env = environment(this_player());
 
	if(!room_flag[flag])
	{
		call_out("show_table",1);
		return 1;	
	}
	else
	{
		if(env->query(room_flag[flag]["name"]) )
			env->delete(room_flag[flag]["name"]);				
		else	env->set(room_flag[flag]["name"],1);
 
		call_out("show_room_flag",1);
		return 1;	
	}
	
}
 
int show_room_all()
{
	string str,*item;	
	int i;
	mapping room;
	
	str = "
 
�U���O���ж��Ҧ��������M�п�ܭn�R�����C\n";
	
	room = environment(this_player())->query_entire_dbase();
	if(sizeof(room) )
	{
		item = keys(room);	
		for(i=0 ;i<sizeof(item); i++)
			str += sprintf(" %s\t\t�J %O\n",item[i],room[item[i]]);			
		this_player()->start_more(str);
		write(HIW"=>"NOR);	
		input_to("get_delete_item");
		return 1;
	} else {
		write("���ж��L�����ơC\n");
		call_out("show_table",1);
		return 1;
	}
}
 
int get_delete_item(string item)
{
	if( environment(this_player())->delete(item) )
		write(HIW"OK!!\n"NOR);
	else	write("�L����ƥi�R���C\n");
	
	call_out("show_table",1);
	return 1;
}
 
int save_room()
{
	object env;
	string str, *name, file;
	mapping prop;
	int i;
 
	env = environment(this_player());
	file = file_name(env) + ".c";
	str = "// " + file + @ROOM_CODE
 
// by Lsr@FSS
#include <ansi.h>

inherit ROOM;

//02____05________10________15________20________25________30________35________40__
 
void create()
{
ROOM_CODE
	;
	str += sprintf("\tset(\"short\", %O);\n", env->query("short") );
	str += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", env->query("long") );
	prop = env->query_entire_dbase();
	name = keys(prop);
	for(i=0; i<sizeof(name); i++) {
		if( member_array(name[i], special_props)!=-1 ) continue;
		str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]] );
	}
	str += "\n\tsetup();\n\t}\n";
 
	// Replace current directory with __DIR__ macro to make relocatable code.
	i = strlen(file)-1;
	while( (i > 0) && (file[i]!='/')) i--;
	if( i>0 ) {
		write("�ثe�ؿ��R" + file[0..i] + " �H __ROOM_DIR__ ���N�C\n");
		str = replace_string(str, "\"" + file[0..i], "__ROOM_DIR__\"");
	}
 
	if( file_size(file)!=-1 ) {
		write("�ɮ� " + file + " �w�s�b�M�n�R�����ɶܡS[y/n]");
		input_to("save_room_file", file, str);
		return 1;
	}
 
	return save_room_file("y", file, str);
}
 
int save_room_file(string yn, string file, string str)
{
	if( strlen(yn)<1 || yn[0]!='y' ) return 1;
 
	rm(file);
	tmp = ([]);
	write("�s�� " + file + "....");
	if( write_file(file, str) ) {
		write(HIW"Ok.\n"NOR);
		return 1;
	} else
		return notify_fail("�A�S���g�J�o���ɮ�(" + file + ")���v�Q�C\n");
}
 
void owner_is_killed() { destruct(this_object()); }
int query_autoload() { return 1; }
 
int do_read(string arg)
{
	string str,note;
	object ob;
	ob = this_player();
	
	str = @HELP
== Roommaker 1.9 �� ==   �@��: Smallpp

 A. �\�઺�Ĥ@����.
 
�Ұ� roommaker  =>  run
 
�|�X�{�@�ӿ��
1. �гy�s�ж�(create room)
2. �]�w�ж�����(set room item)
3. �]�w�ж����ݩ�(set default flag)
4. �M���ж�����(delete room item)
5. �x�s�ж����(save room)
�� �`�N�G�Y�L�x�s�h�ק�L�Į@�C ��
�п�J�Ʀr���(1-5)�M�ο�J quit ���}�C
=>
�A�ӿ�满������Y�i.


 B. �\�઺�ĤG����. [�Ӧ�roommaker v1.1]

mkroom <�ж��ɦW>

    �y�X�@�ӡu�šv�ж��M����A�i�H goto ��o�өж��� rset �]�w�ж���
    �ԭz���ݩʡC
    
rset <�ж��ݩ�> <�ݩʤ��e>

    �]�w�A�ثe�Ҧb�ж����ݩʡM�p short�Mlong ���C

connect <��V> <�ж��ɦW>

    �N�A�ثe�Ҧb���ж��s���@�ӥX�f��t�@�өж��C

saveroom

    �N�A�ثe�Ҧb���ж��s�ɡC           


PS. ���ĤG�������\��Ĥ@�����̭��w�g�����F, �u�O���F�ߺD�ϥ�v1.1�����Ův. 
 
HELP;
	note = @NOTE

 			++++ �` �N �� �� ++++
 
 A. �гy�X�Ӫ��s�ж��|���A�Ҧb���ؿ��U(�Yls �ɬݨ쪺�ؿ�)

 B. �]�w�ж��������X�Ӥ����n�`�N �榡
     1.��L(others)          �o�Ӥ��O�s�A��J others, �ӬO����r��ҥi
     2.�X�f(exits/dir)            �Ҧp  exits/north    exits/enter
     3.����(objects of file)      �Ҧp: objects of /d/locity/npc/cat
     4.���~�y�z(item_desc/item)   �Ҧp: item_desc/table  item_desc/ball

 C. �]�w�ж����ݩ�,�e�� �� ���ж����]�w���ݩ�, �A��@���i�H����
     1. [  ]  �T��I�k(no_magic)
     2. [  ]  �T��԰�(no_fight)
     3. [  ]  �T��ѯ��ǰe(no_recall)
     4. [  ]  �O��(�Ǥ��~����)(light_up)
     5. [��]  �x�s�I(valid_startroom)

 D. �p�G���]�w���~, �u�n�A���]�w�@���N�i, �Ϊ̥����n save ,
    update here�Y�i��_���[

 F. �o�{ bug �гq����..     
 
 G. ��ĳsave����A�ϥ�edit �s�@���o�өж�,�p:
    edit here  <--�s��o�өж�.
    :x          <-�M���x �s�ɥX��.
    
    �o�ˤl�����ηN�O..
    ���]�ڭ̼g�F�@��:
    set("item_desc", ([ /* sizeof() == 1 */
    "test" : "�Ĥ@��\n �ĤG��\n",
    ])); 
    �M���look test�ɥX�{���O:
    �Ĥ@��\n�ĤG��\n 
    
    �i�O�p�G�ϥιLedit �s�ɪ���, �A��look test�N�ܦ�:
    �Ĥ@��
    �ĤG��
            
    �N�ܦ��z�Q�n���ԭz�F...:)    
 
 G. �o�O�@�ӥΨӡu�ֳt�v�s�y�ж����u��M���U�ɶ����h�Φ��Y��  lag ���Ův  
    �Q�νu�W��J�s�y²�檺�ж��M���L�p�G�z�Q�����ۤv�ϰ�ж����~��M�̦n
    ���n�Ө̿�o�ӪF��.
   
 H. �o�� roommaker�w�g�Q Lsr�ק�L�@�p�����F ...
    ��v1.1�������O�]�[�i��, ��K�ߺD��v1.1�����H.
    �ק�F�@�Ǧr, �è̤p�ت��ݭn�ӲK�[�F�@�Ǧa��. 
    �]�N�O��, �z�A�ϥΥH�e, �Х��̱z���ݭn���ǭק��A�ϥ�.

NOTE; 
	if(arg == "roommaker" || arg == "maker" ){
		ob->start_more(str);
		return 1;
		}
	else
	if(arg == "note"){
		ob->start_more(note);
		return 1;
		}
	else 	return notify_fail("�A�Q�\\Ū����H\n");
	return 1;
}