//Room: /d/ruzhou/hongniang-zhaung.c
// by llm 99/06/12

#include <ansi.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "紅娘堂");
   set("long", @LONG
這里就是天下夫婦定約結緣的紅娘堂，只有在這里締結婚約或是解除
婚約才能得到世人的承認。這里是一個不大的門廳，但是經過一番修整之
后，顯得十分地氣派。廳堂正中挂著一塊雕著字的烏木匾牌(sign)。
LONG
        );
	set("exits", ([
		"west" : __DIR__"hong-zoulang",
		"east" : __DIR__"yinyuan-tang",
   ]) );

   set("item_desc", ([
   	"sign": (: look_sign :),
   ]) );

   set("objects", ([
   	__DIR__"npc/meipo" : 1,
      ]) );
   setup();
}

string look_sign(object me)
{
	return HIM"勸和不勸分\n"
   "求緣更求份\n"
   "紅線前生系\n"
   "姻結一世人\n"NOR;
}

int valid_leave(object me, string dir)
{
 	if (dir=="west"&& me->query_temp("pending/pro") )
      me->delete_temp("pending/pro");
      return ::valid_leave(me, dir);
}