// An example doll.c
// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
      set_name("繪理香娃娃",({"erika doll","doll","undead_item"}));
	set_weight(100);
          set("value",10000);
		set("unit","隻");
		set("long",@LONG
繪理香血型A型，身高160cm，繪理香名字由來是花的名字，杜鵑花
科的一種(Erica)。外表雖有如少女般的清純，但性格卻是粗枝大葉，
繪理香本人曾說自己的個性很男孩子氣。
LONG
		);
		set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n突然衝出擋住了這致命一擊!!\n\n"NOR);

setup();
}

