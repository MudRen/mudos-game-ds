#include <ansi.h>

inherit ITEM;

int do_beat();

void create()
{
        set_name("�Ħ�", ({ "drug mortar","mortar" }) );
        set("long",@LONG
�i�N�ħ�(drug)��J�Ħ�(drug mortar)�A�ðt�X�ĪS(drug pestle)�o��(beat)�C
LONG
);
        set_max_capacity(30);
        set_max_encumbrance(3000);
	set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
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
		return notify_fail("�A���W���ݭn���@���ĪS�A���o�ġI\n");
	
	inv=all_inventory(ob);
	i=sizeof(inv);
	if( !i ) 
	{
		message_vision(HIW"$N���_�ĪS���Ħݷo�F�ƤU�A���u�o�X�u�������v���n�C\n"NOR,me);
		return 1;
	}
	while( i-- )
	{
		if( !inv[i]->query("ma_game") )
			return notify_fail("�A���Ħݸ̪��ħ������D�I\n");
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

	inv=all_inventory(ob);
	i=sizeof(inv);
	while( i-- ) destruct(inv[i]);

	message_vision(HIW"$N���_�ĪS���Ħݷo�F�ƤU�A�s���F�@�����ͤ��Ѥ��I\n"NOR,me);
	pill=new(__DIR__"pill.c");
	pill->set("fly_speed",score);
	pill->move(me);
	return 1;
}
