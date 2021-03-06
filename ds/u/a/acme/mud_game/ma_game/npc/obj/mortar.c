#include <ansi.h>

inherit ITEM;

int do_beat();

void create()
{
        set_name("藥臼", ({ "drug mortar","mortar" }) );
        set("long",@LONG
可將藥材(drug)放入藥臼(drug mortar)，並配合藥杵(drug pestle)搗藥(beat)。
LONG
);
        set_max_capacity(30);
        set_max_encumbrance(3000);
	set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value",1000);
        }
        setup();
}

int accept_object(object me, object ob) { return 1; }

void init()
{
	add_action("do_beat","beat");
}

int do_beat()
{
	int i,attr=0,score=0,check=0;
	object ob=this_object(),me=this_player(),*inv,pill;

	inv=all_inventory(me);
	i=sizeof(inv);
	while( i-- )
		if( inv[i]->query("id") == "drug pestle" ) check=1;
	if( !check )
		return notify_fail("你身上必需要有一個藥杵，方能搗藥！\n");
	
	inv=all_inventory(ob);
	i=sizeof(inv);
	if( !i ) 
	{
		message_vision(HIW"$N拿起藥杵往藥臼搗了數下，但只發出「鏘∼鏗∼」之聲。\n"NOR,me);
		return 1;
	}
	while( i-- )
	{
		if( !inv[i]->query("ma_game") )
			return notify_fail("你的藥臼裡的藥材有問題！\n");
		if( !attr )
			attr=inv[i]->query("attr1");

		if( attr-inv[i]->query("attr1") == 1
		|| attr-inv[i]->query("attr1") == -1
		|| attr-inv[i]->query("attr1") == 4
		|| attr-inv[i]->query("attr1") == -4 )
			score+= 150;
		else
			score+= 30+random(10);

		if( inv[i]->query("attr2")+inv[i]->query("attr3") == 10 )
			score+=150;
		else
			score+= (inv[i]->query("attr2")+inv[i]->query("attr3"))*5;
		if( (inv[i]->query("attr2")+inv[i]->query("attr3"))%2 == 0 )
			score+=50+random(10);
		else score+=10+random(10);
		attr=inv[i]->query("attr1");
	}

        if( score > 10000 && random(101) > 90 )
        {
                score+=3000+random(5000);
                write("你心領神會，出神入化的又搗了幾下。\n");
        }
	inv=all_inventory(ob);
	i=sizeof(inv);
	while( i-- ) destruct(inv[i]);

	message_vision(HIW"$N拿起藥杵往藥臼搗了數下，製成了一顆長生不老丹！\n"NOR,me);
	pill=new(__DIR__"pill.c");
	pill->set("fly_speed",score);
	pill->move(me);
	return 1;
}
