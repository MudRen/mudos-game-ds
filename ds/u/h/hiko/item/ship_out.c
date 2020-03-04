#include <ansi.h>
inherit NPC;
void create()
{
        set_name(""HIY"[巫師級]"HIW"太古飛船"NOR ,({ "ancient boat","boat","b","a"}) );
        set("chat_chance", 15);
        set("no_kill", 1);
        set("kill_msg", "飛船材質是木材和石塊...你以為你打的動嗎!!\n");
        set("combat_exp",5);
        set("race","野獸");
        set("unit", "艘");
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
write("一艘巨大的飛船，你可以登上(board)去瞧瞧\n");
return 1;
}
}

int do_board(string what)
{
object boat;
boat = this_object();

if(this_object()->query_temp("fly"))
        return notify_fail("飛船還沒降落，你怎麼上去？\n");
if(id(what)) {
write(HIB"太古飛船投出一張網子把你包起來然後猛地往上拉進去\n"NOR);
	this_player()->set("boat", this_object());
tell_room(environment(this_player()),"一張網子從太古飛船拋下來把"+this_player()->query("name")+"拉了上去!!\n",({this_player()}));
this_player()->move(this_object()->query("room"));
tell_room(environment(this_player()),"飛船的撒網機開始轉動....突然間"+this_player()->query("name")+"被拉了進來!!\n",({this_player()}));
} else write("你想要登上什麼？\n");
return 1;
}

