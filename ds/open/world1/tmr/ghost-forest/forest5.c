// Room: /tmr/garea/forest5.c

inherit ROOM;

void create()
{
	set("short", "幽徑");
	set("long", @LONG
你正在森林中的一條小徑，在你右方有棵十分高大、蒼老的神木，看
來少說也有數百年的樹齡，傲然挺立，隱然有睥視群木的氣概。除此之外
，卻是了無聲響，整條小徑靜得死寂，你耳朵聽到的聲音，只有你的呼吸
聲，令人不由地毛骨聳然。
LONG
	);
	set("no_clean_up", 0);
	set("item_desc",([
	"神木":"離你頭上方數尺處，有根突出的粗樹枝，似乎可上去(jump)看看。\n",
	]) );

	set("exits", ([ /* sizeof() == 2 */
	  "southwest" : __DIR__"forest3",
	  "northwest" : __DIR__"forest7",
	]));
	set("outdoors","forest");
      set("objects",([
         __DIR__"npc/obj/firewood": random(5),
      ]) );
	setup();
}
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me;
	me=this_player();

	if (!arg || arg !="粗樹枝" ) return 0;
	message_vision("$N發一聲喝，奮力跳上神木上的一根粗樹枝。\n",me);
	me->move(__DIR__"tree_up");
	tell_room(environment(me),me->query("name")+"跳了上來。\n",me);
	return 1;
}
