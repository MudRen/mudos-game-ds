#include <ansi.h>
#define LUKY		"/u/l/luky/"
//inherit F_CLEAN_UP;
inherit ITEM;
void create()
{
	object ob, obj;
	seteuid(getuid());
	set_name(HIM"�s�c�_��"NOR,({"box"}));
        if( clonep() )
        set("unit", "��");
        set("long",HIG"�@�ӥj�Ѫ����l�C"NOR"�o�O�j�s���q���s�����c���̰��Ӫ��C\n"
	"�A�i�H�X�e���`�N���ɭ԰����e���_����..(get [�F��] from box)\n");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set_max_encumbrance(999999);
obj = this_object();
ob=new("/u/l/luky/npc/eq/blackjacket");
ob->move(obj);
ob=new("/u/l/luky/npc/wp/kaisan_b");
ob->move(obj);
ob=new("/u/l/luky/npc/item/bag");
ob->move(obj);
ob=new("/u/l/luky/obj/fighterneck");
ob->move(obj);

setup();
}

void init()
{
add_action("do_shakebox","shakebox");
}

int do_shakebox(string arg)
{
object box,ob,me;
string str,file;
me=this_player();
box=this_object();
if( wiz_level(me) < 5) return notify_fail("��M��, �_���R�X�@�����ɧ���A����l...\n");
if(!arg) return notify_fail("�n�n����F��X��?\n");
arg+=".c";
if( file_size(arg) < 0 ) return notify_fail("�S�o�ӪF��\n");
ob=new(arg);
ob->move(box);

  file = "/u/l/luky/box.log";
  str = sprintf("[%s] shake %s(%s)on %s\n",geteuid(me),ob->query("name"),arg,ctime(time()));
  if(file_size(file) < 0) write_file(file, str);
  else if(strsrch(read_file(file), sprintf("[%s] shake %s(%s)on %s\n",geteuid(me),ob->query("name"),arg,ctime(time())))  == -1)
  write_file(file, str);

tell_object(this_player(),"�A�n�F�n�_��...���l�̬�M�h�X�@��"+ob->query("name")+"��!\n");
return 1;
}

