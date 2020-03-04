// eq,wp �۰ʲ��;� by -Acme-
#include <ansi.h>
#define GIFT_DIR "/open/always/game_gift/"

inherit ITEM;

string *eqs = ({ "MASK","NECK","CLOTH","ARMOR","SURCOAT","WAIST","WRISTS","HEAD",
		"SHIELD","FINGER","HANDS","LEGGING","PANTS","BOOTS" });
string *wps = ({ "AXE","BLADE","DAGGER","FORK","HAMMER","SWORD",
                "STAFF","WHIP","BOW","FIST" });
string *wpx = ({ "axe","blade","dagger","fork","hammer","sword",
                "staff","whip","bow","fist" });
string *units = ({ "��","��","��","��","��","��","��","��","��","�u","��","��","��","��" });
string *attr = ({ "str","con","int","dex" } );
//string *attr = ({ "str","cor","int","wis","cps","dex","con","spi" });


//�Z(ARMOR)50 ��(SHIELD)30 ��(CLOTH)30 ��(HEAD)20 ��(SURCOAT)20 �u(BOOTS)15 ��M(GLOVES)10 
//�y(WAIST)8 ��(FINGER)5 ��(NECK)5 ���(WRISTS)10 �@��(HANDS)10 �j�L(LEGGING)10 �Ǥl(PANTS)15

int do_help(string arg);
int do_set_name(string arg);
int do_set_id(string arg);
int do_set_long(string arg);
int do_set_kind(string arg);
int do_check();
int do_change();
int do_create(string arg);

void init()
{
	add_action("do_help","help");
	add_action("do_set_name","set_name");
	add_action("do_set_id","set_id");
	add_action("do_set_long","set_long");
	add_action("do_set_kind","set_kind");
        add_action("do_check","review");
	add_action("do_change","change");
	add_action("do_create","create");
}

int do_set_name(string arg)
{
	string check;
	if( !arg ) return notify_fail("�A�n�]�w������W�r�H\n");

        check = replace_string(arg, "$BLK$", "");
        check = replace_string(check, "$RED$", "");
        check = replace_string(check, "$GRN$", "");
        check = replace_string(check, "$YEL$", "");
        check = replace_string(check, "$BLU$", "");
        check = replace_string(check, "$MAG$", "");
        check = replace_string(check, "$CYN$", "");
        check = replace_string(check, "$WHT$", "");
        check = replace_string(check, "$HIR$", "");
        check = replace_string(check, "$HIG$", "");
        check = replace_string(check, "$HIY$", "");
        check = replace_string(check, "$HIB$", "");
        check = replace_string(check, "$HIM$", "");
        check = replace_string(check, "$HIC$", "");
        check = replace_string(check, "$HIW$", "");
        check = replace_string(check, "$NOR$", "");

	if( strlen(check) > 20 ) return notify_fail("�A�ҳ]�w���W�r�Ӫ��F(���o�j��20�Ӧr��)�C\n");

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

	write("�A�N���~�W�ٳ]�w��["+arg+NOR"]�C\n");
	set("ob_name",arg+NOR);
	return 1;
}

int do_set_id(string arg)
{
	string id1,id2;
	if( !arg ) return notify_fail("�A�n�]�w������^��W�r�H\n");

	if( sscanf(arg,"%s,%s",id1,id2) ==2 )
	{
		if( strlen(id1) > 20 || strlen(id2) > 20 ) 
			return notify_fail("�A�ҳ]�w���^��W�r�Ӫ��F(���o�j��20�Ӧr��)�C\n");
		set("ob_id1",id1);
		set("ob_id2",id2);
	}
	else
	{
		if( strlen(arg) > 20 ) 
			return notify_fail("�A�ҳ]�w���^��W�r�Ӫ��F(���o�j��20�Ӧr��)�C\n");
		set("ob_id1",arg);
		if( query("ob_id2") ) delete("ob_id2");
	}
	write("�A�N���~�^��W�ٳ]�w��["+arg+"]�C\n");
	return 1;
}
int do_set_long(string arg)
{
	if( strlen(arg) > 200 ) return notify_fail("�A�]�w���ԭz�Ӫ��F�C\n");
	set("ob_long",arg);
	write("�A�N���~�ԭz�]�w���G\n"+arg+"\n");
	return 1;
}

