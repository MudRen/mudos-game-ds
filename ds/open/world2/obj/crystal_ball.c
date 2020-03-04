inherit ITEM;
void create()
{
	set_name("水晶球",({ "crystal ball","ball" }) );
	set_weight(2500);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
一顆晶瑩的水晶球。
	==================
	唸咒	curse <id>
	==================
LONG);
	set("unit", "顆");
	set("material","ice");
	set("no_get",1);
	}
	set("value",5000);
	setup();
}

void init()
{
	object env,me;
	me=this_player();
	if(env=environment(this_object()))
	{
		add_action("do_curse","curse");
	}
}

string long()
{
	object env,who;
	string out="",tmp="";
	out = ::long();
	out += "你仔細的看了看水晶球..";
	if(!this_object()->query("player_id") || !who=find_player(this_object()->query("player_id")))
	{
		out +="\n  水晶球裡面一片濛濛的看不清楚。\n";
		return out;
	}
	
	env = environment(who);
	if(!env) out +="\n  水晶球裡面一片濛濛的看不清楚。\n";
	else 
	{
		out+="你隱約看到...\n\n";
		if(tmp=env->query_long(1)) out+=tmp;
		else out+=env->query("long");
	}
	return out;
}

int do_curse(string arg)
{
	object who,me;
	me=this_player();
	if(!arg) return notify_fail("你喃喃自語了一會兒..\n");
	if(me->query("mp")<20)  return notify_fail("你現在的精神不好，無法集中精神..\n");
	message_vision("$N對著水晶球唸著: 天靈靈..地靈靈.."+arg+"快現形..\n",me);
    who = find_player(arg);
    if(!who || wizardp(who) || !environment(who))
	{
		message_vision("水晶球並沒有什麼變化。\n",me);
		this_object()->delete("player_id");
		return 1;
		//return notify_fail("你喃喃自語了一會兒..\n");
	}
	else
	{
		me->receive_damage("mp",20);
		this_object()->set("player_id",arg);
		message_vision("水晶球突然閃了一下。\n",me);
		tell_object(who,"你突然有個奇異的感覺，似乎有對眼睛在看著你。\n");
		return 1;
	}
}
int query_autoload() { return 1; }
