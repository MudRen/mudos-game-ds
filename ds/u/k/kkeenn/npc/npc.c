#include <ansi.h>;

inherit NPC;

void create()
{
            set_name(HIM"李雅棻"NOR,({"efghijk","system"}) );
           set("age",15);
      set("title",HIB"【"HIC"龍騎士"HIW"之"RED"魂"HIB"】"NOR);
	set("gender", "女性");
         set("level",100);
         set("nick",HIC"奶粉"NOR);
	set("long",
"她是遊龍俠的同學之一, 因為某種特殊原因, 所以特別Clone出來^^ \n"
);
	set("chat_chance",5);
	set("chat_msg",({
                (:command("sing"):),
                HIM"奶粉棻"NOR"在"HIC"遊龍俠"NOR"附近晃來晃去..\n",
	}) );
set_skill("unarmed",100);
set_skill("dragonfist",100);
set_skill("sword",100);
set_skill("dragonsteps",100);
set_skill("dragonblade",100);
map_skill("unarmed","dragonfist");
map_skill("dodge","dragonsteps");
map_skill("blade","dragonblade");
set("inquiry",([
  "money" : "ㄚ...現在就要ㄇ??我盡量幫你啦。\n",
  "kkeenn" : "他ㄚ...是我的主人..聽說是一名龍騎士ㄡ。\n",
"龍騎士": "嗯...好像是傳說中的職業ㄝ..特徵是騎著一條龍^^",
"龍" : "ㄚ...這你問我就對了^^龍就在地下龍域停著麻",
]) );

	setup();
}

void init()
{
add_action("hest","hest");
}
int hest(string str)
{ 
object me,ccc;
me=this_player();
if(!objectp(ccc=present("item",me) ) )
return notify_fail(HIR"警告.無持遙控器者不得控制它。\n"NOR);
command(str);
  return 1; 
}