int do_set_kind(string arg)
{
	int i=0,check=0;
	string type,kind;
	if( !arg ) return notify_fail("���O�榡�G set_kind <����> <����>\n");

	i=sizeof(eqs);
	while( i-- )
		if( eqs[i] == arg )
		{
			set("ob_unit",units[i]);
			check=1;
		}
		set("ob_type","armor.h");

	if( !check)
	{
		i=sizeof(wps);
		while( i-- )
		if( wps[i] == arg )
		{
			set("ob_kinds", wpx[i]);
			check=1;
		}
		set("ob_type","weapon.h");
		set("ob_unit","��");
	}

	if( !check ) return notify_fail("�A�]�w�����������~�C\n");
	set("ob_kind",arg);
	delete("make");
	write("�A�N���~�]��["+arg+"]�C\n");
	return 1;
}

int do_check()
{
	int *va,i;
	string msg,str="",sc="",*prop;

	msg = "�� ���~�]�w���A ��\n\n";

	msg += " [�W��] ";
	msg += query("ob_name") ? query("ob_name") : "���]�w";
	msg += query("ob_id1") ? "("+query("ob_id1") : "(none";
	msg += query("ob_id2") ? ","+query("ob_id2")+")\n" : ")\n";

	msg += " [����] ";
	if( query("ob_type") && query("ob_kind") )
	{
		msg+=query("ob_kind")+"\n";
		switch( query("ob_type") )
		{
			case "armor.h": 
				if( query("make/armor_prop") )
				{
					prop=keys(query("make/armor_prop"));
					va=values(query("make/armor_prop"));
					i=sizeof(prop);
					while( i-- )
					{
						switch( prop[i] )
						{
						case "armor":
							str += " [���m] ";
							str += (string)va[i]+"\n";
							break;
						case "shield":
							str += " [�]��] ";
							str += (string)va[i]+"\n";
							break;
						default:
							sc += prop[i]+":";
							sc += (string)va[i]+" ";
							break;
						}
					}
				}
				break;
			case "weapon.h": 
				msg += " [���] ";
				msg += query("ob_attack")+"\n";
				if( query("make/weapon_prop") )
				{
					prop=keys(query("make/weapon_prop"));
					va=values(query("make/weapon_prop"));
					i=sizeof(prop);
					while( i-- )
					{
						switch( prop[i] )
						{
						case "hit":
							str += " [�R��] ";
							str += (string)va[i]+"\n";
							break;
						default:
							sc += prop[i]+":";
							sc += (string)va[i]+" ";
							break;
						}
					}
				}
				break;
			default : msg += query("ob_type")+"\n"; break;
		}
	}
	else msg +="���]�w\n";

	msg += " [���q] ";
	msg += query("ob_weight") ? query("ob_weight") +"\n" : "���]�w\n";
	msg += " [����] ";
	msg += query("ob_value") ? query("ob_value") +"\n" : "���]�w\n";
	if( str ) msg += str;
	if( sc )
	{
		msg += " [���[] ";
		msg += sc;
	}
	this_player()->start_more(msg);
	return 1;
}

