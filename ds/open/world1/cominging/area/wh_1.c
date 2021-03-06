#define NOW_ROOM "/open/world2/lichi_town_1/map_5_6.c"
#include <path.h>
#include <ansi.h>
inherit ROOM;

static int *crystal = ({ 1,1,1 }); // 設定水晶存在嗎 (紫色,白色,紅色) 0 為沒有 1 為存在可供水 2 為只存在但無法使用
static string *crystal_kind = ({ "purple", "white", "red" }); // 設定水晶的種類 (get用)
static string *crystal_color_kind = ({ "[0;35m紫色[0m", "[1;37m白色[0m", "[1;31m紅色[0m" });
string *locate = ({ "map_1_4.c", "map_1_5.c", "map_2_5.c", "map_3_5.c", "map_4_5.c", "map_5_3.c", "map_5_4.c", "map_5_5.c", "map_6_3.c" }); // 河流流道
string *crystal_file = ({ COMINGING_PAST + "area/obj/purple_crystal.c", COMINGING_PAST + "area/obj/white_crystal.c", COMINGING_PAST + "area/obj/red_crystal.c" }); // 水晶

string query_crystal();
void random_moving(string file);
void show_message(object me, object ob);
void control(int flag);

void create()
{
/*
這裡就是滄水水洞了, 充滿著溼氣, 幾乎空氣中所存的, 都盡是水氣,
這邊有個奇異的柱子, 是一個[0;35m紫色[0m的水晶, 水晶發出了一陣陣的光芒,
接著便湧出許多水出來, 也許這個就是全滄縣裡所供應的地下水的來源
共有 3 種不同顏色的水晶, 分別是[0;35m紫色[0m、[1;37m白色[0m、[1;31m紅色[0m的水晶(crystal)。
*/
	set("short", "[1;36m滄水水洞[0m");
	set("long", @LONG

LONG	);
	set("exits", ([
  "out" : __DIR__"map_1_2.c",
]));
	for(int x=0;x<sizeof(crystal);x++)
		if( crystal[x] == 1 )
		{
			set("item_desc/crystal", "柱子上有著幾種水晶有" + query_crystal() + "，假如你想將之拿起, 可以試著用(get)。\n");
			break;
		}
	setup();
}

string query_long(int raw)
{
	int q = 0;
	string out = @LONG

這裡就是滄水水洞了, 這就是全滄縣裡所供應的水源的源頭, 充滿著溼
氣, 幾乎空氣中所存的, 都盡是水氣, 這邊有三個石柱, 石柱上, 有著
LONG;

	if( query_crystal() == "" )
		out += "一個個有桌子般大小的洞，上面都是空的，空蕩蕩的一片。\n\n";
	else out += query_crystal() + "\n\n";
	return out;
}

string query_crystal()
{
	int q;
	string out = "";
	if( crystal[0] == 1 )
		{ out += "[0;35m紫色[0m的水晶"; q = 1; }
	if( crystal[1] == 1 )
		{ out += ((q==1) ? "、" : "") + "[1;37m白色[0m的水晶"; q = 2; }
	if( crystal[2] == 1 )
		{ out += ((q==2 || q==1) ? "、" : "") + "[1;31m紅色[0m的水晶"; q=3; }
		// 判斷是否 q == 1 或 2 再加上後面補充, 加 q=3 是怕前面沒有 query 到.
	return out;
}

void init()
{
	add_action("do_get", "get");
	add_action("do_lay", "lay");
	add_action("do_cast", "cast");
}

int do_get(string arg)
{
	object me = this_player();
	string temp;
	int flag;

	if( !arg || sscanf(arg, "%s crystal", temp) != 1 )
	{
		write("如果你想要拿取這裡的水晶, 請用 get <顏色> crystal。\n");
		return 0;
	}

	flag = member_array(temp, crystal_kind);
	if( flag == -1 || crystal[flag] == 0 )
		return notify_fail("這裡沒有"+to_chinese(temp)+"這種顏色的水晶！("+flag+")\n");

	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成﹗\n");

	if( !me->query_temp("invis") )
	{
		message_vision("$N試著將" + crystal_color_kind[flag] + "的水晶拿起…\n", me);
		message_vision("  不料, 因為這些水晶過於龐大, 突然$N一個不小心, 從$N的手中滑落, 掉到水裡, 被水給沖走了…\n", me);
	}
	else
	{
		write("你試著將" + crystal_color_kind[flag] + "的水晶拿起…\n");
		write("  不料, 因為這些水晶過於龐大, 突然$N一個不小心, 從$N的手中滑落, 掉到水裡, 被水給沖走了…\n");
		message_vision(HIC"突然間, " + crystal_color_kind[flag] + "的水晶掉入了水裡…！\n"NOR, me);
	}

	call_out("random_moving", 10, flag);
	crystal[flag] = 0; // 使水晶不存在 = 0;
	control(1);
	return 1;
}

