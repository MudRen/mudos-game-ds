#define RMK_VERSION "(v1.1)"

inherit ITEM;
inherit F_AUTOLOAD;

string *special_props = ({
	"short", "long" });

int save_room_file(string yn, string file, string str);

void create()
{
	set_name("�ж��s�边" + RMK_VERSION, ({ "roommaker", "maker" }) );
	set_weight(100);
	set("unit", "��" );
	set("long", @LONG
�o�O�@�ӥΨӡu�ֳt�v�s�y�ж����u��M���U�ɶ����h�Φ��Y��  lag ���Ův
�Q�νu�W��J�s�y²�檺�ж��M���L�p�G�A�Q�����ۤv�ϰ�ж����~��M�̦n
���n�Ө̿�o�ӪF��M�A�i�H�ϥΥH�U�X�ӫ��O�R

mkroom <�ж��ɦW>

    �y�X�@�ӡu�šv�ж��M����A�i�H goto ��o�өж��� rset �]�w�ж���
    �ԭz���ݩʡC

rset <�ж��ݩ�> <�ݩʤ��e>

    �]�w�A�ثe�Ҧb�ж����ݩʡM�p short�Mlong ���C

connect <��V> <�ж��ɦW>

    �N�A�ثe�Ҧb���ж��s���@�ӥX�f��t�@�өж��C

saveroom

    �N�A�ثe�Ҧb���ж��s�ɡC
LONG
	);
}

int query_autoload() { return 1; }

void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("do_mkroom", "mkroom");
		add_action("do_rset", "rset");
		add_action("do_connect", "connect");
		add_action("do_saveroom", "saveroom");
	}
}

int do_mkroom(string arg)
{
	string file, dir, code;

	if( !arg ) return notify_fail("���O�榡�Rmkroom <�ж��ɦW> [<��V>]\n");
	if( sscanf(arg, "%s %s", file, dir)!=2 )
		file = arg;
	seteuid(geteuid(this_player()));
	file = resolve_path(this_player()->query("cwd"), file) + ".c";
	if( file_size(file)!=-1 )
		return notify_fail("�ɮ� " + file + " �w�g�s�b�F�C\n");
	if( !write_file(file, @ROOM_CODE
// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	setup();
	replace_program(ROOM);
}
ROOM_CODE
	) ) return notify_fail("�A�S���g�J�ɮ�(" + file +")���v�Q�C\n");
	message_vision("�uť��$N���ж��s�边�u�͡v���@�n�M�Aı�o�o�ӥ@�ɤS�ܤj�F�@�I�C\n", this_player());
	return 1;
}

int do_rset(string arg)
{
	string prop, str;
	mixed data;

	if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
		return notify_fail("���O�榡�Rrset <�ж��ݩ�> <�ݩʤ��e>\n");

	if( sscanf(str, "%d", data)!=1 )
		data = str;

	environment(this_player())->set(prop, str);
	write("Ok.\n");
	return 1;
}

int do_connect(string arg)
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
	write("Ok.\n");
	return 1;
}

int do_saveroom(string arg)
{
	object env;
	string str, *name, file;
	mapping prop;
	int i;

	env = environment(this_player());
	file = file_name(env) + ".c";
	str = "// Room: " + file + @ROOM_CODE


inherit ROOM;

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
	str += "\n\tsetup();\n\treplace_program(ROOM);\n}\n";

	// Replace current directory with __DIR__ macro to make relocatable code.
	i = strlen(file)-1;
	while( (i > 0) && (file[i]!='/')) i--;
	if( i>0 ) {
		write("�ثe�ؿ��R" + file[0..i] + " �H __DIR__ ���N�C\n");
		str = replace_string(str, "\"" + file[0..i], "__DIR__\"");
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
	write("�s�� " + file + "....");
	if( write_file(file, str) ) {
		write("Ok.\n");
		return 1;
	} else
		return notify_fail("�A�S���g�J�o���ɮ�(" + file + ")���v�Q�C\n");
}

void owner_is_killed() { destruct(this_object()); }
