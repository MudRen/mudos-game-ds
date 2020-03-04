inherit ROOM;
void create()
{
	set("short", "��W");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_18_1",
	]));
	set("outdoors","land");
	set("objects",([
		__DIR__"../npc/beast_luckybirda_1":1,
	]));
        setup();
	set("map_long",1);     //show map as long

}

void bird_return()
{
	object bird;
	if(bird = present("bird",this_object())) return;
	if(!bird=new_ob(__DIR__"../npc/beast_luckybirda_1")) return;
	bird->move(this_object());
	tell_room(this_object(),bird->name()+"�w�w�����F�^�ӡC\n");
	remove_call_out("bird_return");
	return;
}

void bird_fly()
{
	call_out("bird_return",90);
}