int do_lay(string arg)
{
	object me = this_player(), ob;
	string temp;
	int x, flag;

	if( !arg || sscanf(arg, "%s on stone", temp) != 1 ) return notify_fail("你想要放什麼東西？(lay <水晶> on stone\n");
	if( !(ob=present(temp, me)) || living(ob) ) ob = present(temp, environment(me));
	if( !ob || living(ob) ) return notify_fail("這裡沒有這樣東西。\n");

	for(x=0;x<sizeof(crystal);x++)
		if( crystal[x] == 1 ) flag = 1;

	if( flag == 1 ) return notify_fail("有一股力量抑制著你放這東西上去，可能是上面還有沒動的東西！\n");
	if( ob->id("crystal") )
	{
		switch(ob->query("id"))
		{
			case "purple crystal":
				crystal[0] = 2;
				break;
			case "white crystal":
				crystal[1] = 2;
				break;
			case "red crystal":
				crystal[2] = 2;
				break;
		}
		show_message(me, ob);
		destruct(ob);
	}
	else return notify_fail("你發覺將" + ob->name(1) + "放上去沒有什麼事發生，於是又拿了下來...\n");
	return 1;
}

int do_cast(string arg)
{
	object me = this_player();
	int x, flag;

	if( me->is_ghost()) return notify_fail(" 你現在還是鬼魂吧\n");
	if( me->is_busy() || me->is_block() )
		return notify_fail("( 你上一個動作還沒有完成﹐不能念咒文。)\n");
	if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你現在正在忙沒空施法。\n");
	if( environment(me)->query("no_magic") || environment(me)->query("no_cast") )
		return notify_fail("這裡不准念咒文。\n");
	if( !arg || arg != "god-fire on the crystals" ) return 0;

	if( !me->query_spell("god-fire") )
		return notify_fail("你還沒學過此咒文。(god-fire)\n");

	for(x=0;x<sizeof(crystal);x++)
		if( crystal[x] == 0 || crystal[x] == 1 ) flag = 1;

	if( (int)me->query("mp") < 25 ) 
		return notify_fail("你的法力不夠。\n");

	if( flag == 1 ) return notify_fail("錯誤！可能是因為石柱上還有空位沒放或者是原本的水晶未取下！\n");

	me->start_busy(2); //施法動作時間
	me->receive_damage("mp", 20); //施法扣MP

	message_vision("$N雙手合十，喃喃自語道："HIW"「"HIG"天地合德，日月合明，四時合序，鬼神合火以滅敵。"HIW"」\n"NOR,me);

	message_vision(RED"\n\n 只見一道道"HIR"火球"NOR RED"飛向水晶而去……　結果水晶開始融化，水源又恢復了...\n"NOR, me);

	for(x=0;x<sizeof(crystal);x++)
		crystal[x] = 1;

	control(2);
	return 1;
}

void show_message(object me, object ob)
{
	int i, t = 0;
	string msg, msg1;

	if( !me || !ob ) return;
	if( crystal[0] == 0 )
		{ msg1 += crystal_color_kind[0]; t=1; }
	if( crystal[1] == 0 )
		{ msg1 += ((t==1) ? "、" : "") + crystal_color_kind[1]; t=2; }
	if( crystal[2] == 0 )
		{ msg1 += ((t==1 || t==2) ? "、" : "") + crystal_color_kind[2]; t=3; }
	if( msg1 ) msg = "，還差" + msg1 + "幾個水晶";
	if( t == 0 ) msg = "，只差施出"HIR"神武真火"NOR"來融水晶(cast god-fire on the crystals)";
	message_vision("$N將$n放在石柱上" + msg + "。\n", me, ob);
	return;
}

void control(int flag)
{
	object now_room = load_object(NOW_ROOM);
	int x, j = 0, uj = 0;
	for(x=0;x<sizeof(crystal);x++)
	{
		if( crystal[x] == 0 ) j++;
		if( crystal[x] == 1 ) uj++;
	}
	if( j == 3 && flag == 1)
	{
		message("world:world1:vision", HIY"突然，水源漸漸減少，森林中的一道水源突然斷了…！\n"NOR, users());
		// 接下來的是現代的變化
		tell_room(now_room, HIY"突然一陣扭曲，你覺得一陣天旋地轉，但是回過神之後並沒有發現什麼，是不是頭腦昏了？\n"NOR, ({ }));
		now_room->set_water(0);
		return;
	}
	if( uj = 3 && flag == 2)
	{
		message("world:world1:vision", HIY"山頭的水源又漸漸的恢復了…\n"NOR, users());
		// now's change
		tell_room(now_room, HIR"突然一陣扭曲，你覺得一陣天旋地轉，但是回過神之後並沒有發現什麼，是不是頭腦昏了？\n"NOR, ({ }));
		now_room->set_water(1);
		return;
	}
}

void random_moving(int flag)
{
	object crystal_move = new(crystal_file[flag]), room;
	if( !crystal_move )
	{
		CHANNEL_D->do_channel(this_object(), "sys", "error: /open/world1/cominging/area/wh_1.c error 傳入值");
		return;
	}
	room = load_object(locate[random(sizeof(locate))]);
	crystal_move->move(room);
	tell_room(room, HIG"從上游突然一個東西流了過來…\n"NOR, ({ }));
	return;
}

int *query_x()
{
	return crystal;
}
