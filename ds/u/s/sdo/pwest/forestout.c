#include <ansi2.h>
inherit ROOM;

int do_exp(object me);

void create()
{
	set("short", "迷霧森林出口");
	set("long", @LONG
這裡就是迷霧森林的出口，也就是妖精國度的邊境。看看四周景
色，只能說讓人非常的賞心悅目。和煦的微風吹來，總是能適時的驅
散熱氣，讓人旅途的勞累在霎時間都消失的無影無蹤。前方是一大片
遼闊的草原。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");

	setup();
}
void init()
{
	call_out("do_exp",1,0);
}
int do_exp(object me)
{
	object book;
	int j,exp;
	string *msg;
	me=this_player();
	book=present("adventure notebook",me);
	
	if(!me) return 0;
	if(!book) return 0;
	if(book->query("quests/fogforest")!=1)
	{
		book->add_quests_note("fogforest",
		"旅途到達這裡，也差不多結束了；迷霧森林的秘密也不再是秘密了。[任務結束]\n");
		
		book->set_quests("fogforest",1);
		msg=book->query_quest_note("fogforest");
                j=sizeof(msg);
                exp=10000*j + random(10000);
                        
                tell_object(
                HIW"恭喜你完成了這個任務！\n\n"NOR
                HIW"你得到了%d點經驗值，得到了%d點聲望！\n\n"NOR,exp,j);
			
		this_player()->add("exp",exp);
		this_player()->add("popularity",j);
        	this_player()->save();
        	return 1;
        }
        return 1;
}