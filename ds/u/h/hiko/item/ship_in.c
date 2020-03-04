//���� �c�Q�ӷ�:UW�����@�� , �[�j�� By Dontpkme
// alickyuen@ds fix bug :p
#include <ansi.h>

inherit ROOM;

void welcome(object ob);

mapping default_dirs = ([
        "north":                "�_",
        "south":                "�n",
        "east":                 "�F",
        "west":                 "��",
        "northup":              "�_��",
        "southup":              "�n��",
        "eastup":               "�F��",
        "westup":               "����",
        "northdown":            "�_��",
        "southdown":            "�n��",
        "eastdown":             "�F��",
        "westdown":             "����",
        "northeast":            "�F�_",
        "northwest":            "��_",
        "southeast":            "�F�n",
        "southwest":            "��n",
        "up":                   "�W��",
        "down":                 "�U��",
	"out":				"�~��",
        "enter":                "�̭�",
        "gate":                 "����",
]);

void create()
{
        set("short", "�ӥj���");
        set("long", "
�o�̷̨ӱq�ӥj�ɥN�Ѥj���]�p�X�Ӫ��Ův��q���K�Z��--�ӥj���������
���O�ѩ�Ův�ӹL�j�N�A����������]�p�Ͽ�d�b�@�ɤW�A��ӳQ�a�W���H
�̵o�{�A�K�}�l�F�L�̪���ŮɥN�A����W�K���@�i"HIR"������U(book)"HIW"�A����
�٦��\\�h"HIR"����(window)"HIW"�i�H���~��

������O�G �U��(exit)

");
        set("objects",([
            __DIR__"../npc/lady":1,
	]));
	set("heal", 10); // �ϥΦ��ƭ���
set("item_desc", ([ 
  "book":"
������U�W�g�ۡG

�w��f���Ův���ӥj����, �o�O�̷s�����ӥj����
�z�i�H�ާ@����k�p�U :

raise   �ɰ_����
descend ��������
move    ���ʭ���
laser   �o�ʹp�g��
exit    �U����

�t�~, ���~����ܬ�, �j�a�i�H�ݬ�

"]));
        set("no_kill", 1);
        set("no_cast", 1);
	set("no_fight", 1);
	set("no_exert", 1);
        setup();
}

void init()
{
	if( !previous_object() || !userp(previous_object()) ) return;
	welcome(previous_object());
        add_action("do_exit", "exit");
        add_action("do_raise", "raise");
        add_action("do_descend", "descend");
        add_action("do_move", "move");
        add_action("do_laser", "laser");
        add_action("do_look", "look");
}

void welcome(object ob)
{
	if( objectp(ob->query("boat")) )
		write(HIY"\n����s�����G�P�±z�f��������C\n\n"NOR);
	else {
		write(HIY"\n����s�����G���O�q���T�~�|�f����������ȥ����ߨ�U��C\n\n"NOR);
		write(HIB"�A�Q����q�U���ƥX�ޱƩ�X�ӡC\n\n"NOR);
		ob->move(ob->query("startroom"));
		ob->delete("boat");
	}
	return;
}

int do_exit(string what)
{
	object me = this_player();
	object boat = me->query("boat");
	if( !objectp(this_player()->query("boat")) )
        return notify_fail("�A�ëD���`�n���A�ҥH�Х�recall��quit��suicide���}�C\n");
if(boat->query_temp("fly")==1)
        return notify_fail("����{�b���B�b�b�Ť��A�A�@�X�h�u�������@��!!\n");

        write(HIB"�A���}��������~��\n"NOR);
        tell_room(environment(this_player()),""+this_player()->query("name")+"�V�j�a�����⻡�D�GBYE!BYE!�ڨ��o ! �M��N���~��~~\n",({this_player()}));
        this_player()->move(environment(boat));
        tell_room(environment(this_player()),""+this_player()->query("name")+"��M�q�Ѧӭ����U�ӡA�t�I����A!!\n",({this_player()}));
        this_player()->delete("boat");
return 1;
}

int do_raise(string what)
{
	object me, boat;
	me = this_player();
	boat = me->query("boat");
	if( !objectp(me->query("boat")) )
        return notify_fail("�A�ëD���`�n���A�ҥH�L�k�r�p�ӥj����C\n");
if(boat->query_temp("fly")==1) {
        write("����w�g�ɦb�Ť��F�C\n");
        return 1;
        }
if(this_object()->query("heal")<1) {
        write("����w�Y���l�a...�L�k�A���_���C\n");
        return 1;
        }

        write(HIB"�A�e�Ԥӥj��������......����v�����W�ɰ_....\n"NOR);
        tell_room(environment(boat),HIY"�ӥj������������F�_��....�}�l�B�������.....�v���B���Ѫ�!!\n"NOR,({this_player()}));
        tell_room(environment(this_player()),"�A�Pı����̰ʤF�@�U....�}�l���W�ɰ_!!\n",({this_player()}));
        boat->set_temp("fly",1);
environment(this_player())->set("long","
�o�̷̨ӱq�ӥj�ɥN�Ѥj���]�p�X�Ӫ��Ův��q���K�Z��--�ӥj���������
���O�ѩ�Ův�ӹL�j�N�A����������]�p�Ͽ�d�b�@�ɤW�A��ӳQ�a�W���H
�̵o�{�A�K�}�l�F�L�̪���ŮɥN�A����W�K���@�i"HIR"������U(book)"HIW"�A����
�٦��\\�h"HIR"����(window)"HIW"�i�H���~��

����B�त�A����U��

"); 
return 1;
}


int do_descend(string what)
{
	object me, boat;
	me = this_player();
	boat = me->query("boat");
	if( !objectp(me->query("boat")) )
        return notify_fail("�A�ëD���`�n���A�ҥH�L�k�r�p�ӥj����C\n");
if(!boat->query_temp("fly"))
        return notify_fail("����w�g������a���W�F�C\n");

        write(HIB"�A����ӥj��������......����v�����U������a���W....\n"NOR);
        tell_room(environment(boat),HIY"�ӥj����w�w��������a���W....�������v�����}....\n"NOR,({this_player()}));
        tell_room(environment(this_player()),"�A�Pı����̰ʤF�@�U....�}�l�U��!!\n",({this_player()}));
     boat->delete_temp("fly");
environment(this_player())->set("long","
�o�̷̨ӱq�ӥj�ɥN�Ѥj���]�p�X�Ӫ��Ův��q���K�Z��--�ӥj���������
���O�ѩ�Ův�ӹL�j�N�A����������]�p�Ͽ�d�b�@�ɤW�A��ӳQ�a�W���H
�̵o�{�A�K�}�l�F�L�̪���ŮɥN�A����W�K���@�i"HIR"������U(book)"HIW"�A����
�٦��\\�h"HIR"����(window)"HIW"�i�H���~��

������O�G �U��(exit)

"); 
return 1;
}
int do_move(string what)
{
mapping exit;
string dir;
	object boat, env, me;
string str, *dirs,title,bon;

	me = this_player();
	boat = me->query("boat");
	env = environment(boat);

	if( !objectp(me->query("boat")) )
        return notify_fail("�A�ëD���`�n���A�ҥH�L�k�r�p�ӥj����C\n");
if(boat->query_temp("fly")!=1)
        return notify_fail("�n�}�ʭ���o���⭸��ɤW�Ť�...���D�A�n���L�b�a�W�}!?\n");
if(!what)
        return notify_fail("�A�Q�⭸��}�����Ӥ�V�H\n");
if(!mapp(exit = env->query("exits")) || undefinedp(exit[what])) {
        this_object()->add("heal",-1);
        tell_room(environment(this_player()),HIR"��M����n�̪��Q���@�P~~~�n�����ˤF��� @@\n"NOR,({this_player()}));
        write(HIR"�A�⭸��}�h������F!!\n"NOR);
if(this_object()->query("heal") < 1) {
        tell_room(environment(this_player()),HIR"����s���G�ѩ�r�p���޳N�L�t...������Ӻ�止��...\n"NOR,({this_player()}));
        write(HIR"����ש�Q�A���a�P....��止����a���W\n"NOR);
tell_room(environment(boat),HIW"�����M�@�Y�v�U��....�t�I�����A!!\n"NOR,({boat}));
        boat->delete_temp("fly");
environment(this_player())->set("long","
�o�̷̨ӱq�ӥj�ɥN�Ѥj���]�p�X�Ӫ��Ův��q���K�Z��--�ӥj���������
���O�ѩ�Ův�ӹL�j�N�A����������]�p�Ͽ�d�b�@�ɤW�A��ӳQ�a�W���H
�̵o�{�A�K�}�l�F�L�̪���ŮɥN�A����W�K���@�i"HIR"������U(book)"HIW"�A����
�٦��\\�h"HIR"����(window)"HIW"�i�H���~��

������O�G �U��(exit)

"); 
}
return 1;
}

        if( !undefinedp(default_dirs[what]) )
                dir = default_dirs[what];
        else
                dir = what;

        tell_room(environment(boat),HIY"�ӥj��������F���F�����o��.....�w�w����"+dir+"�}�F�L�h\n"NOR,({this_player()}));
        boat->move(exit[what]);
        tell_room(environment(boat),HIY"�ӥj�����F���F�����}�F�L��\n"NOR,({this_player()}));