int do_change()
{
	int level;
	if( !query("ob_name") ) 
		return notify_fail("���ݦ��]�w�W�١I\n");
	if( !query("ob_id1") )
		return notify_fail("���ݦ��]�w�^��W�١I\n");

	if( !query("ob_type") || !query("ob_kind") )
		return notify_fail("���ݦ��]�w�����I\n");
        if( this_player()->query("mp") < 20 )
		return notify_fail("�k�O�����A�L�k�I��C\n");
        this_player()->receive_damage("mp", 20 );
	if( !query("level") ) level=1;
	else level=query("level");
	
	delete("make");

	set("ob_weight",level*1000+random(level*1000));
 	set("ob_value",level*1000+random(level*1000));

	switch( query("ob_type") )
	{
		case "armor.h":
			switch( query("ob_kind") )
			{
				case "ARMOR": 
					set("make/armor_prop/armor", random(level*10)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*10)+1);
					else set("make/armor_prop/shield",random(level*10)+1);
					break;
				case "SHIELD": 
					set("make/armor_prop/armor", random(level*6)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*6)+1);
					else set("make/armor_prop/shield",random(level*6)+1);
					break;
				case "CLOTH": 
					set("make/armor_prop/armor", random(level*6)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*6)+1);
					else set("make/armor_prop/shield",random(level*6)+1);
					break;
				case "HEAD": 
					set("make/armor_prop/armor", random(level*4)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*4)+1);
					else set("make/armor_prop/shield",random(level*4)+1);
					break;
				case "SURCOAT": 
					set("make/armor_prop/armor", random(level*4)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*4)+1);
					else set("make/armor_prop/shield",random(level*4)+1);
					break;
				case "BOOTS": 
					set("make/armor_prop/armor", random(level*3)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*3)+1);
					else set("make/armor_prop/shield",random(level*3)+1);
					break;
				case "GLOVES": 
					set("make/armor_prop/armor", random(level*2)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*2)+1);
					else set("make/armor_prop/shield",random(level*2)+1);
					break;
				case "WAIST": 
					set("make/armor_prop/armor", random(level+3)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level+3)+1);
					else set("make/armor_prop/shield",random(level*3)+1);
					break;
				case "FINGER": 
					set("make/armor_prop/armor", random(level)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level)+1);
					else set("make/armor_prop/shield",random(level)+1);
					break;
				case "NECK": 
					break;
					set("make/armor_prop/armor", random(level)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level)+1);
					else set("make/armor_prop/shield",random(level)+1);
				case "WRISTS": 
					set("make/armor_prop/armor", random(level*2)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*2)+1);
					else set("make/armor_prop/shield",random(level*2)+1);
					break;
				case "HANDS": 
					set("make/armor_prop/armor", random(level*2)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*2)+1);
					else set("make/armor_prop/shield",random(level*2)+1);
					break;
				case "LEGGING": 
					set("make/armor_prop/armor", random(level*2)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*2)+1);
					else set("make/armor_prop/shield",random(level*2)+1);
					break;
				case "PANTS": 
					set("make/armor_prop/armor", random(level*3)+1);
					if( random(level*2) > random(query("armor_prop/armor")) )
					set("make/armor_prop/shield",random(level*3)+1);
					else set("make/armor_prop/shield",random(level*3)+1);
					break;
			}

			if( random(level*10) > random(100) )
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*8) > random(100) && level>1 )
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*6) > random(100) && level>2)
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*4) > random(100) && level>3 )
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*2) > random(100) && level>4)
				add("make/armor_prop/"+attr[random(sizeof(attr))],1);
			break;

		case "weapon.h":
			set("ob_attack", random(level*15)+1);

			if( random(level*10) > random(100) )
				set("make/weapon_prop/hit",random(level*6)+1);
			else set("make/weapon_prop/hit",level);

			if( random(level*10) > random(100) )
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*8) > random(100) && level>1)
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*6) > random(100) && level>2 )
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*4) > random(100) && level>3 )
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
                        if( random(level*2) > random(100) && level>4)
				add("make/weapon_prop/"+attr[random(sizeof(attr))],1);
			break;
		default : 
			return notify_fail("�o�Ӻ����L�k�ϥγo�ӫ��O�C\n");
			break;
	}
	write("�A�Τ�b"+query("name")+"�W�٤F�X�U�A���G�_�F�����ܤơC\n");
	return 1;
}

