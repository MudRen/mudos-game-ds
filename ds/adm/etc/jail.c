#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short","[1;35m�T����[0m");
set("long", @LONG
�o�̬O�P�ڶ����s���ʺ��C�|�Ө�o�����O--��MUD���u�W�w���H�C
��~~~�r~~~�r~~~~  �n�n�Ϭ٧a!!!
�@�ߪ�����j�����P�M�a!
LONG
       );
set("light",1);
set_temp("prision",1);
delete_temp("prision");
set("objects", ([ /* sizeof() == 2 */
]));
setup();
}
void init()
{
	if(wiz_level(this_player()) > wiz_level("(wiz)"))
	{
		tell_object(this_player(),"����Х�free <id>\n");
		add_action("do_free", "free");
		return;
	}
	this_player()->set_temp("out_of_power",1);
        add_action("no_quit", "quit");
        add_action("no_quit", "Q");
        add_action("no_kill", "kill");
        add_action("no_goto", "home");
        add_action("no_goto", "recall");
        add_action("no_quit", "fight");
        add_action("no_goto", "goto");
        add_action("no_rm",   "rm");
        add_action("no_dest", "dest");
        add_action("no_more", "more");
        add_action("no_cat",  "update");
        add_action("no_cat",  "cat");
        add_action("no_edit", "edit");
        add_action("no_tell", "clone");
        add_action("no_tell", "mkroom");
        add_action("no_tell", "shutdown");
        add_action("no_tell", "rest");
        add_action("no_tell", "connect");
        add_action("no_tell", "saveroom");
        add_action("no_tell", "localcmds");
        add_action("no_tell", "cp");
        add_action("no_tell", "tell");
        add_action("no_tell", "beep");
        add_action("no_tell", "chat");
        add_action("no_tell", "chat*");
        add_action("no_tell", "music");
        add_action("no_tell", "music*");
        add_action("no_tell", "rumor");
        add_action("no_tell", "wiz");
        add_action("no_tell", "wiz*");
        add_action("no_tell", "es");
        add_action("no_tell", "es*");
        add_action("no_tell", "gwiz");
        add_action("no_tell", "twiz");
        add_action("no_tell", "sys");
        add_action("no_tell", "ls");
        add_action("no_tell", "shout");
        add_action("no_call", "call");
        add_action("no_dest", "smash");
        add_action("do_fuck", "fuck");
        add_action("no_fly","fly");
        add_action("no_jump","jump");
        add_action("no_summon","summon");
        add_action("no_suicide", "suicide");
}

int no_suicide(string str)
{
     write(HIY"�Q���]���O����e����..�O�H��suicide�N�S�ƤF  :( \n"NOR);
        return 1;
}
int no_quit(string str)
{
     write(HIY"�Q��F..�ٷQ��..�O�H��quit�N�S�ƤF  :( \n"NOR);
        return 1;
}
int no_goto(string str)
{
     write(HIC"�z����!!�A�H�g���F�}�ǤF..�ٷQ�]????\n"NOR);
        return 1;
}
int no_kill(string str)
{
write("�o�̸T������{���ɤO�ƥ�o�͡C\n");
        return 1;
}
int no_more(string str)
{
     write(HIY"�Q��more ���ݳo���ɳ�...�����S��...\n"NOR);
        return 1;
}
int no_rm(string str)
{
        write("����?!�Q���F�N�����v�O���S�F, �ٷQrm!!\n");

       return 1;
}
int no_dest(string str)
{
        write("�O�Q�R���o��!!�i�D�A�o�̬O����R����!!\n");
        return 1;

}
int no_cat(string str)
{
        write("�ڬO�ߡ���p����p����p���\n");
        return 1;
}
int no_edit(string str)
{
    write(HIG"�A�Q��EDIT����o�̰�..�����S��!!!\n"NOR);
       return 1;
}
int no_call(string str)
{
       write("CALL!!�z �� �� B.B.CALL ��\n");
        return 1;
}
int do_fuck(string str)
{
        object ob;
        ob = this_player();
        ob->reincarnate();
ob->move("/u/s/sammy/pkroom");
        return 1;
}

int do_free(string str)
{
        object ob,who;
        ob = this_player();
        if(!who=present(str,this_object())) return notify_fail("�����?\n");
	message_vision("$N�N$n����F!\n",ob,who);
	who->move("/open/world2/anfernee/start/login");
        who->delete_temp("out_of_power");
        return 1;
}


int no_fly(string str)
{
        write("������~~~�A�O���ͤ]�����F~~~~~����~~:p\n");
        return 1;
}
int no_jump(string str)
{
        write("��!!!�A��??�A�n���h����???????\n");

return 1;
}
int no_summon(string str)
{
        write("�K�K....�Q��H�ӳ��A��???????�٬٧a!!!!!\n");
        return 1;
}
int no_tell(string str)
{
write("[1;33m�Q�@ԣ?���b�Y�c���F�ٷQ���ǰڡ���[0m");
write("\n");
return 1;
}
