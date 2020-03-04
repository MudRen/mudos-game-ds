// token.c

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
	set_name("��S�H��", ({ "token" }) );
	set("unit", "��");
	set("leader_title", "�x���H");
	seteuid(getuid());
}

string short()
{
	string guild;

	if( stringp(query("short")) || !stringp(guild = query("guild_name")) )
		return ::short();
	else
		return guild + ::short();
}

string long()
{
	if( stringp(query("long")) )
		return ::long();
	else if ( stringp(query("guild_id"))) return @TEXT
�o�O�@�Ӥw�g�Ѷ}�ʦL����S�H���M�A�i�H�ΥH�U���O�ӳгy�ݩ�A�ۤv������
�����|��´�R

    modify <����> <�r��>    �ק�H�����~�[�B�����W�ٵ���
    assign                  �N��´��S����m�ǵ��O�H
    dismiss                 �ä[�Ѵ��o�Ӳ�´
    
TEXT
	;
	else return @TEXT
�o�O�@�ӥΨ������a�إߪ����B���|�ɩҥΪ���S�H���M�����o�����~���H�N�O
�o�Ӳ�´����S(�x���H)�M��S�㦳�۶ҷs�����B�}���즳�����B�H�Χ�令��
�ٸ����v�O�M�o���H���|�۰��x�s�M�b�إߤ@�Ӫ������e���������@�W�Ův�Ѱ�
�H���۪��ʦL(unseal)�C
TEXT
	;
}

void init()
{
	if( !environment()->is_character() ) {
		message_vision("$N�o�X�@�}ģ�������~�M�M������F�C\n", this_object());
		destruct(this_object());
	} else {
		add_action("do_unseal", "unseal");
		add_action("do_assign", "assign");
		add_action("do_modify", "modify");
		add_action("do_dismiss", "dismiss");
	}
}

string query_autoload() { return query("guild_id"); }

string query_save_file() { return DATA_DIR + "guild/" + query("guild_id"); }

void autoload(string name)
{
	if( !restore() ) {
		if( environment() ) environment()->delete("family");
		destruct(this_object());
	}
}

int do_unseal(string arg)
{
	int i;
	string guild_id, guild_name;

	if( query("guild_id") )
		return notify_fail( query("name") + "���ʦL�w�g�Q�Ѷ}�F�C\n");

	if( !wizardp(this_player(1)) )
		return notify_fail(
			"�u���Ův��Ѱ���S�H�����ʦL�M�p�G�A�n�Хߤ@�ӷs�����������|�M��\n"
			"����@��Ův����O�H�M�ХL(�o)���A�Ѱ��ʦL�C\n");

	if(!arg) 
		return notify_fail("���O�榡�Runseal <�����N��> <�����W��>\n");

	if( sscanf(arg, "%s %s", guild_id, guild_name)!= 2 ) {
		set("guild_id", arg);
		if( restore() ) {
			write("Ok.\n");
			return 1;
		} else {
			delete("guild_id");
			return notify_fail("�S���o�Ӫ����C\n");
		}
	}

	for(i=0; i<strlen(guild_id); i++)
		if( guild_id[i] < 'a' || guild_id[i] > 'z' )
			return notify_fail("<�����N��>�����Ѥp�g�^��r���զ��C\n");

	set("guild_id", guild_id);
	set("guild_name", guild_name);

	if(file_size(query_save_file() + __SAVE_EXTENSION__)>=0	)
		restore();
	else {
		log_file("UNSEAL", sprintf("%s [%s] by %s, %s\n",
			guild_name, guild_id, this_player(1)->query("id"), ctime(time()) ));
	}

	write("Ok.\n");
	return 1;
}

int do_assign(string arg)
{
	object ob;
	mapping family;
	string assign_msg;

	if( !arg || !objectp(ob = present(arg, environment(this_player())))
	|| !living(ob) ) 
		return notify_fail("�A�n�N�x���H����ǵ��֡S\n");

	family = this_player(1)->query("family");

	if( wizardp(this_player(1)) || (
		mapp(family) && family["family_name"]==(string)query("guild_name")
		&& (string)this_player(1)->query("id")==(string)query("leader"))	) {
		// If this is a new guild, create its family.
		if( !query("leader") )
			ob->create_family(query("guild_name"));
		else {
			family = ob->query("family");
			if( !mapp(family) || (family["family_name"]!=(string)query("guild_name")) )
				return notify_fail( ob->query("name") + "�ä��O" + query("guild_name") + "���@���l�C\n");
		}
		ob->assign_apprentice( query("leader_title"), -1 );
		set("leader", ob->query("id"));
		if( stringp(assign_msg = query("assign_msg")) )
			message_vision( assign_msg, this_player(1), ob);
		else
			message_vision(
				"\n$N�N" + query("guild_name") + "��" + query("name") + "�浹�F$n�C\n"
				"\n����$p�N�O" + query("guild_name") + "���x���H�F�C\n\n", this_player(1), ob);
		move(ob);
		write("Ok.\n");
		return 1;
	} else
		return notify_fail("�A�S���o���v�O�C\n");
}

int do_modify(string arg)
{
	string prop, str;

	if( !query("guild_id") ) return 0;
	
	if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
		return notify_fail("���O�榡�Rmodify <����> <�T��>\n");
	switch(prop) {
		case "name":
		case "long":
		case "short":
		case "assign_msg":
		case "leader_title":
			set(prop, str);
			save();
			write("Ok.\n");
			break;
		default:
			write("�A��ק諸���إu���Rname, short, long, assign_msg, leader_title�C\n");
	}
	return 1;
}

int do_dismiss(string arg)
{
	if( !query("guild_id") ) return 0;

	rm(query_save_file() + __SAVE_EXTENSION__);
	write( query("guild_name") + "�Q�Ѵ��F�C\n");
	destruct(this_object());
	return 1;
}
