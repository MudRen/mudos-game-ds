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
	set_name("NPC編輯器" + RMK_VERSION, ({ "npcmaker", "maker" }) );
	set_weight(100);
	set("unit", "個" );
	set("long", @LONG
這是一個用來「快速」製造NPC的工具﹐幫助時間不多或有嚴重  lag 的巫師
利用線上輸入製造簡單的房間﹐不過如果你想提高自己區域NPC的品質﹐最好
不要太依賴這個東西﹐你可以使用以下幾個指令﹕

mknpc    造出一個新的NPC.

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
	set_name( "ＮＰＣ", ({ "npc" }));
	set("long", "這是一個標準的NPC。\n");
	set("age", 1);
	set("level",1);
	set("race", "人類");
	setup();
}
NPC_CODE
	) ) return notify_fail("你沒有寫入檔案(" + file +")的權利。\n");
	message_vision("只聽到$N的NPC編輯器「嗶」的一聲﹐你覺得這個世界的怪物又變多了一點。\n", this_player());
        npc=new(file);
        npc->move(environment(this_player()));
        write("\nNPC的英文名字﹕");
	input_to("get_id", npc);
	return 1;
}
void get_id(string arg, object obj)
{
 	if( arg=="" )
 	{
		write("NPC的英文名字﹕");
		input_to("get_id", obj);
		return;
	}
	
	if( !check_legal_id(arg))
	{
		write("NPC的英文名字﹕");
		input_to("get_id", obj);
		return;
	}
	obj->set("id",arg);
        write("NPC的中文名字﹕");
	input_to("get_name", obj);
}
void get_name(string arg, object obj)
{
 	if( arg=="" )
 	{
		write("NPC的中文名字﹕");
		input_to("get_name", obj);
		return;
	}
	
	if( !check_legal_name(arg))
	{
		write("NPC的中文名字﹕");
		input_to("get_name", obj);
		return;
	}
	obj->set("name",arg);
        write("NPC的敘述﹕");

	input_to("get_long", obj);
}

void get_long(string arg, object obj)
{
 	if( arg=="" )
 	{
		write("NPC的敘述﹕");
		input_to("get_long", obj);
		return;
	}
	
	obj->set("long",arg);
        write("NPC的種族﹕(1)人類  (2)野獸:");
	input_to("get_race", obj);
}

void get_race(string arg, object obj)
{

 	if( arg=="1" )
 	{
		write("NPC的種族﹕人類 \nNPC的年齡﹕");
		obj->set("race","人類");
		input_to("get_age", obj);
		return;
	} else
 	if( arg=="2" )
 	{
		write("NPC的種族﹕野獸 \n野獸開發中 \n");
		return;
	} else
	{
        write("NPC的種族﹕(1)人類  (2)野獸:");
	input_to("get_race", obj);
        }
 return ;
}

void get_age(string arg, object obj)
{
 int age;

 	if(sscanf(arg,"%d",age)!=1)
 	{
		write("NPC的年齡﹕");
		input_to("get_age", obj);
		return;
	}	

	obj->set("age",age);
        write("\nNPC的等級﹕");
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
		write("NPC的等級﹕");
		input_to("get_level", obj);
		return 1;
	}
	

 
	obj->set("level",level);
	write("存在檔案 " + file + "?[y/n]");
	
	
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
//		write("存在檔案 " + file + " 嗎﹖[y/n]");
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
	write("存檔 " + file + "....");
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
		return notify_fail("你沒有寫入這個檔案(" + file + ")的權利。\n");
}

void owner_is_killed() { destruct(this_object()); }

int check_legal_id(string id)
{
	int i;

	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
		write("對不起﹐英文名字必須是 3 到 12 個英文字母。\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("對不起﹐英文名字只能用英文字母。\n");
			return 0;
		}
	return 1;
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	
	if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
		write("對不起﹐中文名字必須是 1 到 6 個中文字。\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("對不起﹐中文名字不能用控制字元。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("對不起﹐請您用「中文」取名字。\n");
			return 0;
		}
	}

	return 1;
}
