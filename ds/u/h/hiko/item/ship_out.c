#include <ansi.h>
inherit NPC;
void create()
{
        set_name(""HIY"[�Ův��]"HIW"�ӥj����"NOR ,({ "ancient boat","boat","b","a"}) );
        set("chat_chance", 15);
        set("no_kill", 1);
        set("kill_msg", "�������O����M�۶�...�A�H���A�����ʶ�!!\n");
        set("combat_exp",5);
        set("race","���~");
        set("unit", "��");
        set("room", __DIR__"ship_in");
        set("flyboat",1);
        set("cantgo",1);
        setup();
}

void init()
{
        add_action("do_look", "look");
        add_action("do_board", "board");
}

int do_look(string what)
{
if(id(what)) {
write("�@�����j������A�A�i�H�n�W(board)�h�@�@\n");
return 1;
}
}

int do_board(string what)
{
object boat;
boat = this_object();

if(this_object()->query_temp("fly"))
        return notify_fail("�����٨S�����A�A���W�h�H\n");
if(id(what)) {
write(HIB"�ӥj�����X�@�i���l��A�]�_�ӵM��r�a���W�Զi�h\n"NOR);
	this_player()->set("boat", this_object());
tell_room(environment(this_player()),"�@�i���l�q�ӥj����ߤU�ӧ�"+this_player()->query("name")+"�ԤF�W�h!!\n",({this_player()}));
this_player()->move(this_object()->query("room"));
tell_room(environment(this_player()),"����������}�l���....��M��"+this_player()->query("name")+"�Q�ԤF�i��!!\n",({this_player()}));
} else write("�A�Q�n�n�W����H\n");
return 1;
}