int do_create(string arg)
{
	int i,*va;
	string str,*sc;
        object gift;

	if( wiz_level(this_player()) < wiz_level("(arch)") )
		return notify_fail("�A�S��k�γo�ӫ��O�I\n");
	
	if( !arg ) return notify_fail("���ݫ��w�ɦW�C\n");

        if( file_size( (GIFT_DIR+arg) ) == -2 )
		return notify_fail("�o���ɦW�w�g�s�b�F�@�I\n");

	if( !query("ob_name") ) 
		return notify_fail("���ݳ]�w�W�١I\n");
	if( !query("ob_id1") )
		return notify_fail("���ݳ]�w�^��W�١I\n");
        if( !query("ob_type") || !query("ob_kind") )
		return notify_fail("���ݳ]�w�����I\n");
	if( !query("ob_weight") )
		return notify_fail("���ݳ]�w���q�I\n");
	if( !query("ob_unit") )
		return notify_fail("���ݳ]�w���I\n");

	str = "//�� /std/item/game_gift.c �гy by -Acme-\n\n";
	
	str+= "#include <"+query("ob_type")+">\n";
	str+= "#include <ansi.h>\n";
	str+= "inherit "+query("ob_kind")+";\n\n";
	str+= "void create()\n{\n";

	str+=sprintf("\tset_name( \"%s\", ({ \"%s\" }) );\n",
		query("ob_name"),
		query("ob_id1") + (query("ob_id2") ? "\",\""+query("ob_id2") : "") );

	str+="\tset_weight("+query("ob_weight")+");\n";
	str+="\tif( clonep() )\n";
        str+="\t\tset_default_object(__FILE__);\n";
	str+="\telse {\n";
	str+=sprintf("\t\tset(\"long\",\"%s\");\n", query("ob_long") ? query("ob_long") : "�L" );
	str+=sprintf("\t\tset(\"unit\", \"%s\");\n",query("ob_unit"));
	str+=sprintf("\t\tset(\"value\",%d);\n\t}\n",query("ob_value"));

	if( query("make/armor_prop") )
	{
		sc=keys( query("make/armor_prop") );
		va=values( query("make/armor_prop") );
		i=sizeof(sc);
		while( i-- )
                        str+=sprintf("\tset(\"armor_prop/%s\", %d);\n",sc[i],va[i]);
	}

	if( query("make/weapon_prop") )
	{
		sc=keys( query("make/weapon_prop") );
		va=values( query("make/weapon_prop") );
		i=sizeof(sc);
		while( i-- )
			str+=sprintf("\tset(\"weaopn_prop/%s\", %d );\n",sc[i],va[i]);
		str+="\tinit_"+query("ob_kinds")+"("+query("ob_attack")+");\n";
	}

	str+="\tsetup();\n}\n";
	str+="int query_autoload() { return 1; }\n";

	if( write_file(GIFT_DIR+arg+".c",str) )
        {
                log_file( "game_gift" , getuid(this_player())+" �гy "+query("ob_name")+"("+GIFT_DIR+arg+")��["+ctime(time())+"]�C\n");
                gift=new(GIFT_DIR+arg);
                if( objectp(gift) ) gift->move(this_player());
		write("�g�J�ɮ�["+GIFT_DIR+arg+".c]���\\�I\n");
                message_vision("$N�f�̰�D�G���F�a�F�B�^�����F�K"+query("ob_name")+"�C\n",this_player());
                destruct(this_object());
        }
	else return notify_fail("�g�J�ɮ�["+GIFT_DIR+arg+".c]���ѡI\n");
	return 1;
}

int query_autoload() { return 1; }

int do_help(string arg)
{
	if( arg != "gift" ) return 0;
write(@HELP
  ���O�榡�G
	�@�B�]�w�G
            1. set_name <�W��>  �]�w���~����W�١C(�i�Φ�X)
            2. set_id <�W��>    �]�w���~�^��W�١C ex: set_id acme's blade,blade
                                �h������|�� acme's blade ��blade �G�ӭ^��W
	    3. set_long <�ԭz>	�]�w���~�ԭz�C
	    4. set_kind <����> 	�]�w���~�����A�����й�ӤU�軡���C
	�G�B�ܧ�B�˵�
            1. change           �ܧ󪫫~�]�w�C(�N���ܧ���[�]�w)
            2. review           �ˬd���~���]�w�C
	�T�B�гy
	    1. create <�ɦW>	�Ův���O�A���~�]�w�n�ɡA�Ч�u�W�j�Ův�šC
				�H�W�гy�����~�C

  �� �Z�� ��
	AXE(���Y)	BLADE(�M�l)	DAGGER(�P��)	FORK(���j)	HAMMER(��l)
	SWORD(�C)	STAFF(��)	WHIP(�@)	BOW(�})		FIST(���M)
  �� ���� ��
	ARMOR(�Z��)	SHIELD(�޵P)	CLOTH(��A)	HEAD(�Y��)	SURCOAT(�ܭ�) 
        BOOTS(�u�l)     MASK(����)      WAIST(�y�a)     FINGER(����)    NECK(����)
	WRISTS(�@��)	HANDS(�@��)	LEGGING(�j�L)	PANTS(�Ǥl)
  �� �S�\ �� (���}��)
	�@�B�������G 1.���� 2.�s�� 3.�x����
	�G�B�o�����G 1.����
	�T�B��_���G 1.���O 2.�]�O 3.���O
HELP);
	return 1;
}
