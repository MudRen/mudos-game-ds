#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIY"�d�H���P�E�Z"NOR, ({ "armor of millennium star","armor" }) );
	set_weight(12500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���Z�ҫD�`����, �ݰ_�Ӫ����{�{, �o�����D�O�Φ��\n"
                           "�S������Һc��, �X�G�L�k�R������T��, �i�H������\n"
			   "�̬۷�j�j�����@�O, �ڻ��o���Z�ҬO�C�줤�Y�@�����K\n"
                           "�K���F�y���d�H�ӯS�a���y��!\n"
                           "���ܭ^��W: re_eng_name, ���ܤ���W: rename\n"
                           "ps.���s�i�J�C���� name �N�|���ܤF.\n");
		set("unit","��");
	set("value",1);
		set("material","diamond");
		set("needaward",50);
	}
	set("no_give",1);
	set("no_drop",1);
        set("armor_prop/con",2);
	set("armor_prop/int",1);
	set("armor_prop/str",2);
	set("armor_prop/shield",25);
	set("armor_prop/armor",45);
	setup();
}

int query_autoload() { return 1; }

void init()
{
 add_action("do_re_eng_name","re_eng_name");
 add_action("do_rename","rename");
 if( environment(this_object()) == this_player() )
 {
  if( this_player()->query("millennium_armor/cname") ) 
   this_object()->set("name",this_player()->query("millennium_armor/cname") );
  if( this_player()->query("millennium_armor/id") && this_player()->query("millennium_armor/full_id") )
   this_object()->set_name(HIY"�d�H���P�E�Z"NOR,({ this_player()->query("millennium_armor/full_id") , 
			                           this_player()->query("millennium_armor/id") }) );
  if( this_player()->query("millennium_armor/cname") && 
      this_player()->query("millennium_armor/id") && 
      this_player()->query("millennium_armor/full_id") )
   this_object()->set_name( this_player()->query("millennium_armor/cname") , ({ 
                            this_player()->query("millennium_armor/full_id") , 
          		    this_player()->query("millennium_armor/id") }) );
 }
}

int do_re_eng_name(string arg)
{
	string n_who,id,name;
	object me;
	me = this_player();
	if(!arg || sscanf(arg,"%s as %s %s",n_who,name,id )!=3 )
		return notify_fail("��W�榡: re_eng_name <���~> as <�^����W> <�^��²��>.\n");
	if( !present(n_who,me) )
		return notify_fail("�A���W�S���o�ӪF��. \n");
	if( strlen(id) > 10 || strlen(name) > 20 )
		return notify_fail("�Ч�W�r���o�u�@�I, �T�G�@�I.\n");
	message_vision("$N��$n���^��W�r�אּ�i"+name+NOR+"("+id+")�j\n",me,this_object());
	me->set("millennium_armor/id",id);
	me->set("millennium_armor/full_id",name);
	return 1;
}

int do_rename(string arg)
{
        string n_who,cname,oldname;
	object me;
	me = this_player();
	oldname = this_object()->query("name");
	if(!arg || sscanf(arg,"%s as %s",n_who,cname)!=2 )
		return notify_fail("��W�榡: rename <���~> as <����W��>.\n");
	if( !present(n_who,me) )
		return notify_fail("�A���W�S���o�ӪF��. \n");
	if( strlen(cname) > 24 )
		return notify_fail("�Ч�W�r���o�u�@�I, �T�q�@�I.\n");
	arg = replace_string(arg, "$BLK$", BLK);
	cname = replace_string(cname, "$RED$", RED);
	cname = replace_string(cname, "$GRN$", GRN);
	cname = replace_string(cname, "$YEL$", YEL);
	cname = replace_string(cname, "$BLU$", BLU);
	cname = replace_string(cname, "$MAG$", MAG);
	cname = replace_string(cname, "$CYN$", CYN);
	cname = replace_string(cname, "$WHT$", WHT);
	cname = replace_string(cname, "$HIR$", HIR);
	cname = replace_string(cname, "$HIG$", HIG);
	cname = replace_string(cname, "$HIY$", HIY);
	cname = replace_string(cname, "$HIB$", HIB);
	cname = replace_string(cname, "$HIM$", HIM);
	cname = replace_string(cname, "$HIC$", HIC);
	cname = replace_string(cname, "$HIW$", HIW);
	cname = replace_string(cname, "$NOR$", NOR);
	message_vision(HIC"$N"NOR" �j�n�ŧG�D: �ڴN�b���N�ڪ� "+oldname+NOR+" ��W�� "+cname+NOR+" �a�I\n",me);
        message_vision("$N��"+oldname+NOR+"������W�r�אּ�i"+cname+NOR+"�j\n",me);
        me->set("millennium_armor/cname",cname);
	return 1;
}