write(HIB"�A�N���"+dir+"�}�L�h!!�A�Ө�F"+environment(boat)->query("short")+"\n"NOR);
        return 1;
}

int do_look(string what)
{
	object me, boat, where;
	me = this_player();
	if( !objectp(this_player()->query("boat")) )
        return notify_fail("�A�ëD���`�n���A�u!!\n");
if(what == "window") {
		boat = me->query("boat");
		where = environment(boat);
write(HIW"�A���Y���X���~��....�o�̬ݰ_�ӹ��O....\n\n"NOR);
        "/cmds/std/look"->look_room(this_player(), where);              
return 1;
}}

int do_laser(string what)
{
	object me, boat, ob;
	me = this_player();
	boat = me->query("boat");
	if( !objectp(me->query("boat")) )
        return notify_fail("�A�ëD���`�n���A�ҥH�L�k�ϥιp�g���C\n");
if(this_player()->query("level") < 20)
        return notify_fail("�o�O�Y�M�I�P�R�Z��...LV20�H�W���H�~���!!\n");
if(!what)
        return notify_fail("�A�Q�F�֡H\n");

        if( !(ob = present(what, environment(boat))))
                return notify_fail("�~���S��"+what+"�o�ӤH�C\n");
if(ob==boat)
        return notify_fail("�o��Q���O�ܡH\n");

        write(HIB"�A�N�N�����D�G�u��...�h���a�I�v���U�p�g���o�g���s........\n���������F�X�@�D����p�g������"+ob->query("name")+""HIB"���ŤF!!\n\n"NOR);
        tell_room(environment(this_player()),HIR"�A�Pı����~���o�X���j���T�n....�@�Ӫ�ı�i�D�A...�S���F�@�ӤH�F!!\n"NOR,({this_player()}));
     ob->receive_damage("hp",20000);
        tell_room(environment(ob),HIW"��M�@�D��������q����W�g�X�A�@�����K��"+ob->query("name")+"���ŤF!!\n"NOR,({ob}));
        tell_object(ob,HIW"\n��M����o�X���j�����u...����A�C���}������....�A�w�g���򳣤����D�F..."+NOR+"\n");

return 1;
}

